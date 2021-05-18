
include(../QxOrm/QxOrm.pri)

TEMPLATE = lib
CONFIG += dll
DEFINES += _BUILDING_DEPARTMENT
INCLUDEPATH += ../QxOrm/include
DESTDIR = $$PWD/bin/

CONFIG(debug, debug|release) {
TARGET = departmentd
} else {
TARGET = department
} # CONFIG(debug, debug|release)

LIBS += -L"../QxOrm/lib"

CONFIG(debug, debug|release) {
LIBS += -l"QxOrmd"
} else {
LIBS += -l"QxOrm"
} # CONFIG(debug, debug|release)

include($$PWD/department.gen.pri)

!contains(DEFINES, _QX_UNITY_BUILD) {
SOURCES += $$PWD/src/department_main.gen.cpp
} # !contains(DEFINES, _QX_UNITY_BUILD)
