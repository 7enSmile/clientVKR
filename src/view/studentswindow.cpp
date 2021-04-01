#include "view/studentswindow.h"
#include "ui_studentswindow.h"
#include "Person.h"
StudentsWindow::StudentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentsWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Студенты");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

}

StudentsWindow::~StudentsWindow()
{
    delete ui;
}
