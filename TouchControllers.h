//
// Created by Mark Fox on 8/3/17.
//

#ifndef MEGAPRAYERI2C_TOUCHCONTROLLERS_H
#define MEGAPRAYERI2C_TOUCHCONTROLLERS_H

#include "OrangePi0_i2c/I2cFactory.h"
#include "Mpr121.h"
#include <vector>
#include <memory>
#include <unordered_map>

using namespace std;


class TouchControllers {
public:
    TouchControllers();
    bool init();
    bool sensorsTriggered();
    vector<pair<unsigned int, unsigned int>> allBeadsChanged();
    int sendOSC();
    void clientLoop();
private:
    vector<Mpr121> sensors;
    unordered_map<unsigned int, bool> beadState;
    shared_ptr<I2c> i2c_0;
    shared_ptr<I2c> i2c_1;
};


#endif //MEGAPRAYERI2C_TOUCHCONTROLLERS_H
