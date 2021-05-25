#include "view/insertresultdiscipline.h"
#include "ui_insertresultdiscipline.h"

InsertResultDiscipline::InsertResultDiscipline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertResultDiscipline)
{
    ui->setupUi(this);
    m_resultDiscipline.reset(new ResultEducation());
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    this->setWindowTitle("Результат");
    ui->pushButtonAction->setText("Добавить");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

InsertResultDiscipline::InsertResultDiscipline(ResultEducation_ptr result,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertResultDiscipline)
{
    ui->setupUi(this);
    m_resultDiscipline.reset(new ResultEducation());
    m_resultDiscipline=result;
    ui->lineEdit->setText(m_resultDiscipline->getacquired_skills());
    ui->textEdit->setText(m_resultDiscipline->getdescription());
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    this->setWindowTitle("Результат");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

}

InsertResultDiscipline::~InsertResultDiscipline()
{
    delete ui;
}

ResultEducation_ptr InsertResultDiscipline::getResultDiscipline()
{
    return m_resultDiscipline;
}

void InsertResultDiscipline::onOkClicked()
{
    QDialog::close();

}

void InsertResultDiscipline::onActionClicked()
{
    m_resultDiscipline->setacquired_skills(ui->lineEdit->text());
    m_resultDiscipline->setdescription(ui->textEdit->toPlainText());
    QDialog::accept();

}
