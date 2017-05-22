//
// Created by Mark Fox on 5/21/17.
//

#include "i2c.h"
#include <cstdio>
#include "gpio_lib.h"



i2c::i2c(unsigned int scl, unsigned int sda) :
        SCL(scl), SDA(sda)
{
}


bool i2c::init(void)
{
    if (sunxi_gpio_init() < 0) {
        printf("ERROR: sunxi_gpio_init() failed");
        return false;
    }

    sunxi_gpio_set_cfgpin(SCL, OUTPUT);
    sunxi_gpio_set_cfgpin(SDA, OUTPUT);

//    Wire.begin();
//
//    _i2caddr = i2caddr;
//
//    // soft reset
//    writeRegister(MPR121_SOFTRESET, 0x63);
//    delay();
//
//    writeRegister(MPR121_ECR, 0x0);
//
//    uint8_t c = readRegister8(MPR121_CONFIG2);
//
//    if (c != 0x24) return false;

    printf("init finished\n");

    return true;
}

void i2c::delay(void)
{
    //specs call for a 4us delay minimum.
    //boost::this_thread::sleep_for(boost::chrono::nanoseconds(4000));
    for (int delay = CLK_WIDTH; delay; delay--);

}

void i2c::startBit(void)
{
    // To start a transaction, SDA is pulled low while SCL remains high
    // the next step is to pull SCL low.
    sunxi_gpio_output(SCL, HIGH);
    delay();
    sunxi_gpio_set_cfgpin(SDA, OUTPUT);
    sunxi_gpio_output(SDA, HIGH);
    delay();
    sunxi_gpio_output(SDA, LOW);
    delay();
    sunxi_gpio_output(SCL, LOW);
    delay();
}

void i2c::stopBit(void)
{
    // Releasing SDA to float high again would be a stop marker
    // signaling the end of a bus transaction.
    sunxi_gpio_set_cfgpin(SDA, OUTPUT);

    sunxi_gpio_output(SDA, LOW);
    delay();
    sunxi_gpio_output(SCL, HIGH);
    delay();
    sunxi_gpio_output(SDA, HIGH);
    delay();
}

int i2c::tx(uint8_t *buf, size_t len)
{

    sunxi_gpio_set_cfgpin(SDA, OUTPUT);

    int b;
    unsigned char bit;
    for (size_t i = 0; i < len; i++) {
        bit = 0x80;
        for (b = 0; b < 8; b++) {
            //printf("%d & %d = %d\n", buf[i], bit, buf[i] & bit);

            sunxi_gpio_output(SDA, (buf[i] & bit));
            delay();

            sunxi_gpio_output(SCL, HIGH);
            delay();

            bit >>= 1;
            sunxi_gpio_output(SCL, LOW);
        }
    }
    sunxi_gpio_output(SDA, HIGH);
    sunxi_gpio_output(SCL, HIGH);
    delay();

    // Read SDA for the (N)ACK
    sunxi_gpio_set_cfgpin(SDA, INPUT);
    int ack = sunxi_gpio_input(SDA);
    sunxi_gpio_output(SCL, LOW);
    return ack;
}

void i2c::checkError(int func)
{
    if (func) printf("Error");
}

int i2c::txWStartStop(uint8_t addr, uint8_t reg, uint8_t val)
{

    // To start a transaction, SDA is pulled low while SCL remains high
    // the next step is to pull SCL low.
    // Start START
    checkError(sunxi_gpio_set_cfgpin(SCL, OUTPUT));
    checkError(sunxi_gpio_set_cfgpin(SDA, OUTPUT));

    checkError(sunxi_gpio_output(SCL, HIGH));
    delay();
    checkError(sunxi_gpio_output(SDA, HIGH));
    delay();
    checkError(sunxi_gpio_output(SDA, LOW));
    delay();
    checkError(sunxi_gpio_output(SCL, LOW));
    delay();
    // End START

    // Transmit bits
    for(uint8_t x=8; x; x--) {
        if(addr & 0x80) checkError(sunxi_gpio_output(SDA, 1));
        else checkError(sunxi_gpio_output(SDA, 0));
        checkError(sunxi_gpio_output(SCL, 1));
        addr <<= 1;
        checkError(sunxi_gpio_output(SCL, 0));
    }

    // Transmit bits
    for(uint8_t x=8; x; x--) {
        if(reg & 0x80) checkError(sunxi_gpio_output(SDA, 1));
        else checkError(sunxi_gpio_output(SDA, 0));
        checkError(sunxi_gpio_output(SCL, 1));
        reg <<= 1;
        checkError(sunxi_gpio_output(SCL, 0));
    }

    // Transmit bits
    for(uint8_t x=8; x; x--) {
        if(val & 0x80) checkError(sunxi_gpio_output(SDA, 1));
        else checkError(sunxi_gpio_output(SDA, 0));
        checkError(sunxi_gpio_output(SCL, 1));
        val <<= 1;
        checkError(sunxi_gpio_output(SCL, 0));
    }

    checkError(sunxi_gpio_output(SDA, HIGH));
    checkError(sunxi_gpio_output(SCL, HIGH));
    delay();

    // Read SDA for the (N)ACK
    checkError(sunxi_gpio_set_cfgpin(SDA, INPUT));
    int ack = sunxi_gpio_input(SDA);
    checkError(sunxi_gpio_output(SCL, LOW));

    // Start STOP
    // Releasing SDA to float high again would be a stop marker
    // signaling the end of a bus transaction.
    checkError(sunxi_gpio_set_cfgpin(SDA, OUTPUT));

    checkError(sunxi_gpio_output(SDA, LOW));
    delay();
    checkError(sunxi_gpio_output(SCL, HIGH));
    delay();
    checkError(sunxi_gpio_output(SDA, HIGH));
    delay();
    // End STOP
    return ack;
}

