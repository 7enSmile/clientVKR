#################################################################################################
## File created by QxEntityEditor 1.2.6 (2021/03/24 12:12) : please, do NOT modify this file ! ##
#################################################################################################

!contains(DEFINES, _QX_NO_PRECOMPILED_HEADER) {
PRECOMPILED_HEADER += $$PWD/include/department_precompiled_header.h
} # !contains(DEFINES, _QX_NO_PRECOMPILED_HEADER)

HEADERS += $$PWD/include/department_precompiled_header.h
HEADERS += $$PWD/include/department_export.h

HEADERS += $$PWD/include/Activity.h
HEADERS += $$PWD/include/Collaboration.h
HEADERS += $$PWD/include/Employer.h
HEADERS += $$PWD/include/Task.h
HEADERS += $$PWD/include/Practice.h
HEADERS += $$PWD/include/Event.h
HEADERS += $$PWD/include/Person.h
HEADERS += $$PWD/include/Group.h
HEADERS += $$PWD/include/Student.h
HEADERS += $$PWD/include/Head_employer.h
HEADERS += $$PWD/include/Contact_employer.h
HEADERS += $$PWD/include/Head_university.h
HEADERS += $$PWD/include/Department.h
HEADERS += $$PWD/include/Passing_practice.h
HEADERS += $$PWD/include/Task_practice.h
HEADERS += $$PWD/include/Report.h
HEADERS += $$PWD/include/Practice_result.h
HEADERS += $$PWD/include/Discipline.h
HEADERS += $$PWD/include/Educational_program.h
HEADERS += $$PWD/include/Result_education.h
HEADERS += $$PWD/include/Test_practice.h


contains(DEFINES, _QX_UNITY_BUILD) {

SOURCES += $$PWD/src/department_all.cpp

} else {

SOURCES += $$PWD/src/Activity.cpp
SOURCES += $$PWD/src/Collaboration.cpp
SOURCES += $$PWD/src/Employer.cpp
SOURCES += $$PWD/src/Task.cpp
SOURCES += $$PWD/src/Practice.cpp
SOURCES += $$PWD/src/Event.cpp
SOURCES += $$PWD/src/Person.cpp
SOURCES += $$PWD/src/Group.cpp
SOURCES += $$PWD/src/Student.cpp
SOURCES += $$PWD/src/Head_employer.cpp
SOURCES += $$PWD/src/Contact_employer.cpp
SOURCES += $$PWD/src/Head_university.cpp
SOURCES += $$PWD/src/Department.cpp
SOURCES += $$PWD/src/Passing_practice.cpp
SOURCES += $$PWD/src/Task_practice.cpp
SOURCES += $$PWD/src/Report.cpp
SOURCES += $$PWD/src/Practice_result.cpp
SOURCES += $$PWD/src/Educational_program.cpp
SOURCES += $$PWD/src/Discipline.cpp
SOURCES += $$PWD/src/Result_education.cpp
SOURCES += $$PWD/src/Test_practice.cpp


} # contains(DEFINES, _QX_UNITY_BUILD)

include($$PWD/custom/department.pri)
