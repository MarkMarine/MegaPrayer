#include <iostream>
#include "I2cFactory.h"
#include "I2c.h"
#include "Mpr121.h"
#include <bitset>
#include <vector>


int main() {

    std::cout << "Starting connection" << std::endl;
//    {'gpio_num': 0, 'alternate_func': 'UART2_TX', 'header_num': 13, 'pin_name': 'PA0'} -> SCL (blue)
//    {'gpio_num': 1, 'alternate_func': 'UART2_RX', 'header_num': 11, 'pin_name': 'PA1'} -> SDA (green)

    I2cFactory i2cFactory;
    auto i2c_loop0 = i2cFactory.create_I2c(0, 1);
    auto i2c_loop1 = i2cFactory.create_I2c(198, 199);

    Mpr121 mpr0(i2c_loop0, 0x5A); // 0 - 11
    Mpr121 mpr1(i2c_loop0, 0x5B); // 12 - 23
    Mpr121 mpr2(i2c_loop0, 0x5C); // 24 - 35
    Mpr121 mpr3(i2c_loop0, 0x5D); // 36 - 47
    Mpr121 mpr4(i2c_loop1, 0x5A); // 48 - 59

    std::vector<Mpr121> sensors;
    sensors.push_back(mpr0);
    sensors.push_back(mpr1);
    sensors.push_back(mpr2);
    sensors.push_back(mpr3);
    sensors.push_back(mpr4);

    for (auto s : sensors) {
        if (!s.begin()) std::cout << "MPR init failed" << std::endl;
    }


    uint64_t current = 0;
    uint64_t last = 0;

    while (last != -1) {

        for (int i = 0; i < sensors.size(); ++i) {
            auto t = sensors[i].touched();
            t <<= 4;
            current |= t << (i * 12); // TODO, test this to make sure it gets the right bits over
        }
        
        if (current!=last) std::cout<<std::bitset<64> (current) <<std::endl;
        last = current;
    }
    return 0;
}