#include <iostream>
#include "i2c.h"
using std::hex;

int main() {

    std::cout << "Starting connection" << std::endl;
//    {'gpio_num': 0, 'alternate_func': 'UART2_TX', 'header_num': 13, 'pin_name': 'PA0'} -> SCL (blue)
//    {'gpio_num': 1, 'alternate_func': 'UART2_RX', 'header_num': 11, 'pin_name': 'PA1'} -> SDA (green)
//    Address 0x5A

    i2c mpr(0, 1);

    mpr.init();
    //(0x5A << 1; 0x80, 0x63) this is a soft reset
    uint8_t add = 180;
    uint8_t reg = 128;
    uint8_t val = 99;
    mpr.txWStartStop(add, reg, val);

//    uint8_t address = 0x5a;
//    //(0x80, 0x63) this is a soft reset
//    uint8_t buf[2] = {128, 99};
//    size_t len = 2;
//
//    std::cout << "Start Bit" << std::endl;
//    mpr.startBit();
//    std::cout << "Stop Bit" << std::endl;
//    mpr.stopBit();
//    std::cout << "stopped" << std::endl;
//
//    std::cout << "................................................" << std::endl;
//
//    for (size_t i = 0; i < len; i++) {
//        std::cout << "hex: 0x" << std::hex << buf[i] << std::endl;
//    }
//
//
//    mpr.startBit();
//    mpr.send(address, buf, len);
//
//    //cfg2 = self.receive8(0x5D) this is checking a config
//    //if cfg2 != 0x24: failed comms
//    uint8_t reg = 0x5d;
//    uint8_t cf2 = mpr.receive8(address, reg);
//
//    uint8_t result = 0x24;
//
//    if (cf2 != result) {
//        std::cout << "cf2 wrong" << std::endl;
//        std::cout << "hex: 0x" << hex << cf2 << std::endl;
//    } else {
//        std::cout << "woooo!" << std::endl;
//    }

    std::cout << "Done" << std::endl;
    return 0;
}