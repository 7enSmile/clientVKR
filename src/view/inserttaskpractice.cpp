#include "view/inserttaskpractice.h"
#include "ui_inserttaskpractice.h"

InsertTaskPractice::InsertTaskPractice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertTaskPractice)
{
    ui->setupUi(this);
    m_taskPractice.reset(new TaskPractice());
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->pushButtonCancel,SIGNAL(clicked()),this,SLOT(onCancelClicked()));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Задание");


}

InsertTaskPractice::~InsertTaskPractice()
{
    delete ui;
}

TaskPractice_ptr InsertTaskPractice::getTaskPractice()
{

    return m_taskPractice;

}

void InsertTaskPractice::onActionClicked()
{
    m_taskPractice->setname(ui->lineEditName->text());
    m_taskPractice->setdescription(ui->textEditDescription->toPlainText().trimmed());
    QDialog::accept();

}

void InsertTaskPractice::onCancelClicked()
{
    QDialog::close();

}
