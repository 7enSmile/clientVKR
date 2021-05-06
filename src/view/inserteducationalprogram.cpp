#include "view/inserteducationalprogram.h"
#include "ui_inserteducationalprogram.h"

InsertEducationalProgram::InsertEducationalProgram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertEducationalProgram)
{
    ui->setupUi(this);
    m_educationalProgram.reset(new EducationalProgram());
    ResultEducation_ptr result;
    result.reset(new ResultEducation());
    result->seteducational_program(m_educationalProgram);
    ListOfResultEducation list;
    list.insert(1,result);
    m_educationalProgram->setlist_of_result_education(list);
    initconnection();
    this->setWindowTitle("Добавить");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

InsertEducationalProgram::InsertEducationalProgram(EducationalProgram_ptr educationalProgram,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertEducationalProgram)
{
    ui->setupUi(this);
    m_educationalProgram.reset(new EducationalProgram());
    m_educationalProgram=educationalProgram;
    if(m_educationalProgram->getlist_of_result_education().count()==0){
        ResultEducation_ptr result;
        result.reset(new ResultEducation());
        result->seteducational_program(m_educationalProgram);
        ListOfResultEducation list;
        list.insert(1,result);
        m_educationalProgram->setlist_of_result_education(list);
    }

    ui->lineEditName->setText(m_educationalProgram->getname());
    ui->lineEditFocus->setText(m_educationalProgram->getfocus());
    ui->lineEditField->setText(m_educationalProgram->getfield());
    ui->plainTextEditDescription->setPlainText(m_educationalProgram->getdescription());
    initconnection();
    ui->pushButtonAction->setText("Изменить");
    ui->pushButtonOk->setText("Ок");
    this->setWindowTitle("Изменить");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

InsertEducationalProgram::~InsertEducationalProgram()
{
    delete ui;
}

EducationalProgram_ptr InsertEducationalProgram::getEducationalProgram()
{
    return m_educationalProgram;
}

void InsertEducationalProgram::initconnection()
{
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
}

void InsertEducationalProgram::onActionClicked()
{
    m_educationalProgram->setname(ui->lineEditName->text());
    m_educationalProgram->setfocus(ui->lineEditFocus->text());
    m_educationalProgram->setfield(ui->lineEditField->text());
    m_educationalProgram->setdescription(ui->plainTextEditDescription->toPlainText());

    QDialog::accept();

}

void InsertEducationalProgram::onOKCliced()
{
    QDialog::close();
}

void InsertEducationalProgram::onResultClicked()
{

}

void InsertEducationalProgram::onAdditionalClicket()
{

}
