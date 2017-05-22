//
// Created by Mark Fox on 5/21/17.
//

#ifndef MEGAPRAYERI2C_I2C_H
#define MEGAPRAYERI2C_I2C_H

#define CLK_WIDTH 100

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

// The default I2C address
#define MPR121_I2CADDR_DEFAULT  0x5A
#define MPR121_TOUCHSTATUS_L    0x00
#define MPR121_TOUCHSTATUS_H    0x01
#define MPR121_FILTDATA_0L      0x04
#define MPR121_FILTDATA_0H      0x05
#define MPR121_BASELINE_0       0x1E
#define MPR121_MHDR             0x2B
#define MPR121_NHDR             0x2C
#define MPR121_NCLR             0x2D
#define MPR121_FDLR             0x2E
#define MPR121_MHDF             0x2F
#define MPR121_NHDF             0x30
#define MPR121_NCLF             0x31
#define MPR121_FDLF             0x32
#define MPR121_NHDT             0x33
#define MPR121_NCLT             0x34
#define MPR121_FDLT             0x35
#define MPR121_TOUCHTH_0        0x41
#define MPR121_RELEASETH_0      0x42
#define MPR121_DEBOUNCE         0x5B
#define MPR121_CONFIG1          0x5C
#define MPR121_CONFIG2          0x5D
#define MPR121_CHARGECURR_0     0x5F
#define MPR121_CHARGETIME_1     0x6C
#define MPR121_ECR              0x5E
#define MPR121_AUTOCONFIG0      0x7B
#define MPR121_AUTOCONFIG1      0x7C
#define MPR121_UPLIMIT          0x7D
#define MPR121_LOWLIMIT         0x7E
#define MPR121_TARGETLIMIT      0x7F
#define MPR121_GPIODIR          0x76
#define MPR121_GPIOEN           0x77
#define MPR121_GPIOSET          0x78
#define MPR121_GPIOCLR          0x79
#define MPR121_GPIOTOGGLE       0x7A
#define MPR121_SOFTRESET        0x80

#include <cstdlib>
#include <stdint.h>

class i2c {
public:
    void checkError(int func);
    void delay(void);
    void startBit(void);
    void stopBit(void);
    int tx(uint8_t *buf, size_t len);
    int txWStartStop(uint8_t addr, uint8_t reg, uint8_t val);
    unsigned char rx(unsigned int ack);
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
