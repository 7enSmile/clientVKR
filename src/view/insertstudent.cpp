#include "view/insertstudent.h"
#include "ui_insertstudent.h"

InsertStudent::InsertStudent(ListOfGroup &list,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertStudent)
{
    ui->setupUi(this);
    m_student.reset(new Student());
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Студент");
    ui->pushButtonAction->setText("Добавить");
    ui->pushButton->setText("Отмена");
    m_listGroups=list;
    m_modelEducationalProgram =new AbstractEducationalProgramModel();
    fillComboBox();


}

InsertStudent::~InsertStudent()
{
    delete ui;
}





void InsertStudent::insert(Student_ptr &student)
{
    m_student=student;
    initInsert();
}

Student_ptr &InsertStudent::getStudent()
{
    return m_student;

}

void InsertStudent::onActionClicked()
{

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
    if(ui->comboBoxEducationProgram->currentIndex()!=-1){

        m_student->seteducation_program(m_modelEducationalProgram->getEducationalProgram(ui->comboBoxEducationProgram->currentIndex()));
    }
    if(ui->comboBoxGrops->currentIndex()!=-1){

        m_student->setgroup(m_listGroups.getByIndex(ui->comboBoxGrops->currentIndex()));

    }

    if(!person->getfirstname().isEmpty()&&!person->getlastname().isEmpty()&&!person->getpatronymic().isEmpty()&&!person->getphone_number().isEmpty()&&!person->getemail().isEmpty()){

        QDialog::accept();
    }

    else{

        QMessageBox::critical(this,"Ошибка!","Введенно пустое поле!");
    }
}

void InsertStudent::onOkClicked()
{
    QDialog::close();
}

void InsertStudent::fillComboBox()
{

    ListOfEducationalProgram listEducationProgram;
    listEducationProgram=m_modelEducationalProgram->getList();

    for(int i=0;i<listEducationProgram.count();i++){
        ui->comboBoxEducationProgram->addItem(listEducationProgram.getByIndex(i)->getname());
    }


    for(int i=0;i<m_listGroups.count();i++){
        ui->comboBoxGrops->addItem(m_listGroups.getByIndex(i)->getnumber());
    }
}

void InsertStudent::initInsert()
{
    ui->lineEditFirstname->setText(m_student->getperson()->getfirstname());
    ui->lineEditLastname->setText(m_student->getperson()->getlastname());
    ui->lineEditPatronymic->setText(m_student->getperson()->getpatronymic());
    ui->lineEditEmail->setText(m_student->getperson()->getemail());
    ui->lineEditPhone->setText(m_student->getperson()->getphone_number());
    this->setWindowTitle("Студент");
    ui->pushButtonAction->setText("Изменить");
    ui->pushButton->setText("Ок");
    if(m_student->getgroup()!=nullptr){
        ui->comboBoxGrops->setCurrentText((m_student->getgroup()->getnumber()));

    }else{
        ui->comboBoxGrops->setCurrentIndex(-1);
    }

    if(m_student->geteducation_program()!=nullptr){

        ui->comboBoxEducationProgram->setCurrentText(m_student->geteducation_program()->getname());


    }else{

        ui->comboBoxEducationProgram->setCurrentIndex(-1);
    }
}
