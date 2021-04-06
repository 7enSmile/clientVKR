#include "view/insertstaffemployer.h"
#include "ui_insertstaffemployer.h"

InsertStaffEmployer::InsertStaffEmployer(TypeInsert typeInsert,ListOfEmployer listEmployers,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertStaffEmployer)
{
    ui->setupUi(this);
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Создать работника предприятия");
    ui->pushButtonAction->setText("Добавить");
    ui->pushButton->setText("Отмена");
    m_headEmployer.reset(new HeadEmployer());
    m_contactEmployer.reset(new ContactEmployer());
    ui->comboBoxRole->setHidden(true);
    ui->label_2->setHidden(true);
    m_typeInsert=typeInsert;
    m_listEmployers=listEmployers;
    fillComboBox();

}

InsertStaffEmployer::~InsertStaffEmployer()
{
    delete ui;
}

InsertStaffEmployer::InsertStaffEmployer(TypeInsert typeInsert, Employer_ptr employer, QWidget *parent):
    QDialog(parent),
    ui(new Ui::InsertStaffEmployer)
{
    ui->setupUi(this);
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Создать работника предприятия");
    ui->pushButtonAction->setText("Добавить");
    ui->pushButton->setText("Отмена");
    m_headEmployer.reset(new HeadEmployer());
    m_contactEmployer.reset(new ContactEmployer());
    ui->comboBoxRole->setHidden(true);
    ui->label_2->setHidden(true);
    m_typeInsert=typeInsert;
    m_listEmployers.insert(employer->getemployer_id(),employer);
    ui->comboBox->addItem(employer->getname());
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox->setHidden(true);
    ui->label_4->setHidden(true);


}

void InsertStaffEmployer::insertHeadEmployer(HeadEmployer_ptr & headEmployer)
{

    m_headEmployer=headEmployer;
    initInsertHeadEmployer();

}

void InsertStaffEmployer::insertContactEmplyer(ContactEmployer_ptr & contactEmployer)
{
    m_contactEmployer=contactEmployer;
    initInsertContactEmployer();
}

HeadEmployer_ptr &InsertStaffEmployer::getHeadEmployer()
{
    return m_headEmployer;

}

ContactEmployer_ptr &InsertStaffEmployer::getContactEmployer()
{
    return m_contactEmployer;
}

void InsertStaffEmployer::onActionClicked()
{
    Person_ptr person;
    person.reset(new Person());
    if(m_typeInsert==insertheademployer){
        if(m_headEmployer->getperson()!=nullptr){
            person=m_headEmployer->getperson();
        }
        person->setfirstname(ui->lineEditFirstname->text());
        person->setlastname(ui->lineEditLastname->text());
        person->setpatronymic(ui->lineEditPatronymic->text());
        person->setphone_number(ui->lineEditPhone->text());
        person->setemail(ui->lineEditEmail->text());
        m_headEmployer->setperson(person);



        if(ui->comboBox->currentIndex()!=-1){

        m_headEmployer->setemployer(m_listEmployers.getByIndex(ui->comboBox->currentIndex()));

        }

        if(!person->getfirstname().isEmpty()&&!person->getlastname().isEmpty()&&!person->getpatronymic().isEmpty()&&!person->getphone_number().isEmpty()&&!person->getemail().isEmpty()){

            QDialog::accept();
        }

        else{

            QMessageBox::critical(this,"Ошибка!","Введенно пустое поле!");
        }


    }else{
        if(m_contactEmployer->getperson()!=nullptr){
            person=m_contactEmployer->getperson();
        }
        person->setfirstname(ui->lineEditFirstname->text());
        person->setlastname(ui->lineEditLastname->text());
        person->setpatronymic(ui->lineEditPatronymic->text());
        person->setphone_number(ui->lineEditPhone->text());
        person->setemail(ui->lineEditEmail->text());
        m_contactEmployer->setperson(person);
        if(ui->comboBox->currentIndex()!=-1){

        m_contactEmployer->setemployer(m_listEmployers.getByIndex(ui->comboBox->currentIndex()));

        }

        if(!person->getfirstname().isEmpty()&&!person->getlastname().isEmpty()&&!person->getpatronymic().isEmpty()&&!person->getphone_number().isEmpty()&&!person->getemail().isEmpty()){

            QDialog::accept();
        }

        else{

            QMessageBox::critical(this,"Ошибка!","Введенно пустое поле!");
        }

    }

}

void InsertStaffEmployer::onOkClicked()
{
    QDialog::close();

}

void InsertStaffEmployer::fillComboBox()
{
    for(int i=0;i<m_listEmployers.count();i++){
        ui->comboBox->addItem(m_listEmployers.getByIndex(i)->getname());
    }

}

void InsertStaffEmployer::initInsertHeadEmployer()
{
    ui->lineEditFirstname->setText(m_headEmployer->getperson()->getfirstname());
    ui->lineEditLastname->setText(m_headEmployer->getperson()->getlastname());
    ui->lineEditPatronymic->setText(m_headEmployer->getperson()->getpatronymic());
    ui->lineEditEmail->setText(m_headEmployer->getperson()->getemail());
    ui->lineEditPhone->setText(m_headEmployer->getperson()->getphone_number());
    this->setWindowTitle("Изменить студента");
    ui->pushButtonAction->setText("Изменить");
    ui->pushButton->setText("Ок");
    ui->comboBoxRole->setHidden(false);
    ui->label_2->setHidden(false);
    ui->comboBoxRole->setCurrentIndex(0);
    ui->comboBoxRole->setEnabled(false);
    if(m_headEmployer->getemployer()!=nullptr){
        ui->comboBox->setCurrentText(m_headEmployer->getemployer()->getname());

    }else{
        ui->comboBox->setCurrentIndex(-1);
    }



}

void InsertStaffEmployer::initInsertContactEmployer()
{
    ui->lineEditFirstname->setText(m_contactEmployer->getperson()->getfirstname());
    ui->lineEditLastname->setText(m_contactEmployer->getperson()->getlastname());
    ui->lineEditPatronymic->setText(m_contactEmployer->getperson()->getpatronymic());
    ui->lineEditEmail->setText(m_contactEmployer->getperson()->getemail());
    ui->lineEditPhone->setText(m_contactEmployer->getperson()->getphone_number());
    this->setWindowTitle("Изменить студента");
    ui->pushButtonAction->setText("Изменить");
    ui->pushButton->setText("Ок");
    ui->comboBoxRole->setHidden(false);
    ui->label_2->setHidden(false);
    ui->comboBoxRole->setCurrentIndex(1);
    ui->comboBoxRole->setEnabled(false);
    if(m_contactEmployer->getemployer()!=nullptr){
        ui->comboBox->setCurrentText(m_contactEmployer->getemployer()->getname());

    }else{
        ui->comboBox->setCurrentIndex(-1);
    }

}
