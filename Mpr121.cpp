/***************************************************
  This is a library for the MPR121 I2C 12-chan Capacitive Sensor
  Designed specifically to work with the MPR121 sensor from Adafruit
  ----> https://www.adafruit.com/products/1982
  These sensors use I2C to communicate, 2+ pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

//
// Adapted for OrangePi Zero by Mark Fox on 5/22/17.
//

#include <vector>
#include "Mpr121.h"
#include "gpio_lib.h"

using namespace std;

Mpr121::Mpr121(shared_ptr<I2c> i2c_, uint8_t i2caddr_, unsigned int interrupt_, unsigned int multiplier_) :
    i2c(i2c_), i2caddr(i2caddr_), interrupt(interrupt_), multiplier(multiplier_)
{
    sunxi_gpio_set_cfgpin(interrupt, INPUT);
}

bool Mpr121::begin() {

//     soft reset
    writeRegister(MPR121_SOFTRESET, 0x63);
    writeRegister(MPR121_ECR, 0x0);

    uint8_t c = readRegister8(MPR121_CONFIG2);

    if (c != 0x24) return false;

    setThresholds(12, 6);  // TODO get rid of these magic constants... what's the right init value?
    writeRegister(MPR121_MHDR, 0x01);
    writeRegister(MPR121_NHDR, 0x01);
    writeRegister(MPR121_NCLR, 0x0E);
    writeRegister(MPR121_FDLR, 0x00);
    writeRegister(MPR121_MHDF, 0x01);
    writeRegister(MPR121_NHDF, 0x05);
    writeRegister(MPR121_NCLF, 0x01);
    writeRegister(MPR121_FDLF, 0x00);
    writeRegister(MPR121_NHDT, 0x00);
    writeRegister(MPR121_NCLT, 0x00);
    writeRegister(MPR121_FDLT, 0x00);
    writeRegister(MPR121_DEBOUNCE, 0);
    writeRegister(MPR121_CONFIG1, 0x10); // default, 16uA charge current
    writeRegister(MPR121_CONFIG2, 0x20); // 0.5uS encoding, 1ms period
//  writeRegister(MPR121_AUTOCONFIG0, 0x8F);
//  writeRegister(MPR121_UPLIMIT, 150);
//  writeRegister(MPR121_TARGETLIMIT, 100); // should be ~400 (100 shifted)
//  writeRegister(MPR121_LOWLIMIT, 50);
    // enable all electrodes
    writeRegister(MPR121_ECR, 0x8F);  // start with first 5 bits of baseline tracking
    return true;
}

uint8_t Mpr121::readRegister8(uint8_t reg)
{
    return i2c->receive8(i2caddr, reg);
}

uint16_t Mpr121::readRegister16(uint8_t reg)
{
    return i2c->receive16(i2caddr, reg);
}

void Mpr121::writeRegister(uint8_t reg, uint8_t value)
{
    i2c->send(i2caddr, reg, &value, 1);
}

uint16_t Mpr121::touched(void)
{
    uint16_t t = readRegister16(MPR121_TOUCHSTATUS_L);
    // we only get 12 lower bits from the sensor
    return t & 0x0FFF;
}

void Mpr121::setThresholds(uint8_t touch, uint8_t release) {
    for (uint8_t i=0; i<12; i++) {
        writeRegister(MPR121_TOUCHTH_0 + 2*i, touch);
        writeRegister(MPR121_RELEASETH_0 + 2*i, release);
    }
}

uint16_t  Mpr121::filteredData(uint8_t t) {
    if (t > 12) return 0;
    return readRegister16(MPR121_FILTDATA_0L + t*2);
}

uint16_t  Mpr121::baselineData(uint8_t t) {
    if (t > 12) return 0;
    uint16_t bl = readRegister8(MPR121_BASELINE_0 + t);
    return (bl << 2);
}

bool Mpr121::triggered() {
    sunxi_gpio_set_cfgpin(interrupt, INPUT);
    int trigger = sunxi_gpio_input(interrupt);
    // interrupt is high unless it's touched and needs to be read, then it's low
    bool result = trigger == 0;
    return result;
}

vector<pair<unsigned int, bool>> Mpr121::changed() {
    auto current = bitset<12> (touched());
    // light #, on?
    vector<pair<unsigned int, bool>> changedLights;
    if (current != previous) {
        for (uint16_t i=0; i<12; i++) {
            if (current.test(i) != previous.test(i)) {
                // add 12 * multiplier to index the lights properly
                changedLights.emplace_back(i + 12 * multiplier, current.test(i));
            }
        }
    }
    previous = current;
    return changedLights;
}