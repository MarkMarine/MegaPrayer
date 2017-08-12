#include <iostream>
#include <thread>

#include "TouchControllers.h"

int main() {
    TouchControllers controller;
    cout << "running main controller start" << endl;

    if (controller.init()) {
        controller.clientLoop();
    } else {
        cout << "failed main.cpp init" << endl;
        return 1;
    }

    return 0;
}
