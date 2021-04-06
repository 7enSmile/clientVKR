#include "view/employerswindow.h"
#include "ui_employerswindow.h"

EmployersWindow::EmployersWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployersWindow)
{
    ui->setupUi(this);
}

EmployersWindow::EmployersWindow(Employer_ptr employer,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployersWindow)
{
    ui->setupUi(this);
    m_employer.reset(new Employer());
    m_employer=employer;
    m_modelHeadEmployerModel=new AbstractHeadEmployerModel(employer->getlist_of_head_employer());
    m_modelContactemployer=new AbstractContactEmployerModel(employer->getlist_of_contact_employer());
    ui->tableViewHeadEmployer->setModel(m_modelHeadEmployerModel);
    ui->tableViewContactEmployer->setModel(m_modelContactemployer);

}

EmployersWindow::~EmployersWindow()
{
    delete ui;
}
