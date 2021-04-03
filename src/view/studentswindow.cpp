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


}

StudentsWindow::~StudentsWindow()
{
    delete ui;
}

void StudentsWindow::onDeleteStudentClicked()
{
    QModelIndexList index = ui->tableViewStudents->selectionModel()->selectedRows();
    m_modelStudents->deleteStudent(index[0].row());
    QMessageBox::information(this,"Успех","Студент удален!");

}

void StudentsWindow::onInsertStudentClicked()
{
    InsertStudent *insert=new InsertStudent();
    insert->setGroups(m_modelGroups->getList());
    if(insert->exec()==InsertStudent::Accepted){
       m_modelStudents->saveStudent(insert->getStudent());
       QMessageBox::information(this,"Успех","Студент добавлен!");
    }

}

void StudentsWindow::onTableStudentClicked()
{
    Student_ptr student;
    student.reset(new Student());
    QModelIndexList index = ui->tableViewStudents->selectionModel()->selectedRows();
    student=m_modelStudents->getStudent(index[0].row());
    InsertStudent *insert=new InsertStudent();
    insert->setGroups(m_modelGroups->getList());
    insert->insert(student);
    if(insert->exec()==InsertStudent::Accepted){
       m_modelStudents->saveStudent(insert->getStudent());
       QMessageBox::information(this,"Успех","Изменения внесены!");
    }



}

void StudentsWindow::onDeleteGroupClicked()
{
    QModelIndexList index = ui->tableViewGroups->selectionModel()->selectedRows();
    m_modelGroups->deleteGroup(index[0].row());
    QMessageBox::information(this,"Успех","Группа удалена!");
    m_modelStudents->loadList();

}

void StudentsWindow::onInsertGroupClicked()
{
    InsertGroup *insert=new InsertGroup();

    if(insert->exec()==InsertGroup::Accepted){
       m_modelGroups->saveGroup(insert->getGroup());
       QMessageBox::information(this,"Успех","Группа добавлена!");
    }
    m_modelStudents->loadList();

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
   m_modelStudents->loadList();

}

void StudentsWindow::onOkClicked()
{
    QDialog::close();

}










