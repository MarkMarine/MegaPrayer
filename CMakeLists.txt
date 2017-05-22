

cmake_minimum_required(VERSION 3.6)
project(megaprayerI2c)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp i2c.cpp i2c.h common.h common.c event_gpio.c event_gpio.h gpio_lib.c gpio_lib.h)
#set(BOOST_ROOT /usr/local/boost_1_64_0)
#set(BOOST_LIBRARYDIR /usr/local/boost_1_64_0/stage/lib)

FIND_PACKAGE (Threads)
#FIND_PACKAGE( Boost 1.64 COMPONENTS program_options REQUIRED )
#INCLUDE_DIRECTORIES( ${BOOST_ROOT} )
#LINK_DIRECTORIES(${BOOST_LIBRARYDIR})

add_executable(megaprayerI2c ${SOURCE_FILES})
TARGET_LINK_LIBRARIES( megaprayerI2c ${CMAKE_THREAD_LIBS_INIT} )
#TARGET_LINK_LIBRARIES( megaprayerI2c LINK_PUBLIC ${Boost_LIBRARIES} )