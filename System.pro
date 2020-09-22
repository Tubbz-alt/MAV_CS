TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -pthread
LIBS += -pthread

SOURCES += \
        main.cpp \
    Device/device.cpp \
    Device/i2cdevice.cpp \
    Device/uartdevice.cpp \
    Device/gpiodevice.cpp \
    Sensor/camera.cpp

HEADERS += \
    Device/device.hpp \
    Device/i2cdevice.hpp \
    Sensor/sensor.hpp \
    Sensor/camera.hpp \
    Sensor/imu.hpp \
    Sensor/accelerometer_lis331dlh.hpp \
    Device/uartdevice.hpp \
    Device/gpiodevice.hpp

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_videoio

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include


unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_core

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_imgproc

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_highgui

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include
