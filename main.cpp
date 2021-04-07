#include "include/view/studentswindow.h"
#include "include/view/mainwindow.h"
#include "Result_education.h"
#include "include/precompiled.h"
#include <QtCore/qcoreapplication.h>
#include <QApplication>
#include "view/searchstudents.h"
void init();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    init();
    MainWindow *w=new MainWindow();


    w->show();

    a.exec();



}
void init(){
    qx::QxSqlDatabase::getSingleton()->setDriverName("QPSQL");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("department");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("postgres");
    qx::QxSqlDatabase::getSingleton()->setPassword("hesoyam2012QWE");
    qx::QxSqlDatabase::getSingleton()->setVerifyOffsetRelation(true);
}
