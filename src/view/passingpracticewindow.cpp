#include "view/passingpracticewindow.h"
#include "ui_passingpracticewindow.h"

PassingPracticeWindow::PassingPracticeWindow(PassingPractice_ptr passingPractice,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PassingPracticeWindow)
{
    ui->setupUi(this);
    m_passingPractice.reset(new PassingPractice());
    m_passingPractice=passingPractice;
    m_modelTasks=new AbstractTasksPracticeModel(m_passingPractice->gettask());
    ui->tableViewTask->setModel(m_modelTasks);
    if(m_passingPractice->gethead_employer()!=nullptr){
        ui->labelHeadEmployer->setText(m_passingPractice->gethead_employer()->getperson()->getlastname()+" "+m_passingPractice->gethead_employer()->getperson()->getfirstname());
    }
    if(m_passingPractice->gethead_university()!=nullptr){
        ui->labelHeadUniversity->setText(m_passingPractice->gethead_university()->getperson()->getlastname()+" "+m_passingPractice->gethead_university()->getperson()->getfirstname());
    }
    if(m_passingPractice->getstuden()!=nullptr){
        ui->labelStudent->setText(m_passingPractice->getstuden()->getperson()->getlastname()+" "+m_passingPractice->getstuden()->getperson()->getfirstname());
    }
    initconnect();
}

PassingPracticeWindow::PassingPracticeWindow(Employer_ptr employer,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PassingPracticeWindow)
{
    ui->setupUi(this);
    m_passingPractice.reset(new PassingPractice());
    m_passingPractice->setemployer(employer);
    m_modelTasks=new AbstractTasksPracticeModel(m_passingPractice->gettask());
    ui->tableViewTask->setModel(m_modelTasks);
    initconnect();
}

PassingPractice_ptr PassingPracticeWindow::getPassingPractice()
{
    return m_passingPractice;

}

void PassingPracticeWindow::initconnect()
{
    connect(ui->tableViewTask,SIGNAL(clicked(QModelIndex)),this,SLOT(onTableTasksClicked()));
    connect(ui->pushButtonInsertStudent,SIGNAL(clicked()),this,SLOT(onInsertStudentClicked()));
    connect(ui->pushButtonInserHeadUniversity,SIGNAL(clicked()),this,SLOT(onInserStaffUniversityClicked()));
}

void PassingPracticeWindow::onTableTasksClicked()
{
    QModelIndexList index = ui->tableViewTask->selectionModel()->selectedRows();
    m_modelTasks->insertTaskLocal(index[0].row());
    m_passingPractice->settask(m_modelTasks->gettask());
    ui->tableViewTask->clearSelection();
    ui->tableViewTask->clearFocus();

}

void PassingPracticeWindow::onInsertStudentClicked()
{
    SearchStudents  *w=new SearchStudents();
    if(w->exec()==QDialog::Accepted){
        m_passingPractice->setstuden(w->getStudent());
        ui->labelStudent->setText(m_passingPractice->getstuden()->getperson()->getfirstname()+" "+m_passingPractice->getstuden()->getperson()->getlastname());
    }

}

void PassingPracticeWindow::onInserStaffUniversityClicked()
{
    SearchStaffUniversity *w=new  SearchStaffUniversity();
    if(w->exec()==QDialog::Accepted){
        m_passingPractice->sethead_university(w->getStaffUniversity());
        ui->labelHeadUniversity->setText(m_passingPractice->gethead_university()->getperson()->getfirstname()+" "+m_passingPractice->gethead_university()->getperson()->getlastname());
    }

}






PassingPracticeWindow::~PassingPracticeWindow()
{
    delete ui;
}
