#include <iostream>
#include "i2c.h"
#include "mpr121.h"
#include <bitset>


int main() {

    std::cout << "Starting connection" << std::endl;
//    {'gpio_num': 0, 'alternate_func': 'UART2_TX', 'header_num': 13, 'pin_name': 'PA0'} -> SCL (blue)
//    {'gpio_num': 1, 'alternate_func': 'UART2_RX', 'header_num': 11, 'pin_name': 'PA1'} -> SDA (green)
//    Address 0x5A

    i2c i2c1(0, 1);
    i2c1.init();

    mpr121 mpr1(&i2c1, 0x5A);
    if (!mpr1.begin()) std::cout << "MPR init failed" << std::endl;

    uint16_t current;
    uint16_t last;

    while (true) {
        current = mpr1.touched();
//        if (cap.touched() & (1 << 4)) { do something }
        if (current!=last) std::cout<<std::bitset<16> (current) <<std::endl;
//        for (uint8_t i = 0; i < 12; i++) {

//            // it if *is* touched and *wasnt* touched before, alert!
//            if ((current & bitVal(i)) && !(last & bitVal(i))) {
//                std::cout<<std::bitset<16>(i)<<std::endl;
////                std::cout << (int)i << " touched" << std::endl;
//            }
//            // if it *was* touched and now *isnt*, alert!
//            if (!(current & bitVal(i)) && (last & bitVal(i))) {
////                std::cout << (int)i << " released" << std::endl;
//            }
//        }
        last = current;
    }
    return 0;
}