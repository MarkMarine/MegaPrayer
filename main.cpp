//#include <iostream>
//#include "OrangePi0_i2c/I2cFactory.h"
//#include "Mpr121.h"
//#include <vector>
//#include <thread>
//
//using namespace std;
//
//void readLoop(vector<Mpr121> sensors, bitset<12> current, bitset<12> last) {
//    while (last != -1) {
//        auto touched = sensors[0].touched();
//        current = bitset<12> (touched);
//
////        for (int i = 0; i < sensors.size(); ++i) {
////            auto touched = sensors[i].touched();
////
////            touched <<= 4;
////            current |= touched << (i * 12); // TODO, test this to make sure it gets the right bits over
////        }
//
//        if (current!=last) cout << bitset<12> (current) <<endl;
//        last = current;
//    }
//}
//
//int main() {
//
//    cout << "Starting connection" << endl;
////    {'gpio_num': 0, 'alternate_func': 'UART2_TX',  'header_num': 13, 'pin_name': 'PA0'} -> SCL (blue)
////    {'gpio_num': 1, 'alternate_func': 'UART2_RX',  'header_num': 11, 'pin_name': 'PA1'} -> SDA (green)
//
////    {'gpio_num': 198, 'alternate_func': 'UART1_TX','header_num': 8,  'pin_name': 'PG6'} -> SCL (blue)
////    {'gpio_num': 199, 'alternate_func': 'UART1_RX','header_num': 10, 'pin_name': 'PG7'} -> SDA (green)
//
//    I2cFactory i2cFactory;
//    auto i2c_loop0 = i2cFactory.create_I2c(0, 1);
//    Mpr121 mpr0(i2c_loop0, 0x5A, 1000, 0); // 0 - 11   TODO change 1000
//    Mpr121 mpr1(i2c_loop0, 0x5B, 1000, 1); // 12 - 23
//    Mpr121 mpr2(i2c_loop0, 0x5C, 1000, 2); // 24 - 35
//    vector<Mpr121> sensors0;
//    sensors0.push_back(mpr0);
//    sensors0.push_back(mpr1);
//    sensors0.push_back(mpr2);
//
//    auto i2c_loop1 = i2cFactory.create_I2c(198, 199);
//    Mpr121 mpr3(i2c_loop1, 0x5A, 1000, 3); // 36 - 47
//    Mpr121 mpr4(i2c_loop1, 0x5B, 1000, 4); // 48 - 59
//    vector<Mpr121> sensors1;
//    sensors1.push_back(mpr3);
//    sensors1.push_back(mpr4);
//
//    for (auto s : sensors0) {
//        if (!s.begin()) cout << "MPR init failed loop0" << endl;
//    }
////    for (auto s : sensors1) {
////        if (!s.begin()) cout << "MPR init failed loop1" << endl;
////    }
//
//
//    bitset<12> current0 = 0;
////    uint64_t current1 = 0;
//    bitset<12> last0 = 0;
////    uint64_t last1 = 0;
//
//    thread loop0 (readLoop, sensors0, current0, last0);
////    thread loop1 (readLoop, sensors1, current1, last1);
//
//    loop0.join();
////    loop1.join();
//
//    return 0;
//}