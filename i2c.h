//
// Created by Mark Fox on 5/21/17.
//

#ifndef MEGAPRAYERI2C_I2C_H
#define MEGAPRAYERI2C_I2C_H

#define CLK_WIDTH 120


#include <cstdlib>

class i2c {
private:
    void delay(void);
    void startBit(void);
    void stopBit(void);
    unsigned int tx(unsigned char *buf, size_t len);
    unsigned char rx(unsigned int ack);
public:
    i2c(int scl, int sda);
    bool init(void);
    void send(uint8_t address, unsigned char *buf, size_t len);
    unsigned char receive8(uint8_t address, uint8_t reg);
    uint16_t receive16(uint8_t address, uint8_t reg);
    int gpio_scl;
    int gpio_sda;

    ~i2c();
};


#endif //MEGAPRAYERI2C_I2C_H