uint8_t i2c::rx(unsigned int ack)
{
    uint8_t dat = 0;
    // receive the byte.
    for (int i = 0; i < 8; ++i) {
        dat <<= 1;

        // Wait for any clock stretching. If any chip is latching the scl line low,
        // we need to wait for it, our transmission won't be heard if we don't.
        int free;
        do {
            sunxi_gpio_set_cfgpin(SCL, OUTPUT);
            sunxi_gpio_output(SCL, HIGH);
            sunxi_gpio_set_cfgpin(SCL, INPUT);
            free = sunxi_gpio_input(SCL);
        } while (!free);
        delay();

        sunxi_gpio_set_cfgpin(SDA, INPUT);
        int up = sunxi_gpio_input(SDA);
        // Read SDA, if it's HIGH we |= 1, if not it'll be a zero
        if (up) dat |= 1;

        // Pulse the clock back down, done reading this one
        sunxi_gpio_set_cfgpin(SCL, OUTPUT);
        sunxi_gpio_output(SCL, LOW);
        // continue reading
    }

    // send the (n)ack
    sunxi_gpio_set_cfgpin(SDA, OUTPUT);
    if (ack) {
        sunxi_gpio_output(SDA, LOW);
    } else {
        sunxi_gpio_output(SDA, HIGH);
    }
    sunxi_gpio_output(SCL, HIGH);
    delay(); // this is the wait for the (n)ack

    sunxi_gpio_output(SCL, LOW);
    sunxi_gpio_output(SDA, HIGH);
    return dat;
}


void i2c::send(uint8_t address, uint8_t reg, uint8_t *buf, size_t len)
{
    uint8_t write = address << 1; // Write address
    size_t addLen = 1;

    startBit();
    int ack = tx(&write, addLen);
    if (!ack) printf("ACK failed!");

    ack = tx(&reg, addLen);
    if (!ack) printf("ACK failed!");

    ack = tx(buf, len);
    if (!ack) printf("ACK failed!");
    stopBit();
}

uint8_t i2c::receive8(uint8_t address, uint8_t reg)
{
//    1. Send a start sequence
//    2. Send 0xC0 ( I2C address of the CMPS03 with the R/W bit low (even address)
//    3. Send 0x01 (Internal address of the bearing register)
//    4. Send a start sequence again (repeated start)
//    5. Send 0xC1 ( I2C address of the CMPS03 with the R/W bit high (odd address)
//    6. Read data byte from CMPS03
//    7. Send the stop sequence.

    uint8_t write = address << 1; // Write address
    uint8_t read = write + (uint8_t )1; // read address, final bit turned on
    size_t len = 1;

    startBit();
    tx(&write, len);
    tx(&reg, len);
    startBit();
    tx(&read, len);
    uint8_t val = rx(0);
    stopBit();
    return val;
}

uint16_t i2c::receive16(uint8_t address, uint8_t reg)
{
    uint8_t write = address << 1; // Write address is 7bit add << 1 with 8th bit as 0
    uint8_t read = write + (uint8_t )1; // read address, final bit turned on

    size_t len = 1;

    startBit();
    tx(&write, len); // send the address
    tx(&reg, len); // send the register we want to read
    startBit(); // restart
    tx(&read, len); // start the read
    uint8_t h = rx(1); // byte 0 + ACK
    uint8_t l = rx(0); // byte 1 + NACK
    stopBit();

    uint16_t val = (uint16_t)h;
    val <<= 8;
    val += l;

    return val;
}

i2c::~i2c()
{

}
