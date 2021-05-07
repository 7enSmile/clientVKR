#include "view/insertdiscipline.h"
#include "ui_insertdiscipline.h"

InsertDiscipline::InsertDiscipline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertDiscipline)
{
    ui->setupUi(this);
    m_discipline.reset(new Discipline());
    this->setWindowTitle("Добавить");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    initconnection();
}

InsertDiscipline::InsertDiscipline(Discipline_ptr discipline,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertDiscipline)
{
    ui->setupUi(this);
    m_discipline.reset(new Discipline());
    m_discipline=discipline;
    this->setWindowTitle("Изменить");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->pushButtonOk->setText("Отмена");
    ui->pushButtonAction->setText("Изменить");
    initconnection();
    ui->lineEditName->setText(m_discipline->getname());
    ui->plainTextEditDescription->setPlainText(m_discipline->getdescription());
    ui->comboBox->setCurrentText(QString::number(m_discipline->getsemester()));

}

Discipline_ptr InsertDiscipline::getDiscipline()
{
    return m_discipline;

}

InsertDiscipline::~InsertDiscipline()
{
    delete ui;
}

void InsertDiscipline::initconnection()
{
   connect(ui->pushButtonResult,SIGNAL(clicked()),this,SLOT(onResultClicked()));
   connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
   connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));

}

void InsertDiscipline::onOkClicked()
{
    QDialog::close();

}

void InsertDiscipline::onActionClicked()
{
    m_discipline->setname(ui->lineEditName->text());
    m_discipline->setdescription(ui->plainTextEditDescription->toPlainText());
    m_discipline->setsemester(ui->comboBox->currentText().toInt());
    QDialog::accept();

}

void InsertDiscipline::onResultClicked()
{
    ResultDisciplineWindow *w=new ResultDisciplineWindow(m_discipline->getlist_of_result_educational());
    if(w->exec()==Accepted){

        m_discipline->setlist_of_result_educational(w->getList());
    }

}
