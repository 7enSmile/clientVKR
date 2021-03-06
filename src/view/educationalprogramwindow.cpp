#include "view/educationalprogramwindow.h"
#include "ui_educationalprogramwindow.h"

EducationalProgramWindow::EducationalProgramWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EducationalProgramWindow)
{
    ui->setupUi(this);
    m_modelEducationProgram =new AbstractEducationalProgramModel();
    ui->tableViewEducationalPrograms->setModel(m_modelEducationProgram);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Образовательные программы");
    connect(ui->tableViewEducationalPrograms,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableEducationProgramClicked()));
    connect(ui->pushButtonInsert,SIGNAL(clicked()),this,SLOT(onInsertClicked()));
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkCliced()));
    connect(ui->pushButtonDeleteEducationProgram,SIGNAL(clicked()),this,SLOT(onDeleteEducationProgramClicked()));
}

EducationalProgramWindow::~EducationalProgramWindow()
{
    delete ui;
}

void EducationalProgramWindow::onDeleteClicked()

{

}

void EducationalProgramWindow::onInsertClicked()

{
    InsertEducationalProgram *w=new InsertEducationalProgram();
    if(w->exec()==QDialog::Accepted){

        m_modelEducationProgram->saveEducationalProgram(w->getEducationalProgram());
    }

}

void EducationalProgramWindow::onTableEducationProgramClicked()
{
    QModelIndexList index = ui->tableViewEducationalPrograms->selectionModel()->selectedRows();
    InsertEducationalProgram *w=new InsertEducationalProgram(m_modelEducationProgram->getEducationalProgram(index[0].row()));
    if(w->exec()==QDialog::Accepted){
        m_modelEducationProgram->saveEducationalProgram(w->getEducationalProgram());
    }
    ui->tableViewEducationalPrograms->clearSelection();
    ui->tableViewEducationalPrograms->clearFocus();


}

void EducationalProgramWindow::onOkCliced()
{
    QDialog::close();

}

void EducationalProgramWindow::onDeleteEducationProgramClicked()
{
    QModelIndexList index = ui->tableViewEducationalPrograms->selectionModel()->selectedRows();
    if(index.count()!=0){

        m_modelEducationProgram->deleteEducationalProgram(index[0].row());

    }


}
