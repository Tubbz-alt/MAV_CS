TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Device/device.cpp \
    Device/i2cdevice.cpp \
    Device/uartdevice.cpp

HEADERS += \
    Device/device.hpp \
    Device/i2cdevice.hpp \
    Sensor/sensor.hpp \
    Sensor/camera.hpp \
    Sensor/imu.hpp \
    Sensor/accelerometer_lis331dlh.hpp \
    Device/uartdevice.hpp \
    Device/gpiodevice.hpp
