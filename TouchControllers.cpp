//
// Created by Mark Fox on 8/3/17.
//

#include "TouchControllers.h"

#include <sstream>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

#include <lo/lo.h>
#include <lo/lo_cpp.h>

#include "OrangePi0_i2c/I2cFactory.h"
#include "Mpr121.h"

// Here are all the pinouts for the OrangePi
// loop 0
#define i2c_0_scl 12    // 3
#define i2c_0_sda 11    // 5
#define INT_PIN0 1      // 11
#define INT_PIN1 0      // 13
#define INT_PIN2 3      // 15

// loop 1
#define i2c_1_scl 13    // 24
#define i2c_1_sda 10    // 26
#define INT_PIN3 7      // 12
#define INT_PIN4 19     // 16

#define INT_PIN5 10     // 26

// LED controller address
#define CONTROLLER_IP "192.168.1.72"
#define CONTROLLER_PORT "5006"

#define BUNDLE_MSG 0 // Leave bundle messages off, they don't work

using namespace std;

TouchControllers::TouchControllers() {}

bool TouchControllers::init() {
    I2cFactory i2cFactory;
    // MPR121 can't handle more than 4 sensors on one i2c loop because of the addressing
    i2c_0 = i2cFactory.create_I2c(i2c_0_scl, i2c_0_sda);
    i2c_1 = i2cFactory.create_I2c(i2c_1_scl, i2c_1_sda);

    bool started = false;
    bool failed = false;

    unsigned int mult = 0;
    Mpr121 mpr0(i2c_0, 0x5A, INT_PIN0, mult); // 0 - 11
    started = mpr0.begin();
    if (!started) { cout << "failed init mpr" << 0 << endl; failed = true; }
    else {
        sensors.push_back(mpr0);
        for (int i = 12 * mult; i < 12 * mult; ++i) {
            beadState[i] = false;
        }
    }

    mult = 1;
    Mpr121 mpr1(i2c_0, 0x5B, INT_PIN1, mult); // 12 - 23
    started = mpr1.begin();
    if (!started) { cout << "failed init mpr" << 1 << endl; failed = true; }
    else {
        sensors.push_back(mpr1);
        for (int i = 12 * mult; i < 12 * mult; ++i) {
            beadState[i] = false;
        }
    }

    mult = 2;
    Mpr121 mpr2(i2c_0, 0x5C, INT_PIN2, mult); // 24 - 35
    started = mpr2.begin();
    if (!started) { cout << "failed init mpr" << 2 << endl; failed = true; }
    else {
        sensors.push_back(mpr2);
        for (int i = 12 * mult; i < 12 * mult; ++i) {
            beadState[i] = false;
        }
    }

    mult = 3;
    Mpr121 mpr3(i2c_1, 0x5A, INT_PIN3, mult); // 36 - 47
    started = mpr3.begin();
    if (!started) { cout << "failed init mpr" << 3 << endl; failed = true; }
    else {
        sensors.push_back(mpr3);
        for (int i = 12 * mult; i < 12 * mult; ++i) {
            beadState[i] = false;
        }
    }

    mult = 4;
    Mpr121 mpr4(i2c_1, 0x5B, INT_PIN4, mult); // 48 - 59
    started = mpr4.begin();
    if (!started) { cout << "failed init mpr" << 4 << endl; failed = true; }
    else {
        sensors.push_back(mpr4);
        for (int i = 12 * mult; i < 12 * mult; ++i) {
            beadState[i] = false;
        }
    }
//
//    mult = 5;
//    Mpr121 nails(i2c_1, 0x5C, INT_PIN5, mult); // 60, 61 (Left, Right nail, respectively)
//    started = nails.begin();
//    if (!started) { cout << "failed init nails" << endl; failed = true; }
//    else {
//        sensors.push_back(nails);
//        for (int i = 12 * mult; i < 12 * mult; ++i) {
//            beadState[i] = false;
//        }
//    }

    return !failed;
}

bool TouchControllers::sensorsTriggered() {
    for (auto s : sensors) {
        if (s.interruptTriggered()) {
            return true;
        }
    }
    return false;
}

vector<pair<unsigned int, unsigned int>> TouchControllers::allBeadsChanged() {
    vector<pair<unsigned int, unsigned int>> ret;

    for (auto s : sensors) {
        if (s.interruptTriggered()) {
            auto changed = s.beadsChanged(beadState);
            // add the resulting vector to the ret
            ret.insert(ret.end(), changed.begin(), changed.end());
        }
    }

    return ret;
};

int TouchControllers::sendOSC() {
    lo::Address controller(CONTROLLER_IP, CONTROLLER_PORT);
    lo::Bundle bundle;

    int sent = 0;

    auto changed = allBeadsChanged();
    for (auto c : changed) {
        if (c.first < 60) {
            ostringstream ss;
            ss << "/trigger/bead/number/" << c.first;
            auto msg = lo::Message("i", c.second);

            if (BUNDLE_MSG) { bundle.add(ss.str().c_str(), msg); }
            else { sent += controller.send(ss.str().c_str(), msg); }
        }
        else {

            ostringstream ss;
            if (c.first == 60){ ss << "/trigger/left_nail"; }
            else if (c.first == 61) { ss << "/trigger/right_nail"; }
            else { continue; } // TODO add error handling here
            bundle.add(ss.str().c_str(), lo::Message("i", c.second));
        }
    }
    if (BUNDLE_MSG){ sent =  controller.send(bundle); }
    return sent;
}

void TouchControllers::clientLoop() {
    while (true) {
        // loop over the input pins as quickly as possible, and bundle packets when
        if (sensorsTriggered()) {
            sendOSC();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
