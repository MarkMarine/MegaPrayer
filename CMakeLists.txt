cmake_minimum_required(VERSION 3.6)
project(megaprayerI2c)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp I2c.cpp I2c.h common.h common.c gpio_lib.c gpio_lib.h Mpr121.cpp Mpr121.h II2c.h I2cFactory.h I2cFactory.cpp)

FIND_PACKAGE (Threads)

add_executable(megaprayerI2c ${SOURCE_FILES})
TARGET_LINK_LIBRARIES( megaprayerI2c ${CMAKE_THREAD_LIBS_INIT} )
