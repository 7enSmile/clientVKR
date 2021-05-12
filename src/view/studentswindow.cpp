#include "view/studentswindow.h"
#include "ui_studentswindow.h"
#include "Person.h"
#include "model/abstractstudentsmodel.h"
#include <QDebug>

StudentsWindow::StudentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentsWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Студенты");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    m_modelStudents=new AbstractStudentsModel();
    m_modelGroups=new AbstractGroupsModel();
    ui->tableViewGroups->setModel(m_modelGroups);
    ui->tableViewStudents->setModel(m_modelStudents);
    connect(ui->pushButtonDeleteStudent,SIGNAL(clicked()),this,SLOT(onDeleteStudentClicked()));
    connect(ui->pushButtonInsertStudent,SIGNAL(clicked()),this,SLOT(onInsertStudentClicked()));
    connect(ui->tableViewStudents,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableStudentClicked()));
    connect(ui->pushButtonInsertGroup,SIGNAL(clicked()),this,SLOT(onInsertGroupClicked()));
    connect(ui->pushButtonDeleteGroup,SIGNAL(clicked()),this,SLOT(onDeleteGroupClicked()));
    connect(ui->tableViewGroups,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableGroupClicked()));
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonLoadLIst,SIGNAL(clicked()),this,SLOT(onloadListClicked()));


}

StudentsWindow::~StudentsWindow()
{
    delete ui;
}

void StudentsWindow::onDeleteStudentClicked()
{
    QModelIndexList index = ui->tableViewStudents->selectionModel()->selectedRows();
    m_modelStudents->deleteStudentGlobal(index[0].row());
    QMessageBox::information(this,"Успех","Студент удален!");
    ui->tableViewStudents->clearSelection();
    ui->tableViewStudents->clearFocus();

}

void StudentsWindow::onInsertStudentClicked()
{
    InsertStudent *insert=new InsertStudent(m_modelGroups->getList());
    if(insert->exec()==InsertStudent::Accepted){
        m_modelStudents->saveStudentGlobal(insert->getStudent());
        QMessageBox::information(this,"Успех","Студент добавлен!");
    }
    ui->tableViewStudents->clearSelection();
    ui->tableViewStudents->clearFocus();

}

void StudentsWindow::onTableStudentClicked()
{
    Student_ptr student;
    student.reset(new Student());
    QModelIndexList index = ui->tableViewStudents->selectionModel()->selectedRows();
    student=m_modelStudents->getStudent(index[0].row());
    InsertStudent *insert=new InsertStudent(m_modelGroups->getList());
    insert->insert(student);
    if(insert->exec()==InsertStudent::Accepted){
        m_modelStudents->saveStudentGlobal(insert->getStudent());
        QMessageBox::information(this,"Успех","Изменения внесены!");
    }
    ui->tableViewStudents->clearSelection();
    ui->tableViewStudents->clearFocus();



}

void StudentsWindow::onDeleteGroupClicked()
{
    QModelIndexList index = ui->tableViewGroups->selectionModel()->selectedRows();
    m_modelGroups->deleteGroup(index[0].row());
    QMessageBox::information(this,"Успех","Группа удалена!");
    m_modelStudents->loadListGlobal();
    ui->tableViewGroups->clearSelection();
    ui->tableViewGroups->clearFocus();

}

void StudentsWindow::onInsertGroupClicked()
{
    InsertGroup *insert=new InsertGroup();

    if(insert->exec()==InsertGroup::Accepted){
        m_modelGroups->saveGroup(insert->getGroup());
        QMessageBox::information(this,"Успех","Группа добавлена!");
    }
    m_modelStudents->loadListGlobal();
    ui->tableViewGroups->clearSelection();
    ui->tableViewGroups->clearFocus();

}

void StudentsWindow::onTableGroupClicked()
{
    Group_ptr group;
    group.reset(new Group());
    QModelIndexList index = ui->tableViewGroups->selectionModel()->selectedRows();
    group=m_modelGroups->getGroup(index[0].row());
    InsertGroup *insert=new InsertGroup();
    insert->insert(group);
    if(insert->exec()==InsertGroup::Accepted){
        m_modelGroups->saveGroup(insert->getGroup());
        QMessageBox::information(this,"Успех","Изменения внесены!");
    }
    m_modelStudents->loadListGlobal();
    ui->tableViewGroups->clearSelection();
    ui->tableViewGroups->clearFocus();

}

void StudentsWindow::onOkClicked()
{
    QDialog::accept();

}

void StudentsWindow::onloadListClicked()
{
    int count;
    QInputDialog qDialog (this);

    QStringList items;
    items<<QString(";");
    items<<QString(",");

    qDialog.setOptions(QInputDialog::UseListViewForComboBoxItems);
    qDialog.setComboBoxItems(items);
    qDialog.setWindowFlags(qDialog.windowFlags() & ~Qt::WindowContextHelpButtonHint);
    qDialog.setLabelText("Выбирите разделитель");
    qDialog.setWindowTitle("Раздителель");

    if(qDialog.exec()==QDialog::Accepted){

        QString fileName = QFileDialog::getOpenFileName(this, "Зазгрузить", QStandardPaths::writableLocation(QStandardPaths::HomeLocation), QFileDialog::tr(" (*.csv)"));
        count=m_modelStudents->creatFromFile(fileName,qDialog.textValue());
        QMessageBox::information(this,"Инормация","Было импортировано "+QString::number(count)+" записей");
        m_modelGroups->loadList();

    }


}










