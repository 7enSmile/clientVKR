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
    ui->tableViewPractice->setColumnWidth(0,150);
    ui->tableViewPractice->setColumnWidth(1,130);

    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->tableViewDiscipline,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableDisciplineClicked()));
    connect(ui->pushButtonInsertDiscipline,SIGNAL(clicked()),this,SLOT(onInsertDisciplineClicked()));
    connect(ui->pushButtonInsertPractice,SIGNAL(clicked()),this,SLOT(onInsertPracticeClicked()));
    connect(ui->pushButtonDeleteDiscipline,SIGNAL(clicked()),this,SLOT(onDeleteDisciplineClicked()));
    connect(ui->pushButtonDeletePractice,SIGNAL(clicked()),this,SLOT(onDeletePracticeClicked()));
    connect(ui->tableViewPractice,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTablePracticeClicked()));
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
        statusDelete=true;
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
        statusDelete=true;

    }
    ui->tableViewPractice->clearSelection();
    ui->tableViewPractice->clearFocus();

}

void InsertAdditionalEducationalProgram::onTablePracticeClicked()
{
    QModelIndexList index = ui->tableViewPractice->selectionModel()->selectedRows();
    QInputDialog qDialog (this);

    QStringList items;
    for(int i=1;i<=10;i++){
        items<<QString::number(i);
    }

    qDialog.setOptions(QInputDialog::UseListViewForComboBoxItems);
    qDialog.setComboBoxItems(items);
    qDialog.setWindowFlags(qDialog.windowFlags() & ~Qt::WindowContextHelpButtonHint);
    qDialog.setLabelText("Выбирите семестр");
    qDialog.setTextValue(QString::number(m_modelPractice->getPractice(index[0].row())->getsemester()));
    qDialog.setWindowTitle("Семестр");

    if(qDialog.exec()==QDialog::Accepted){

        m_modelPractice->setSemester(index[0].row(),qDialog.textValue().toInt());
    }

}
