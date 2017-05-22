//
// Created by Mark Fox on 5/21/17.
//

#ifndef MEGAPRAYERI2C_I2C_H
#define MEGAPRAYERI2C_I2C_H

#define CLK_WIDTH 600

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

#include <cstdlib>
#include <stdint.h>

class i2c {
private:
    void delay(void);
    void startBit(void);
    void stopBit(void);
    int tx(uint8_t *buf, size_t len);
    unsigned char rx(unsigned int ack);

public:
    i2c(unsigned int scl, unsigned int sda);
    bool init(void);
    void send(uint8_t address, uint8_t reg, uint8_t *buf, size_t len);
    uint8_t receive8(uint8_t address, uint8_t reg);
    uint16_t receive16(uint8_t address, uint8_t reg);
    unsigned int SCL;
    unsigned int SDA;

    ~i2c();
};


#endif //MEGAPRAYERI2C_I2C_H
