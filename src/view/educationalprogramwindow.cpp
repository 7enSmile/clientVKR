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
    connect(ui->tableViewEducationalPrograms,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableEducationProgramClicket()));
    connect(ui->pushButtonInsert,SIGNAL(clicked()),this,SLOT(onInsertClicket()));
}

EducationalProgramWindow::~EducationalProgramWindow()
{
    delete ui;
}

void EducationalProgramWindow::onDeleteClicket()

{

}

void EducationalProgramWindow::onInsertClicket()

{
    InsertEducationalProgram *w=new InsertEducationalProgram();
    if(w->exec()==QDialog::Accepted){

        m_modelEducationProgram->saveEducationalProgram(w->getEducationalProgram());
    }

}

void EducationalProgramWindow::onTableEducationProgramClicket()
{
    QModelIndexList index = ui->tableViewEducationalPrograms->selectionModel()->selectedRows();
    InsertEducationalProgram *w=new InsertEducationalProgram(m_modelEducationProgram->getEducationalProgram(index[0].row()));
    if(w->exec()==QDialog::Accepted){
        m_modelEducationProgram->saveEducationalProgram(w->getEducationalProgram());
    }


}

void EducationalProgramWindow::onOkCliced()
{
    QDialog::close();

}
