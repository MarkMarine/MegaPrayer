cmake_minimum_required(VERSION 3.6)
project(megaprayerI2c)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
FIND_PACKAGE (Threads)
FIND_PACKAGE( liblo REQUIRED )

include_directories(${LIBLO_INCLUDE_DIRS})
set(LIBS ${LIBS} ${LIBLO_LIBRARIES})
# compiler flags
SET( LIBLO_LINK_FLAGS  ${LIBLO_DEFINITIONS})
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${LIBLO_LINK_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LIBLO_LINK_FLAGS}" )

set(SOURCE_FILES main.cpp common.h common.c gpio_lib.c gpio_lib.h Mpr121.cpp Mpr121.h
        OrangePi0_i2c/I2c.h OrangePi0_i2c/I2c.cpp OrangePi0_i2c/I2cFactory.h OrangePi0_i2c/I2cFactory.cpp
        TouchControllers.cpp TouchControllers.h)

add_executable(megaprayerI2c ${SOURCE_FILES})
TARGET_LINK_LIBRARIES( megaprayerI2c ${CMAKE_THREAD_LIBS_INIT} ${LIBS})
