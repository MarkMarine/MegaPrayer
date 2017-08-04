cmake_minimum_required(VERSION 3.6)
project(megaprayerI2c)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

#add_subdirectory (liblo/cmake)
#add_library (liblo liblo/lo/lo.h liblo/lo/lo_cpp.h)
#target_include_directories (Liblo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp common.h common.c gpio_lib.c gpio_lib.h Mpr121.cpp Mpr121.h OrangePi0_i2c/I2c.h OrangePi0_i2c/I2cFactory.h TouchControllers.cpp TouchControllers.h)

FIND_PACKAGE (Threads)
find_package( liblo REQUIRED )
include_directories(${liblo_INCLUDE_DIRS})
set(LIBS ${LIBS} ${liblo_LIBRARIES})

add_executable(megaprayerI2c ${SOURCE_FILES})
TARGET_LINK_LIBRARIES( megaprayerI2c ${CMAKE_THREAD_LIBS_INIT} ${LIBS})
