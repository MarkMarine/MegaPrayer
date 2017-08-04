//
// Created by Mark Fox on 8/3/17.
//

#ifndef MEGAPRAYERI2C_TOUCHCONTROLLERS_H
#define MEGAPRAYERI2C_TOUCHCONTROLLERS_H

#include "OrangePi0_i2c/I2cFactory.h"
#include "Mpr121.h"
#include <vector>
#include <thread>
#include <map>

using namespace std;


class TouchControllers {
public:
    TouchControllers();
    void init();
    bool touched();
    vector<pair<unsigned int, bool>> changed();
    void sendOSC(vector<pair<unsigned int, bool>>);
    void clientLoop();

    ~TouchControllers();
private:
    vector<Mpr121> sensors;
    shared_ptr<I2c> i2c_0;
    shared_ptr<I2c> i2c_1;
};


#endif //MEGAPRAYERI2C_TOUCHCONTROLLERS_H
