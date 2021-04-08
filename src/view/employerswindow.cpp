#include "view/employerswindow.h"
#include "ui_employerswindow.h"

EmployersWindow::EmployersWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployersWindow)
{

    ui->setupUi(this);
    initConnection();
    m_employer.reset(new Employer());
    m_modelHeadEmployerModel=new AbstractHeadEmployerModel(m_employer->getlist_of_head_employer());
    m_modelContactemployer=new AbstractContactEmployerModel(m_employer->getlist_of_contact_employer());
    ui->tableViewHeadEmployer->setModel(m_modelHeadEmployerModel);
    ui->tableViewContactEmployer->setModel(m_modelContactemployer);
    ui->lineEditName->setText(m_employer->getname());
    ui->pushButtonAction->setText("Добавить");
    ui->pushButtonOk->setText("Отмена");
}

EmployersWindow::EmployersWindow(Employer_ptr employer,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployersWindow)
{

    ui->setupUi(this);
    initConnection();

    m_employer.reset(new Employer());
    m_employer=employer;
    m_modelHeadEmployerModel=new AbstractHeadEmployerModel(employer->getlist_of_head_employer());
    m_modelContactemployer=new AbstractContactEmployerModel(employer->getlist_of_contact_employer());
    ui->tableViewHeadEmployer->setModel(m_modelHeadEmployerModel);
    ui->tableViewContactEmployer->setModel(m_modelContactemployer);
    ui->lineEditName->setText(m_employer->getname());


}

EmployersWindow::~EmployersWindow()
{
    delete ui;
}

Employer_ptr EmployersWindow::getEmployer()
{
    m_employer->setname(ui->lineEditName->text());
    return m_employer;

}

void EmployersWindow::initConnection()
{
    this->setWindowTitle("Работодатель");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(ui->pushButtonInsertHeadEmployer,SIGNAL(clicked()),this,SLOT(onInsertHeadEmployerClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->pushButtonDeleteHeadEmployer,SIGNAL(clicked()),this,SLOT(onDeleteHeadEmployerClicked()));
    connect(ui->tableViewHeadEmployer,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableHeadEmployerClicked()));
    connect(ui->pushButtonInsertContactEmployer,SIGNAL(clicked()),this,SLOT(onInsertContactEmployerClicked()));
    connect(ui->pushButtonDeleteContacrEmployer,SIGNAL(clicked()),this,SLOT(onDeleteContactClicked()));
    connect(ui->tableViewContactEmployer,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableContactClicked()));
    connect(ui->pushButtonAdditional,SIGNAL(clicked()),this,SLOT(onAdditionalClicked()));
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicket()));


}

void EmployersWindow::onInsertHeadEmployerClicked()
{
    TypeInsert type;
    type=insertheademployer;
    InsertStaffEmployer *w =new InsertStaffEmployer(type,m_employer);
    if(w->exec()==QDialog::Accepted){
        m_modelHeadEmployerModel->saveHeadEmployerLocal(w->getHeadEmployer());
    }
    m_employer->setlist_of_head_employer(m_modelHeadEmployerModel->getListHeadEmployer());

}

void EmployersWindow::onActionClicked()
{
    QDialog::accept();

}

void EmployersWindow::onInsertContactEmployerClicked()
{
    TypeInsert type;
    type=insertcontactemployer;
    InsertStaffEmployer *w =new InsertStaffEmployer(type,m_employer);
    if(w->exec()==QDialog::Accepted){
        m_modelContactemployer->saveContactEmployerLocal(w->getContactEmployer());
    }
    m_employer->setlist_of_contact_employer(m_modelContactemployer->getListContactEmployer());

}

void EmployersWindow::onTableContactClicked()
{
    TypeInsert type;
    type=insertcontactemployer;
    ContactEmployer_ptr contactEmployer;
    contactEmployer.reset(new ContactEmployer());
    QModelIndexList index = ui->tableViewContactEmployer->selectionModel()->selectedRows();
    contactEmployer=m_modelContactemployer->getContactEmployer(index[0].row());
    InsertStaffEmployer *w =new InsertStaffEmployer(type,m_employer);
    w->insertContactEmplyer(contactEmployer);
    if(w->exec()==QDialog::Accepted){
        //m_modelContactemployer->changeContactEmployerLocal(index[0].row(),w->getContactEmployer()->getcontact_employer_id(),w->getContactEmployer());
    }
    m_employer->setlist_of_contact_employer(m_modelContactemployer->getListContactEmployer());
    ui->tableViewContactEmployer->clearSelection();
    ui->tableViewContactEmployer->clearFocus();

}

void EmployersWindow::onDeleteContactClicked()
{
    QModelIndexList index = ui->tableViewContactEmployer->selectionModel()->selectedRows();
    if(index.count()>0){
        m_modelContactemployer->deleteContactEmployerLocal(index[0].row());
    }
    m_employer->setlist_of_contact_employer(m_modelContactemployer->getListContactEmployer());
    ui->tableViewContactEmployer->clearSelection();
    ui->tableViewContactEmployer->clearFocus();


}

void EmployersWindow::onAdditionalClicked()
{
    AdditionalWindow *w=new AdditionalWindow(m_employer);
    if(w->exec()==QDialog::Accepted){

        m_employer->setlist_of_activity(w->getListActivity());
        m_employer->setlist_of_collaboration(w->getListCollaboration());
        m_employer->setlist_of_task(w->getListTasks());

    }
    m_employer->setlist_of_activity(w->getListActivity());
    m_employer->setlist_of_collaboration(w->getListCollaboration());
    m_employer->setlist_of_task(w->getListTasks());

}

void EmployersWindow::onOkClicket()
{
    QDialog::close();

}

void EmployersWindow::onTableHeadEmployerClicked()
{
    TypeInsert type;
    type=insertheademployer;
    HeadEmployer_ptr headEmployer;
    headEmployer.reset(new HeadEmployer());
    QModelIndexList index = ui->tableViewHeadEmployer->selectionModel()->selectedRows();
    headEmployer=m_modelHeadEmployerModel->getHeadEmployer(index[0].row());
    InsertStaffEmployer *insert=new InsertStaffEmployer(type,m_employer);
    insert->insertHeadEmployer(headEmployer);
    if(insert->exec()==InsertStaffEmployer::Accepted){
        //m_modelHeadEmployerModel->changeHeadEmployerLocal(index[0].row(),headEmployer->getHeadEmployer(),insert->getHeadEmployer());
    }
    m_employer->setlist_of_head_employer(m_modelHeadEmployerModel->getListHeadEmployer());
    ui->tableViewHeadEmployer->clearSelection();
    ui->tableViewHeadEmployer->clearFocus();

}

void EmployersWindow::onDeleteHeadEmployerClicked()
{
    QModelIndexList index = ui->tableViewHeadEmployer->selectionModel()->selectedRows();
    if(index.count()>0){
        m_modelHeadEmployerModel->deleteHeadEmployerLocal(index[0].row());
    }
    m_employer->setlist_of_head_employer(m_modelHeadEmployerModel->getListHeadEmployer());
    ui->tableViewHeadEmployer->clearSelection();
    ui->tableViewHeadEmployer->clearFocus();

}

