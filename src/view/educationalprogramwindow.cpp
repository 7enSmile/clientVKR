#include "view/educationalprogramwindow.h"
#include "ui_educationalprogramwindow.h"

EducationalProgramWindow::EducationalProgramWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EducationalProgramWindow)
{
    ui->setupUi(this);
}

EducationalProgramWindow::~EducationalProgramWindow()
{
    delete ui;
}
