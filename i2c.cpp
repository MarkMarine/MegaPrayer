//
// Created by Mark Fox on 5/21/17.
//

#include "i2c.h"
#include <cstdio>
#include "gpio_lib.h"
#include "event_gpio.h"
//#include <boost/thread/thread.hpp>



i2c::i2c(int scl, int sda) :
        gpio_scl(scl), gpio_sda(sda)
{
}


bool i2c::init(void)
{
    if (sunxi_gpio_init() < 0) {
        printf("ERROR: sunxi_gpio_init() failed");
        return false;
    }

    gpio_export(gpio_scl);
    gpio_export(gpio_sda);

    gpio_set_direction(gpio_scl, 1);
    gpio_set_direction(gpio_sda, 1);

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
    gpio_set_direction(gpio_scl, OUTPUT);
    gpio_set_direction(gpio_sda, OUTPUT);

    gpio_set_value(gpio_scl, HIGH);
    delay();
    gpio_set_value(gpio_sda, HIGH);
    delay();
    gpio_set_value(gpio_sda, LOW);
    delay();
    gpio_set_value(gpio_scl, LOW);
    delay();


}

void i2c::stopBit(void)
{
    // Releasing SDA to float high again would be a stop marker
    // signaling the end of a bus transaction.
    gpio_set_direction(gpio_scl, OUTPUT);
    gpio_set_direction(gpio_sda, OUTPUT);

    gpio_set_value(gpio_sda, LOW);
    delay();
    gpio_set_value(gpio_scl, HIGH);
    delay();
    gpio_set_value(gpio_sda, HIGH);
    delay();
}

unsigned int i2c::tx(unsigned char *buf, size_t len)
{

    gpio_set_direction(gpio_scl, OUTPUT);
    gpio_set_direction(gpio_sda, OUTPUT);

    int b;
    unsigned char bit;
    for (size_t i = 0; i < len; i++) {
        bit = 0x80;
        for (b = 0; b < 8; b++) {
            //printf("%d & %d = %d\n", buf[i], bit, buf[i] & bit);

            gpio_set_value(gpio_sda, (buf[i] & bit));
            delay();

            gpio_set_value(gpio_scl, HIGH);
            delay();

            bit >>= 1;
            gpio_set_value(gpio_scl, LOW);
        }
    }
    gpio_set_value(gpio_sda, HIGH);
    gpio_set_value(gpio_scl, HIGH);
    delay();

    // Read SDA for the (N)ACK
    gpio_set_direction(gpio_sda, INPUT);

    unsigned int ack = LOW;
    gpio_get_value(gpio_sda, &ack);
    gpio_set_value(gpio_scl, LOW);
    return ack;
}

unsigned char i2c::rx(unsigned int ack)
{
    unsigned char d=0;
    gpio_set_direction(gpio_scl, OUTPUT);
    gpio_set_direction(gpio_sda, OUTPUT);

    // unlatch SDA TODO can this just be set input?
    gpio_set_value(gpio_sda, HIGH);

    // receive the byte.
    for (int i = 0; i < 8; ++i) {
        d <<= 1;

        // Wait for any clock stretching. If any chip is latching the scl line low,
        // we need to wait for it, our transmission won't be heard if we don't.
        unsigned int scl = LOW;
        do {
            gpio_set_direction(gpio_scl, OUTPUT);
            gpio_set_value(gpio_scl, HIGH);
            gpio_set_direction(gpio_scl, INPUT);
            gpio_get_value(gpio_scl, &scl);
        } while (scl == LOW);
        delay();

        // Read SDA, if it's HIGH we |= 1, if not it'll be a zero
        unsigned int sda = LOW;
        gpio_set_direction(gpio_sda, INPUT);
        gpio_get_value(gpio_sda, &sda);
        if (sda == HIGH) d |= 1;

        // Pulse the clock back down, done reading this one
        gpio_set_direction(gpio_scl, OUTPUT);
        gpio_set_value(gpio_scl, LOW);
        // continue reading
    }

    // send the (n)ack
    gpio_set_direction(gpio_sda, OUTPUT);
    if (ack) {
        gpio_set_value(gpio_sda, LOW);
    } else {
        gpio_set_value(gpio_sda, HIGH);
    }
    gpio_set_value(gpio_scl, HIGH);
    delay(); // this is the wait for the (n)ack

    gpio_set_value(gpio_scl, LOW);
    gpio_set_value(gpio_sda, HIGH);
    return d;
}


void i2c::send(uint8_t address, unsigned char *buf, size_t len)
{
    address <<= 1; // Write address
    unsigned char* add = reinterpret_cast<unsigned char*>(&address);
    size_t addLen = 1;

    startBit();
    tx(add, addLen);
    tx(buf, len);
    stopBit();
}

unsigned char i2c::receive8(uint8_t address, uint8_t reg)
{
//    1. Send a start sequence
//    2. Send 0xC0 ( I2C address of the CMPS03 with the R/W bit low (even address)
//    3. Send 0x01 (Internal address of the bearing register)
//    4. Send a start sequence again (repeated start)
//    5. Send 0xC1 ( I2C address of the CMPS03 with the R/W bit high (odd address)
//    6. Read data byte from CMPS03
//    7. Send the stop sequence.

    address <<= 1; // Write address
    unsigned char* writeAddress = reinterpret_cast<unsigned char*>(&address);
    address += 1;
    unsigned char* readAddress = reinterpret_cast<unsigned char*>(&address);

    unsigned char* readRegister = reinterpret_cast<unsigned char*>(&reg);
    size_t len = 1;

    startBit();
    tx(writeAddress, len);
    tx(readRegister, len);
    startBit();
    tx(readAddress, len);
    unsigned char val = rx(0);
    stopBit();

    return val;
}

uint16_t i2c::receive16(uint8_t address, uint8_t reg)
{
    address <<= 1; // Write address
    unsigned char* writeAddress = reinterpret_cast<unsigned char*>(&address);
    address += 1;
    unsigned char* readAddress = reinterpret_cast<unsigned char*>(&address);

    unsigned char* readRegister = reinterpret_cast<unsigned char*>(&reg);
    size_t len = 1;

    startBit();
    tx(writeAddress, len);
    tx(readRegister, len);
    startBit();
    tx(readAddress, len);
    unsigned char h = rx(1);
    unsigned char l = rx(0); //(N)ACK
    stopBit();

    (uint16_t) h;
    uint16_t val = h;
    val <<= 8;
    val += l;

    return val;
}

i2c::~i2c()
{

}
