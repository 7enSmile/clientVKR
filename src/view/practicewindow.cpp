#include "view/practicewindow.h"
#include "ui_practicewindow.h"

PracticeWindow::PracticeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PracticeWindow)
{
    ui->setupUi(this);
}

PracticeWindow::~PracticeWindow()
{
    delete ui;
}
