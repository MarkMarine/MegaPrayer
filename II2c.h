//
// Created by Mark Fox on 5/23/17.
//

#ifndef MEGAPRAYERI2C_II2C_H
#define MEGAPRAYERI2C_II2C_H

#include <string>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <iostream>

//#ifdef DEBUG
//#define log(msg) _log(msg)
//#else
//#define log(msg)
//#endif

class II2c
{
 public:
    II2c(unsigned int SCL_, unsigned int SDA_) {};

    virtual bool init(void)  = 0;
    virtual void send(uint8_t address, uint8_t reg, uint8_t *buf, size_t len) = 0;
    virtual uint8_t receive8(uint8_t address, uint8_t reg) = 0;
    virtual uint16_t receive16(uint8_t address, uint8_t reg) = 0;

//    // general purpose logging function for debugging
//    void _log(std::string msg) {
//        struct timeval tv;
//        if (gettimeofday(&tv, NULL) < 0) {
//            return;
//        }
//
//        printf("%ld.%ld %s\n", tv.tv_sec, tv.tv_usec, msg.c_str());
//    };

    virtual ~II2c() {};
};


#endif //MEGAPRAYERI2C_II2C_H
