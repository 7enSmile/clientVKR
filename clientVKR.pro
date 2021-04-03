include(C:/Qt/QxOrm/QxOrm.pri)
QT+=widgets
TEMPLATE = app
DEFINES += _BUILDING_QX_BLOG_EXEC

INCLUDEPATH += C:/Qt/QxOrm/include/
INCLUDEPATH += D:/prodjects/entityVKR/include/

LIBS += -L"C:/Qt/QxOrm/lib"
LIBS += -L"D:/prodjects/entityVKR/bin"

CONFIG(debug, debug|release) {
TARGET = department
LIBS += -l"QxOrmd"
LIBS += -l"departmentd"
} else {
TARGET = department
LIBS += -l"QxOrm"
LIBS += -l"departmentd"
} # CONFIG(debug, debug|release)

!contains(DEFINES, _QX_NO_PRECOMPILED_HEADER) {
PRECOMPILED_HEADER = ./include/precompiled.h
} # !contains(DEFINES, _QX_NO_PRECOMPILED_HEADER)

QT       += core gui
TEMPLATE = app





SOURCES += main.cpp
SOURCES += $$PWD/src/view/studentswindow.cpp
SOURCES += $$PWD/src/model/abstractstudentsmodel.cpp
SOURCES += $$PWD/src/view/insertstudent.cpp
SOURCES += $$PWD/src/view/insertgroup.cpp
SOURCES += $$PWD/src/view/insertstaffuniversity.cpp
SOURCES += $$PWD/src/model/abstractgroupsmodel.cpp
SOURCES += $$PWD/src/view/mainwindow.cpp
SOURCES += $$PWD/src/view/staffuniversitywindow.cpp
SOURCES += $$PWD/src/model/abstractstaffemployermodel.cpp
SOURCES += $$PWD/src/model/abstractstaffuniversitymodel.cpp
SOURCES += $$PWD/src/model/abstractdepartmentsmodel.cpp
SOURCES += $$PWD/src/view/insertdepartment.cpp
HEADERS += $$PWD/include/view/studentswindow.h
HEADERS += $$PWD/include/model/abstractstudentsmodel.h
HEADERS += $$PWD/include/view/insertstudent.h
HEADERS += $$PWD/include/model/abstractgroupsmodel.h
HEADERS += $$PWD/include/export.h
HEADERS += $$PWD/include/precompiled.h
HEADERS += $$PWD/include/view/insertgroup.h
HEADERS += $$PWD/include/view/mainwindow.h
HEADERS += $$PWD/include/view/staffuniversitywindow.h
HEADERS += $$PWD/include/model/abstractstaffemployermodel.h
HEADERS += $$PWD/include/model/abstractstaffuniversitymodel.h
HEADERS += $$PWD/include/model/abstractdepartmentsmodel.h
HEADERS += $$PWD/include/view/insertstaffuniversity.h
HEADERS += $$PWD/include/view/insertdepartment.h
FORMS +=$$PWD/ui/studentswindow.ui
FORMS +=$$PWD/ui/insertstudent.ui
FORMS +=$$PWD/ui/insertgroup.ui
FORMS +=$$PWD/ui/mainwindow.ui
FORMS +=$$PWD/ui/staffuniversitywindow.ui
FORMS +=$$PWD/ui/insertstaffuniversity.ui
FORMS +=$$PWD/ui/insertdepartment.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
