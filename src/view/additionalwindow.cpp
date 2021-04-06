#include "view/additionalwindow.h"
#include "ui_additionalwindow.h"

AdditionalWindow::AdditionalWindow(Employer_ptr employer,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdditionalWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Дополнительно");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    m_modelActivity=new AbstractActivityModel(employer->getlist_of_activity());
    m_modelCollaboration=new AbstractCollaborationModel(employer->getlist_of_collaboration());
    m_modelTask=new AbstractTasksModel(employer->getlist_of_task());
    ui->tableViewActivity->setModel(m_modelActivity);
    ui->tableViewTasks->setModel(m_modelTask);
    ui->tableViewCollaboration->setModel(m_modelCollaboration);
    connect(ui->tableViewActivity,SIGNAL(clicked(QModelIndex)),this,SLOT(onActivityTableClicked()));
    connect(ui->tableViewCollaboration,SIGNAL(clicked(QModelIndex)),this,SLOT(onCollaborationTableClicked()));
    connect(ui->tableViewTasks,SIGNAL(clicked(QModelIndex)),this,SLOT(onTasksTableClicked()));
    connect(ui->pushButtonInsertActitivity,SIGNAL(clicked()),this,SLOT(onInsertActivityClicked()));
    connect(ui->pushButtonInsertCollaboration,SIGNAL(clicked()),this,SLOT(onInsertCollaborationClicked()));
    connect(ui->pushButtonInsertTasks,SIGNAL(clicked()),this,SLOT(onInsertTasksClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->pushButtondeleteActivity,SIGNAL(clicked()),this,SLOT(onDeleteTasksClicked()));
    connect(ui->pushButtonDeleteTasks,SIGNAL(clicked()),this,SLOT(onDeleteTasksClicked()));
    connect(ui->pushButtonDeleteCollaboration,SIGNAL(clicked()),this,SLOT(onDeleteCollaborationClicked()));


}

AdditionalWindow::~AdditionalWindow()
{
    delete ui;
}

ListOfActivity AdditionalWindow::getListActivity()
{
    return m_modelActivity->getActivity();
}

ListOfTask AdditionalWindow::getListTasks()
{
    return m_modelTask->getTask();
}

ListOfCollaboration AdditionalWindow::getListCollaboration()
{
    return m_modelCollaboration->getCollaboration();

}



void AdditionalWindow::onActivityTableClicked()
{
    QModelIndexList index = ui->tableViewActivity->selectionModel()->selectedRows();
    m_modelActivity->action(index[0].row());

}

void AdditionalWindow::onCollaborationTableClicked()
{
    QModelIndexList index = ui->tableViewCollaboration->selectionModel()->selectedRows();
    m_modelCollaboration->action(index[0].row());

}

void AdditionalWindow::onTasksTableClicked()
{
    QModelIndexList index = ui->tableViewTasks->selectionModel()->selectedRows();
    m_modelTask->action(index[0].row());

}

void AdditionalWindow::onActionClicked()
{
    QDialog::accept();

}

void AdditionalWindow::onInsertActivityClicked()
{
   InsertAdditional *w=new InsertAdditional();
   if(w->exec()==QDialog::Accepted){
       m_modelActivity->insertGlobalActivity(w->getActivity());
   }

}

void AdditionalWindow::onInsertCollaborationClicked()
{
    InsertAdditional *w=new InsertAdditional();
    if(w->exec()==QDialog::Accepted){
        m_modelCollaboration->insertGlobalCollaboration(w->getCollaboration());
    }

}

void AdditionalWindow::onInsertTasksClicked()
{
    InsertAdditional *w=new InsertAdditional();
    if(w->exec()==QDialog::Accepted){
        m_modelTask->insertGlobalTask(w->getTask());
    }

}

void AdditionalWindow::onDeleteActivityClicked()
{
    QModelIndexList index = ui->tableViewActivity->selectionModel()->selectedRows();
    if(index.count()>0){
    m_modelActivity->deleteGlobal(index[0].row());
    }



}

void AdditionalWindow::onDeleteTasksClicked()
{
    QModelIndexList index = ui->tableViewTasks->selectionModel()->selectedRows();
    if(index.count()>0){
    m_modelTask->deleteGlobal(index[0].row());
    }

}

void AdditionalWindow::onDeleteCollaborationClicked()
{
    QModelIndexList index = ui->tableViewCollaboration->selectionModel()->selectedRows();
    if(index.count()>0){
    m_modelCollaboration->deleteGlobal(index[0].row());
    }

}

