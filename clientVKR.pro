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
LIBS += -l"department"
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
SOURCES += $$PWD/src/model/abstractstaffuniversitymodel.cpp
SOURCES += $$PWD/src/view/mainwindow.cpp
SOURCES += $$PWD/src/view/staffuniversitywindow.cpp
SOURCES += $$PWD/src/model/abstractcontactemployermodel.cpp
SOURCES += $$PWD/src/model/abstractheademployermodel.cpp
SOURCES += $$PWD/src/model/abstractdepartmentsmodel.cpp
SOURCES += $$PWD/src/view/insertdepartment.cpp
SOURCES += $$PWD/src/view/insertstaffemployer.cpp
SOURCES += $$PWD/src/view/staffemployerwindow.cpp
SOURCES += $$PWD/src/view/employerswindow.cpp
SOURCES += $$PWD/src/model/abstractemployermodel.cpp
SOURCES += $$PWD/src/view/additionalwindow.cpp
SOURCES += $$PWD/src/model/abstractactivitymodel.cpp
SOURCES += $$PWD/src/model/abstracttasksmodel.cpp
SOURCES += $$PWD/src/model/abstractcollaborationmodel.cpp
SOURCES += $$PWD/src/view/insertadditional.cpp
SOURCES += $$PWD/src/view/insertevent.cpp
SOURCES += $$PWD/src/view/eventswindow.cpp
SOURCES += $$PWD/src/view/practicewindow.cpp
SOURCES += $$PWD/src/model/abstractpracticemodel.cpp
SOURCES += $$PWD/src/view/searchstudents.cpp
SOURCES += $$PWD/src/model/abstractpassingpracticemodel.cpp
SOURCES += $$PWD/src/view/passingpracticewindow.cpp
SOURCES += $$PWD/src/model/abstracttaskspracticemodel.cpp
SOURCES += $$PWD/src/view/searchstaffuniversity.cpp
SOURCES += $$PWD/src/view/searchheademployer.cpp
SOURCES += $$PWD/src/view/inserttaskpractice.cpp
SOURCES += $$PWD/src/model/abstractreportsmodel.cpp
SOURCES += $$PWD/src/view/reportwindow.cpp
SOURCES += $$PWD/src/view/reportpracticewindow.cpp
SOURCES += $$PWD/src/model/abstactsubclassmodel.cpp
SOURCES += $$PWD/src/view/authorizationwindow.cpp
SOURCES += $$PWD/src/view/adminwindow.cpp
SOURCES += $$PWD/src/view/insertuser.cpp
SOURCES += $$PWD/src/model/abstractusersmodel.cpp
SOURCES += $$PWD/src/model/checkauthorizationmodel.cpp
SOURCES += $$PWD/src/model/abstracteventsmodel.cpp
SOURCES += $$PWD/src/view/reporteventswindow.cpp
SOURCES += $$PWD/src/view/educationalprogramwindow.cpp
SOURCES += $$PWD/src/view/inserteducationalprogram.cpp
SOURCES += $$PWD/src/view/insertadditionaleducationalprogram.cpp
SOURCES += $$PWD/src/view/insertresultdiscipline.cpp
SOURCES += $$PWD/src/view/insertdiscipline.cpp


