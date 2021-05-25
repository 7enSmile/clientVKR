#include "view/insertgroup.h"
#include "ui_insertgroup.h"

InsertGroup::InsertGroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertGroup)
{
    ui->setupUi(this);
    m_group.reset(new Group);
    this->setWindowTitle("Группа");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
}

InsertGroup::~InsertGroup()
{
    delete ui;

}

void InsertGroup::insert(Group_ptr &group)
{
    m_group=group;
    initInser();

}

Group_ptr &InsertGroup::getGroup()
{
    return m_group;

}

void InsertGroup::initInser()
{
    this->setWindowTitle("Группа");
    ui->lineEditNumber->setText(m_group->getnumber());

}

void InsertGroup::onOkClicked()

{

    m_group->setnumber(ui->lineEditNumber->text());
    if(!m_group->getnumber().isEmpty()){
        QDialog::accept();

    }else{
        QMessageBox::critical(this,"Ошибка!","Задано пустое поле");
    }


}
