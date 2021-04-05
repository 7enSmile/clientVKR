#include "view/insertstaffuniversity.h"
#include "ui_insertstaffuniversity.h"

InsertStaffUniversity::InsertStaffUniversity(ListOfDepartment &list,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertStaffUniversity)
{
    ui->setupUi(this);
    m_staff.reset(new HeadUniversity());
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("СоздатьРаботника университета");
    ui->pushButtonAction->setText("Добавить");
    ui->pushButton->setText("Отмена");
    m_listDepartmens=list;
    fillComboBox();

}

InsertStaffUniversity::~InsertStaffUniversity()
{
    delete ui;
}



void InsertStaffUniversity::insert(HeadUniversity_ptr &staff)
{
    m_staff=staff;
    initInsert();

}

HeadUniversity_ptr &InsertStaffUniversity::getStaffUniversity()
{
    return m_staff;

}

void InsertStaffUniversity::onActionClicked()
{
    Person_ptr person;
    person.reset(new Person());
    if(m_staff->getperson()!=nullptr){
        person=m_staff->getperson();
    }

    person->setfirstname(ui->lineEditFirstname->text());
    person->setlastname(ui->lineEditLastname->text());
    person->setpatronymic(ui->lineEditPatronymic->text());
    person->setphone_number(ui->lineEditPhone->text());
    person->setemail(ui->lineEditEmail->text());
    m_staff->setperson(person);

    m_staff->setdepartment(m_listDepartmens.getByIndex(ui->comboBoxGrops->currentIndex()));

    if(!person->getfirstname().isEmpty()&&!person->getlastname().isEmpty()&&!person->getpatronymic().isEmpty()&&!person->getphone_number().isEmpty()&&!person->getemail().isEmpty()){

        QDialog::accept();
    }

    else{

        QMessageBox::critical(this,"Ошибка!","Введенно пустое поле!");
    }

}

void InsertStaffUniversity::onOkClicked()
{

    QDialog::close();
}

void InsertStaffUniversity::fillComboBox()
{
    for(int i=0;i<m_listDepartmens.count();i++){
        ui->comboBoxGrops->addItem(m_listDepartmens.getByIndex(i)->getname());
    }

}

void InsertStaffUniversity::initInsert()
{
    ui->lineEditFirstname->setText(m_staff->getperson()->getfirstname());
    ui->lineEditLastname->setText(m_staff->getperson()->getlastname());
    ui->lineEditPatronymic->setText(m_staff->getperson()->getpatronymic());
    ui->lineEditEmail->setText(m_staff->getperson()->getemail());
    ui->lineEditPhone->setText(m_staff->getperson()->getphone_number());
    this->setWindowTitle("Изменить студента");
    ui->pushButtonAction->setText("Изменить");
    ui->pushButton->setText("Ок");
    if(m_staff->getdepartment()!=nullptr){
        ui->comboBoxGrops->setCurrentText((m_staff->getdepartment()->getname()));

    }else{
        ui->comboBoxGrops->setCurrentIndex(-1);
    }

}
