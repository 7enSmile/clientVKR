#include "include/view/studentswindow.h"
#include "include/view/mainwindow.h"
#include "Result_education.h"
#include "include/precompiled.h"
#include <QtCore/qcoreapplication.h>
#include <QApplication>
#include "view/searchstudents.h"
#include "view/authorizationwindow.h"
void init();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AuthorizationWindow *w=new AuthorizationWindow();


    w->show();

    a.exec();



}
void init(){

}
