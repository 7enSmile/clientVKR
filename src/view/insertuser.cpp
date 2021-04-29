#include "view/insertuser.h"
#include "ui_insertuser.h"

InsertUser::InsertUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertUser)
{
    ui->setupUi(this);
    connect(ui->pushButtonCancel,SIGNAL(clicked()),this,SLOT(onCancelCkicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Добавить");
}

InsertUser::~InsertUser()
{
    delete ui;
}

QString InsertUser::getLogin()
{
    return m_login;

}

QString InsertUser::getPassword()
{

    return m_password;

}



void InsertUser::onActionClicked()
{
    m_login=ui->lineEditLogin->text();
    m_password=ui->lineEditPassword->text();
    QDialog::accept();

}

void InsertUser::onCancelCkicked()
{
    QDialog::close();

}
