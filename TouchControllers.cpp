//
// Created by Mark Fox on 8/3/17.
//


#include "TouchControllers.h"
#include "OrangePi0_i2c/I2cFactory.h"
#include "Mpr121.h"
#include <sstream>
#include <string>

#include <lo/lo.h>
#include <lo/lo_cpp.h>


// Here are all the pinouts for the OrangePi
#define i2c_0_scl 0
#define i2c_0_sda 1
#define i2c_1_scl 198
#define i2c_1_sda 199

#define INT_PIN0 0
#define INT_PIN1 0
#define INT_PIN2 0
#define INT_PIN3 0
#define INT_PIN4 0
#define INT_PIN5 0

// LED controller address
#define CONTROLLER_IP "192.168.1.100"
#define CONTROLLER_PORT "5006"

using namespace std;

TouchControllers::TouchControllers() {
    I2cFactory i2cFactory;

    // MPR121 can't handle more than 4 sensors on one i2c loop because of the addressing
    i2c_0 = i2cFactory.create_I2c(i2c_0_scl, i2c_0_sda);
    Mpr121 mpr0(i2c_0, 0x5A, INT_PIN0, 0); // 0 - 11
    Mpr121 mpr1(i2c_0, 0x5B, INT_PIN1, 1); // 12 - 23
    Mpr121 mpr2(i2c_0, 0x5C, INT_PIN2, 2); // 24 - 35

    i2c_1 = i2cFactory.create_I2c(i2c_1_scl, i2c_1_sda);
    Mpr121 mpr3(i2c_1, 0x5A, INT_PIN3, 3); // 36 - 47
    Mpr121 mpr4(i2c_1, 0x5B, INT_PIN4, 4); // 48 - 59
    Mpr121 nails(i2c_1, 0x5C, INT_PIN5, 5); // 60, 61 (Left, Right nail, respectively)

    sensors.push_back(mpr0);
    sensors.push_back(mpr1);
    sensors.push_back(mpr2);
    sensors.push_back(mpr3);
    sensors.push_back(mpr4);
    sensors.push_back(nails);
}

bool TouchControllers::touched() {
    for (auto s : sensors) {
        if (s.triggered()) {
            return true;
        }
    }
    return false;
}

vector<pair<unsigned int, bool>> TouchControllers::changed() {
    vector<pair<unsigned int, bool>> ret;

    for (auto s : sensors) {
        if (s.triggered()) {
            auto changed = s.changed();
            // add the resulting vector to the ret
            ret.insert(ret.end(), changed.begin(), changed.end());
        }
    }

    return ret;
};

void TouchControllers::sendOSC(vector<pair<unsigned int, bool>> changed) {
    lo::Address controller(CONTROLLER_IP, CONTROLLER_PORT);
    lo::Bundle bundle;

    for (auto c : changed) {
        if (c.first < 60) {
            ostringstream ss;
            ss << "/trigger/bead/number/" << c.first;
            float val;
            if (c.second) { val = 1.0; } else { val = 0.0; }
            bundle.add(ss.str().c_str(), lo::Message("i", val));
        } else {
            ostringstream ss;
            if (c.first == 60){
                ss << "/trigger/left_nail";
            } else {
                ss << "/trigger/right_nail";
            }
            float val;
            if (c.second) { val = 1.0; } else { val = 0.0; }
            bundle.add(ss.str().c_str(), lo::Message("i", val));
        }
    }
    controller.send(bundle);
}

void TouchControllers::clientLoop() {
    while (true) {
        // loop over the input pins as quickly as possible, and bundle packets when
        if (touched()) {
            sendOSC(changed());
        }
    }
}
