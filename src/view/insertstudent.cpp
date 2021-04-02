#include "view/insertstudent.h"
#include "ui_insertstudent.h"

InsertStudent::InsertStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertStudent)
{
    ui->setupUi(this);
    m_student.reset(new Student());
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionCliced()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onOkCliced()));
    this->setWindowTitle("Создать студена");
    ui->pushButtonAction->setText("Добавить");
    ui->pushButton->setText("Отмена");


}

InsertStudent::~InsertStudent()
{
    delete ui;
}

void InsertStudent::setGroups(ListOfGroup &list)
{
    m_listGroups=list;
    fillComboBox();
}



void InsertStudent::insert(Student_ptr &student)
{
    m_student=student;
    ui->lineEditFirstname->setText(m_student->getperson()->getfirstname());
    ui->lineEditLastname->setText(m_student->getperson()->getlastname());
    ui->lineEditPatronymic->setText(m_student->getperson()->getpatronymic());
    ui->lineEditEmail->setText(m_student->getperson()->getemail());
    qDebug()<<m_student->getperson()->getphone_number();
    ui->lineEditPhone->setText(m_student->getperson()->getphone_number());
    this->setWindowTitle("Изменить студента");
    ui->pushButtonAction->setText("Изменить");
    ui->pushButton->setText("Ок");
    ui->comboBoxGrops->setCurrentText(m_student->getgroup()->getnumber());


}

Student_ptr &InsertStudent::getStudent()
{
    return m_student;
}

void InsertStudent::onActionCliced()
{
    qDebug()<<"TEst";
    Person_ptr person;
    person.reset(new Person());
    if(m_student->getperson()!=nullptr){
    person=m_student->getperson();
    }

    person->setfirstname(ui->lineEditFirstname->text());
    person->setlastname(ui->lineEditLastname->text());
    person->setpatronymic(ui->lineEditPatronymic->text());
    person->setphone_number(ui->lineEditPhone->text());
    person->setemail(ui->lineEditEmail->text());
    m_student->setperson(person);
    m_student->setgroup(m_listGroups.getByIndex(ui->comboBoxGrops->currentIndex()));
    QDialog::accept();
}

void InsertStudent::onOkCliced()
{
    QDialog::close();
}

void InsertStudent::fillComboBox()
{
    qDebug()<<m_listGroups.count();

    for(int i=0;i<m_listGroups.count();i++){
        ui->comboBoxGrops->addItem(m_listGroups.getByIndex(i)->getnumber());
    }
}
