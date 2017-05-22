#include <iostream>
#include <thread>
#include <chrono>
#include "i2c.h"
//using namespace std::literals;

int main() {

    std::cout << "Starting connection" << std::endl;
//    {'gpio_num': 0, 'alternate_func': 'UART2_TX', 'header_num': 13, 'pin_name': 'PA0'} -> SCL (blue)
//    {'gpio_num': 1, 'alternate_func': 'UART2_RX', 'header_num': 11, 'pin_name': 'PA1'} -> SDA (green)
//    Address 0x5A

    i2c mpr(0, 1);

    mpr.init();
    const uint8_t address = 0x5a;
    uint8_t reg = 0x80;
    //(0x80, 0x63) this is a soft reset
    uint8_t buf[1] = {0x63};
    size_t len = 1;

    mpr.send(address, reg, buf, len);

    //cfg2 = self.receive8(0x5D) this is checking a config
    //if cfg2 != 0x24: failed comms
    reg = 0x5d;
    uint8_t cf2 = mpr.receive8(address, reg);

    if (cf2 != 0x24) {
        std::cout << "cf2 wrong" << std::endl;
    }



    std::cout << "Done" << std::endl;
    return 0;
}