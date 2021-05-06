#include "view/resultdisciplinewindow.h"
#include "ui_resultdisciplinewindow.h"

ResultDisciplineWindow::ResultDisciplineWindow(ListOfResultEducation list,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultDisciplineWindow)
{
    ui->setupUi(this);
    m_modelResult=new AbstractResultDisciplineModel(list);
    ui->tableViewResult->setModel(m_modelResult);
    connect(ui->tableViewResult,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableResultClicked()));
    connect(ui->pushButtonInsert,SIGNAL(clicked()),this,SLOT(onInsertClicked()));
    connect(ui->pushButtonDeleteEvent,SIGNAL(clicked()),this,SLOT(onDeleteclicked()));
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    this->setWindowTitle("Результат");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);


}

ResultDisciplineWindow::~ResultDisciplineWindow()
{
    delete ui;
}

ListOfResultEducation &ResultDisciplineWindow::getList()
{
    return m_modelResult->getListResult();
}

void ResultDisciplineWindow::onOkClicked()
{
    QDialog::close();

}

void ResultDisciplineWindow::onActionClicked()
{
    QDialog::accept();

}

void ResultDisciplineWindow::onInsertClicked()
{
    InsertResultDiscipline *w=new InsertResultDiscipline();
    if(w->exec()==QDialog::Accepted){

        m_modelResult->saveResultEducation(w->getResultDiscipline());

    }

}

void ResultDisciplineWindow::onTableResultClicked()
{
    QModelIndexList index = ui->tableViewResult->selectionModel()->selectedRows();
    InsertResultDiscipline *w=new InsertResultDiscipline(m_modelResult->getResultEducation(index[0].row()));
    if(w->exec()==QDialog::Accepted){

        //m_modelResult->saveResultEducation(w->getResultDiscipline());

    }
    ui->tableViewResult->clearSelection();
    ui->tableViewResult->clearFocus();

}

void ResultDisciplineWindow::onDeleteclicked()
{

    QModelIndexList index = ui->tableViewResult->selectionModel()->selectedRows();
    if(index.count()>0){
        m_modelResult->deleteResultEducation(index[0].row());
    }

}
