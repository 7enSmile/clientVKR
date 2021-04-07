#include "view/practicewindow.h"
#include "ui_practicewindow.h"

PracticeWindow::PracticeWindow(ListOfEmployer listEmployers, Practice_ptr practice, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PracticeWindow)
{
    ui->setupUi(this);
    m_practice.reset(new Practice());
    m_practice=practice;
    m_listEmployers=listEmployers;
    initElementsChange();
    iniconnection();


}

PracticeWindow::PracticeWindow(ListOfEmployer listEmployers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PracticeWindow)
{
    ui->setupUi(this);
    m_practice.reset(new Practice());
    m_listEmployers=listEmployers;
    initElementInsert();
    iniconnection();
}

PracticeWindow::~PracticeWindow()
{
    delete ui;
}

Practice_ptr PracticeWindow::getPractice()
{

    m_practice->setemployer(m_listEmployers.getByIndex(ui->comboBox->currentIndex()));
    m_practice->setbeginning(ui->dateEditbegining->date());
    m_practice->setending(ui->dateEditEnding->date());
    return m_practice;
}

void PracticeWindow::iniconnection()
{
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));

}

void PracticeWindow::initElementsChange()
{

    for(int i=0;i<m_listEmployers.count();i++){
        ui->comboBox->addItem(m_listEmployers.getByIndex(i)->getname());
    }
    if(m_practice->getemployer()!=nullptr){
        ui->comboBox->setCurrentText(m_practice->getemployer()->getname());
    }

    ui->dateEditbegining->setDate(m_practice->getbeginning());
    ui->dateEditEnding->setDate(m_practice->getending());
    ui->pushButtonAction->setText("Изменить");
    ui->pushButtonOk->setText("Ок");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Изменить");


}

void PracticeWindow::initElementInsert()
{
    for(int i=0;i<m_listEmployers.count();i++){
        ui->comboBox->addItem(m_listEmployers.getByIndex(i)->getname());
    }
    ui->pushButtonAction->setText("Создать");
    ui->pushButtonOk->setText("Отмена");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Добавить");

}

void PracticeWindow::onOkClicked()
{
    QDialog::close();

}

void PracticeWindow::onActionClicked()
{

    QDialog::accept();

}
