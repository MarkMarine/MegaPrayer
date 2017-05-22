cmake_minimum_required(VERSION 3.6)
project(megaprayerI2c)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp i2c.cpp i2c.h common.h common.c gpio_lib.c gpio_lib.h mpr121.cpp mpr121.h)

FIND_PACKAGE (Threads)

add_executable(megaprayerI2c ${SOURCE_FILES})
TARGET_LINK_LIBRARIES( megaprayerI2c ${CMAKE_THREAD_LIBS_INIT} )
