#include "view/employerswindow.h"
#include "ui_employerswindow.h"

EmployersWindow::EmployersWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployersWindow)
{
    ui->setupUi(this);
}

EmployersWindow::~EmployersWindow()
{
    delete ui;
}
