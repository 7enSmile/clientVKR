#include "view/insertdepartment.h"
#include "ui_insertdepartment.h"

InsertDepartment::InsertDepartment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertDepartment)
{
    ui->setupUi(this);
    m_department.reset(new Department());
    this->setWindowTitle("Добавить");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
}

InsertDepartment::~InsertDepartment()
{
    delete ui;
}

void InsertDepartment::insert(Department_ptr &department)
{
    m_department=department;
    initInser();
}

Department_ptr &InsertDepartment::getDepartment()
{
     return m_department;

}

void InsertDepartment::initInser()
{
    this->setWindowTitle("Изменить");
    ui->lineEdit->setText(m_department->getname());

}

void InsertDepartment::onOkClicked()
{
    m_department->setname(ui->lineEdit->text());
    if(!m_department->getname().isEmpty()){
        QDialog::accept();

    }else{
        QMessageBox::critical(this,"Ошибка!","Задано пустое поле");
    }

}
