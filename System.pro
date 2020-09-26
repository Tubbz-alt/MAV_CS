TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -pthread -O2
LIBS += -pthread

SOURCES += \
        main.cpp \
    Device/device.cpp \
    Device/i2cdevice.cpp \
    Device/uartdevice.cpp \
    Sensor/camera.cpp \
    Sensor/thermometer_dht.cpp \
    Device/GPIO.cpp

HEADERS += \
    Device/device.hpp \
    Device/i2cdevice.hpp \
    Sensor/sensor.hpp \
    Sensor/camera.hpp \
    Sensor/imu.hpp \
    Sensor/accelerometer_lis331dlh.hpp \
    Device/uartdevice.hpp \
    Sensor/thermometer_dht.hpp \
    Device/GPIO.hpp

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

unix:!macx: LIBS += -L$$PWD/../../../usr/lib/ -lwiringPi

