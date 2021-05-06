#include "view/insertresultdiscipline.h"
#include "ui_insertresultdiscipline.h"

InsertResultDiscipline::InsertResultDiscipline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertResultDiscipline)
{
    ui->setupUi(this);
    m_resultDiscipline.reset(new ResultEducation());
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

}

InsertResultDiscipline::~InsertResultDiscipline()
{
    delete ui;
}

ResultEducation_ptr InsertResultDiscipline::getResultDiscipline()
{
    return m_resultDiscipline;
}

void InsertResultDiscipline::onOkClicket()
{
    QDialog::close();

}

void InsertResultDiscipline::onActionClicket()
{
    m_resultDiscipline->setacquired_skills(ui->lineEdit->text());
    m_resultDiscipline->setdescription(ui->textEdit->toPlainText());
    QDialog::accept();

}
