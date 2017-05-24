//
// Created by Mark Fox on 5/23/17.
//

#include "I2cFactory.h"
#include <err.h>
#include <memory>

std::shared_ptr<I2c> I2cFactory::create_I2c(unsigned int scl, unsigned int sda)
{

    std::shared_ptr<I2c> i2c(new I2c(scl, sda));

    if (i2c->init() != 0) {
        err(1, "i2c->init() failed");
        return NULL;
    }

    return i2c;
}