HEADERS += $$PWD/include/view/studentswindow.h
HEADERS += $$PWD/include/model/abstractstudentsmodel.h
HEADERS += $$PWD/include/view/insertstudent.h
HEADERS += $$PWD/include/view/insertstaffemployer.h
HEADERS += $$PWD/include/model/abstractgroupsmodel.h
HEADERS += $$PWD/include/export.h
HEADERS += $$PWD/include/precompiled.h
HEADERS += $$PWD/include/view/insertgroup.h
HEADERS += $$PWD/include/view/mainwindow.h
HEADERS += $$PWD/include/view/staffuniversitywindow.h
HEADERS += $$PWD/include/model/abstractcontactemployermodel.h
HEADERS += $$PWD/include/model/abstractheademployermodel.h
HEADERS += $$PWD/include/model/abstractstaffuniversitymodel.h
HEADERS += $$PWD/include/model/abstractdepartmentsmodel.h
HEADERS += $$PWD/include/view/insertstaffuniversity.h
HEADERS += $$PWD/include/view/insertdepartment.h
HEADERS += $$PWD/include/view/staffemployerwindow.h
HEADERS += $$PWD/include/view/employerswindow.h
HEADERS += $$PWD/include/model/abstractemployermodel.h
HEADERS += $$PWD/include/view/additionalwindow.h
HEADERS += $$PWD/include/model/abstractactivitymodel.h
HEADERS += $$PWD/include/model/abstracttasksmodel.h
HEADERS += $$PWD/include/model/abstractcollaborationmodel.h
HEADERS += $$PWD/include/view/insertadditional.h
HEADERS += $$PWD/include/view/insertevent.h
HEADERS += $$PWD/include/view/eventswindow.h
HEADERS += $$PWD/include/view/practicewindow.h
HEADERS += $$PWD/include/model/abstractpracticemodel.h
HEADERS += $$PWD/include/view/searchstudents.h
HEADERS += $$PWD/include/model/abstractpassingpracticemodel.h
HEADERS += $$PWD/include/view/passingpracticewindow.h
HEADERS += $$PWD/include/view/searchstaffuniversity.h
HEADERS += $$PWD/include/view/searchheademployer.h
HEADERS += $$PWD/include/view/inserttaskpractice.h
HEADERS += $$PWD/include/model/abstractreportsmodel.h
HEADERS += $$PWD/include/view/reportwindow.h
HEADERS += $$PWD/include/view/reportpracticewindow.h
HEADERS += $$PWD/include/model/abstactsubclassmodel.h
HEADERS += $$PWD/include/view/authorizationwindow.h
HEADERS += $$PWD/include/view/adminwindow.h
HEADERS += $$PWD/include/view/insertuser.h
HEADERS += $$PWD/include/model/abstractusersmodel.h
HEADERS += $$PWD/include/model/checkauthorizationmodel.h
HEADERS += $$PWD/include/model/abstracteventsmodel.h
HEADERS += $$PWD/include/view/reporteventswindow.h
HEADERS += $$PWD/include/view/educationalprogramwindow.h
HEADERS += $$PWD/include/view/inserteducationalprogram.h
HEADERS += $$PWD/include/view/insertadditionaleducationalprogram.h
HEADERS += $$PWD/include/view/insertresultdiscipline.h
HEADERS += $$PWD/include/view/insertdiscipline.h



FORMS +=$$PWD/ui/studentswindow.ui
FORMS +=$$PWD/ui/insertstudent.ui
FORMS +=$$PWD/ui/insertgroup.ui
FORMS +=$$PWD/ui/mainwindow.ui
FORMS +=$$PWD/ui/staffuniversitywindow.ui
FORMS +=$$PWD/ui/insertstaffuniversity.ui
FORMS +=$$PWD/ui/insertdepartment.ui
FORMS +=$$PWD/ui/staffemployerwindow.ui
FORMS +=$$PWD/ui/insertstaffemployer.ui
FORMS +=$$PWD/ui/employerswindow.ui
FORMS +=$$PWD/ui/additionalwindow.ui
FORMS +=$$PWD/ui/insertadditional.ui
FORMS +=$$PWD/ui/insertevent.ui
FORMS +=$$PWD/ui/eventswindow.ui
FORMS +=$$PWD/ui/practicewindow.ui
FORMS +=$$PWD/ui/searchstudents.ui
FORMS +=$$PWD/ui/passingpracticewindow.ui
FORMS +=$$PWD/ui/searchstaffuniversity.ui
FORMS +=$$PWD/ui/searchheademployer.ui
FORMS +=$$PWD/ui/inserttaskpractice.ui
FORMS +=$$PWD/ui/reportwindow.ui
FORMS +=$$PWD/ui/reportpracticewindow.ui
FORMS +=$$PWD/ui/authorizationwindow.ui
FORMS +=$$PWD/ui/adminwindow.ui
FORMS +=$$PWD/ui/insertuser.ui
FORMS +=$$PWD/ui/reporteventswindow.ui
FORMS +=$$PWD/ui/educationalprogramwindow.ui
FORMS +=$$PWD/ui/inserteducationalprogram.ui
FORMS +=$$PWD/ui/insertadditionaleducationalprogram.ui
FORMS +=$$PWD/ui/insertresultdiscipline.ui
FORMS +=$$PWD/ui/insertdiscipline.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
RC_FILE = clientVKR.rc
RESOURCES +=

