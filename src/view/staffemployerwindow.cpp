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
    this->setWindowTitle("Работники предприятия");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
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

void StaffEmployerWindow::onDeleteHeadEmployerClicked()
{
    QModelIndexList index = ui->tableViewHeadEmployer->selectionModel()->selectedRows();
    if(index.count()>0){
    m_modelHeadEmployer->deleteHeadEmployerGlobal(index[0].row());
    QMessageBox::information(this,"Успех","Сотрудник удален!");
    }
    ui->tableViewHeadEmployer->clearSelection();
    ui->tableViewHeadEmployer->clearFocus();

}

void StaffEmployerWindow::onInsertHeadEmployerClicked()
{
    TypeInsert type;
    type=insertheademployer;
    InsertStaffEmployer *insert=new InsertStaffEmployer(type,m_modelHeadEmployer->m_listEmployers);

    if(insert->exec()==InsertStaffEmployer::Accepted){
       m_modelHeadEmployer->saveHeadEmployerGlobal(insert->getHeadEmployer());
       QMessageBox::information(this,"Успех","Сотрудник добавлен!");
    }
    ui->tableViewHeadEmployer->clearSelection();
    ui->tableViewHeadEmployer->clearFocus();


}

void StaffEmployerWindow::onTableHeadEmployerClicked()
{
    TypeInsert type;
    type=insertheademployer;
    HeadEmployer_ptr headEmployer;
    headEmployer.reset(new HeadEmployer());
    QModelIndexList index = ui->tableViewHeadEmployer->selectionModel()->selectedRows();
    headEmployer=m_modelHeadEmployer->getHeadEmployer(index[0].row());
    InsertStaffEmployer *insert=new InsertStaffEmployer(type,m_modelHeadEmployer->m_listEmployers);
    insert->insertHeadEmployer(headEmployer);
    if(insert->exec()==InsertStaffEmployer::Accepted){
       m_modelHeadEmployer->saveHeadEmployerGlobal(insert->getHeadEmployer());
       QMessageBox::information(this,"Успех","Изменения внесены!");
    }
    ui->tableViewHeadEmployer->clearSelection();
    ui->tableViewHeadEmployer->clearFocus();

}

void StaffEmployerWindow::onDeleteContactEmployerClicked()
{
    QModelIndexList index = ui->tableViewContactEmployer->selectionModel()->selectedRows();
    if(index.count()>0){
    m_modelContactEmployer->deleteContactEmployerGlobal(index[0].row());
    QMessageBox::information(this,"Успех","Сотрудник удален!");
    }
    ui->tableViewContactEmployer->clearSelection();
    ui->tableViewContactEmployer->clearFocus();

}

void StaffEmployerWindow::onInsertContactEmployerClicked()
{
    TypeInsert type;
    type=insertcontactemployer;
    InsertStaffEmployer *insert=new InsertStaffEmployer(type,m_modelContactEmployer->m_listEmployers);

    if(insert->exec()==InsertStaffEmployer::Accepted){
       m_modelContactEmployer->saveContactEmployerGlobal(insert->getContactEmployer());
       QMessageBox::information(this,"Успех","Сотрудник добавлен!");
    }
    ui->tableViewContactEmployer->clearSelection();
    ui->tableViewContactEmployer->clearFocus();



}

void StaffEmployerWindow::onTableContactEmployerClicked()
{
    TypeInsert type;
    type=insertcontactemployer;
    ContactEmployer_ptr contactEmployer;
    contactEmployer.reset(new ContactEmployer());
    QModelIndexList index = ui->tableViewContactEmployer->selectionModel()->selectedRows();
    contactEmployer=m_modelContactEmployer->getContactEmployer(index[0].row());
    InsertStaffEmployer *insert=new InsertStaffEmployer(type,m_modelContactEmployer->m_listEmployers);
    insert->insertContactEmplyer(contactEmployer);
    if(insert->exec()==InsertStaffEmployer::Accepted){
       m_modelContactEmployer->saveContactEmployerGlobal(insert->getContactEmployer());
       QMessageBox::information(this,"Успех","Изменения внесены!");
    }
    ui->tableViewContactEmployer->clearSelection();
    ui->tableViewContactEmployer->clearFocus();

}

void StaffEmployerWindow::onOkClicked()
{
    QDialog::accept();

}
