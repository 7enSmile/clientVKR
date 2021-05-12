#include "view/insertadditionaleducationalprogram.h"
#include "ui_insertadditionaleducationalprogram.h"

InsertAdditionalEducationalProgram::InsertAdditionalEducationalProgram(ListOfDiscipline listDiscipline,ListOfPractice listPractice,ListOfStudent listStudent,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertAdditionalEducationalProgram)
{
    ui->setupUi(this);
    m_modelDescipline=new AbstractDisciplineModel(listDiscipline);
    m_modelPractice=new AbstractPracticeModel(listPractice);
    ui->tableViewDiscipline->setModel(m_modelDescipline);
    ui->tableViewPractice->setModel(m_modelPractice);
    ui->tableViewPractice->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->tableViewDiscipline,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableDisciplineClicked()));
    connect(ui->pushButtonInsertDiscipline,SIGNAL(clicked()),this,SLOT(onInsertDisciplineClicked()));
    connect(ui->pushButtonInsertPractice,SIGNAL(clicked()),this,SLOT(onInsertPracticeClicked()));
    connect(ui->pushButtonDeleteDiscipline,SIGNAL(clicked()),this,SLOT(onDeleteDisciplineClicked()));
    connect(ui->pushButtonDeletePractice,SIGNAL(clicked()),this,SLOT(onDeletePracticeClicked()));
    this->setWindowTitle("Дополнительно");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

InsertAdditionalEducationalProgram::~InsertAdditionalEducationalProgram()
{
    delete ui;
}

ListOfDiscipline &InsertAdditionalEducationalProgram::getListDiscipline()
{
    return m_modelDescipline->getListDiscipline();

}

ListOfPractice &InsertAdditionalEducationalProgram::getListPractice()
{
    return m_modelPractice->getList();

}

void InsertAdditionalEducationalProgram::onActionClicked()
{
    QDialog::accept();

}

void InsertAdditionalEducationalProgram::onOkClicked()
{
    QDialog::close();

}

void InsertAdditionalEducationalProgram::onInsertDisciplineClicked()

{
    InsertDiscipline *w=new InsertDiscipline();
    if(w->exec()==QDialog::Accepted){

        m_modelDescipline->saveDiscipline(w->getDiscipline());
    }


}

void InsertAdditionalEducationalProgram::onDeleteDisciplineClicked()
{
    QModelIndexList index = ui->tableViewDiscipline->selectionModel()->selectedRows();
    if(index.count()>0){
        m_modelDescipline->deleteDiscipline(index[0].row());
    }
    ui->tableViewDiscipline->clearSelection();
    ui->tableViewDiscipline->clearFocus();


}

void InsertAdditionalEducationalProgram::onTableDisciplineClicked()
{
    QModelIndexList index = ui->tableViewDiscipline->selectionModel()->selectedRows();
    InsertDiscipline *w=new InsertDiscipline(m_modelDescipline->getDiscipline(index[0].row()));
    w->exec();
    ui->tableViewDiscipline->clearSelection();
    ui->tableViewDiscipline->clearFocus();
}

void InsertAdditionalEducationalProgram::onInsertPracticeClicked()
{

    SearchPractice *w=new SearchPractice(m_modelPractice->getList());
    if(w->exec()==QDialog::Accepted){

        ListOfPractice list;
        list=w->getList();
        for(int i=0;i<list.count();i++){
            m_modelPractice->savePracticeLocal(list.getByIndex(i));
        }
    }

}

void InsertAdditionalEducationalProgram::onDeletePracticeClicked()
{
    QModelIndexList index = ui->tableViewPractice->selectionModel()->selectedRows();
    if(index.count()>0){

        m_modelPractice->deleteEducationProgram(index[0].row());
    }
    ui->tableViewPractice->clearSelection();
    ui->tableViewPractice->clearFocus();

}
