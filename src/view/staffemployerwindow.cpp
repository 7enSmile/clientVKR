#include "view/staffemployerwindow.h"
#include "ui_staffemployerwindow.h"

StaffEmployerWindow::StaffEmployerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffEmployerWindow)
{
    ui->setupUi(this);
    m_modelContactEmployer=new AbstractContactEmployerModel();
    m_modelHeadEmployer =new AbstractHeadEmployerModel();
    ui->tableViewContactEmployer->setModel(m_modelContactEmployer);
    ui->tableViewHeadEmployer->setModel(m_modelHeadEmployer);
    connect(ui->pushButtonDeleteHeadEmployer,SIGNAL(clicked()),this,SLOT(onDeleteHeadEmployerClicked()));
    connect(ui->pushButtonInsertHeadEmployer,SIGNAL(clicked()),this,SLOT(onInsertHeadEmployerClicked()));
    connect(ui->tableViewHeadEmployer,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableHeadEmployerClicked()));
    connect(ui->pushButtonInsertContactEmployer,SIGNAL(clicked()),this,SLOT(onInsertContactEmployerClicked()));
    connect(ui->pushButtonDeleteContactEmployer,SIGNAL(clicked()),this,SLOT(onDeleteContactEmployerClicked()));
    connect(ui->tableViewContactEmployer,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableContactEmployerClicked()));
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
}

StaffEmployerWindow::~StaffEmployerWindow()
{
    delete ui;
}

void StaffEmployerWindow::onDeleteHeadEmployer()
{

}

void StaffEmployerWindow::onInsertHeadEmployer()
{

}

void StaffEmployerWindow::onTableHeadEmployerClicked()
{

}

void StaffEmployerWindow::onDeleteContactEmployerClicket()
{

}

void StaffEmployerWindow::onInsertContactEmployerClicket()
{

}

void StaffEmployerWindow::onTableContactEmployerClicked()
{

}

void StaffEmployerWindow::onOkClicked()
{

}
