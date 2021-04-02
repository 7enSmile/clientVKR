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
    m_modelGroups=new AbstactGroupsModel();
    ui->tableViewGroups->setModel(m_modelGroups);
    ui->tableViewStudents->setModel(m_modelStudents);
    connect(ui->pushButtonDeleteStudent,SIGNAL(clicked()),this,SLOT(onDeleteStudentCliced()));
    connect(ui->pushButtonInsertStudent,SIGNAL(clicked()),this,SLOT(onInsertStudentCliced()));
    connect(ui->tableViewStudents,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableStudentCliced()));


}

StudentsWindow::~StudentsWindow()
{
    delete ui;
}

void StudentsWindow::onDeleteStudentCliced()
{
    QModelIndexList index = ui->tableViewStudents->selectionModel()->selectedRows();
    m_modelStudents->deleteStudent(index[0].row());
}

void StudentsWindow::onInsertStudentCliced()
{
    InsertStudent *insert=new InsertStudent();
    insert->setGroups(m_modelGroups->getList());
    if(insert->exec()==InsertStudent::Accepted){
       m_modelStudents->saveStudent(insert->getStudent());
    }

}

void StudentsWindow::onTableStudentCliced()
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
    }


}










