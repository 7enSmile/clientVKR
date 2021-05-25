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

    m_modelReports=new AbstractReportsModel(m_passingPractice->getlist_of_reports());
    ui->tableViewReports->setModel(m_modelReports);
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
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Прохождение практики");
    ui->pushButtonOk->setText("Ок");
    ui->pushButtonAction->setText("Изменить");


}

PassingPracticeWindow::PassingPracticeWindow(Employer_ptr employer,Practice_ptr practice,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PassingPracticeWindow)
{
    ui->setupUi(this);
    m_passingPractice.reset(new PassingPractice());
    m_passingPractice->setemployer(employer);
    m_passingPractice->setpractice(practice);
    m_modelTasks=new AbstractTasksPracticeModel(m_passingPractice->gettask());
    ui->tableViewTask->setModel(m_modelTasks);


    m_modelReports=new AbstractReportsModel(m_passingPractice->getlist_of_reports());
    ui->tableViewReports->setModel(m_modelReports);
    initconnect();
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Прохождение практики");
    if(m_passingPractice->getemployer()==nullptr)
        ui->pushButtonHeadEmployer->setDisabled(true);

}

PassingPractice_ptr& PassingPracticeWindow::getPassingPractice()
{



    return m_passingPractice;

}

void PassingPracticeWindow::initconnect()
{
    connect(ui->tableViewTask,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableTasksClicked()));
    connect(ui->pushButtonInsertStudent,SIGNAL(clicked()),this,SLOT(onInsertStudentClicked()));
    connect(ui->pushButtonInserHeadUniversity,SIGNAL(clicked()),this,SLOT(onInserStaffUniversityClicked()));
    connect(ui->pushButtonHeadEmployer,SIGNAL(clicked()),this,SLOT(onInsertHeadEmployerClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonInsertTask,SIGNAL(clicked()),this,SLOT(onInsertTaskClicked()));
    connect(ui->pushButtonDeleteTask,SIGNAL(clicked()),this,SLOT(onDeleteTaskClicked()));
    connect(ui->tableViewReports,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableReportClicked()));
    connect(ui->pushButtonInsertReport,SIGNAL(clicked()),this,SLOT(onInsertReportClicked()));
    connect(ui->pushButtonDeleteReport,SIGNAL(clicked()),this,SLOT(onDeleteReportClicked()));

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

void PassingPracticeWindow::onInsertHeadEmployerClicked()
{
    SearchHeadEmployer *w=new SearchHeadEmployer(m_passingPractice->getemployer());
    if(w->exec()==QDialog::Accepted){
        m_passingPractice->sethead_employer(w->getHeadEmployer());
        ui->labelHeadEmployer->setText(m_passingPractice->gethead_employer()->getperson()->getfirstname()+" "+m_passingPractice->gethead_employer()->getperson()->getlastname());
    }

}

void PassingPracticeWindow::onOkClicked()
{
    QDialog::close();

}

void PassingPracticeWindow::onActionClicked()
{
    QDialog::accept();

}

void PassingPracticeWindow::onInsertTaskClicked()
{
    InsertTaskPractice *w=new InsertTaskPractice();
    if(w->exec()==QDialog::Accepted){
        qDebug()<<"ТЕст";
        m_modelTasks->insertTaskGlobal(w->getTaskPractice());
    }


}

void PassingPracticeWindow::onDeleteTaskClicked()
{
    QModelIndexList index = ui->tableViewTask->selectionModel()->selectedRows();
    m_modelTasks->deleteTask(index[0].row());
    ui->tableViewTask->clearSelection();
    ui->tableViewTask->clearFocus();


}

void PassingPracticeWindow::onTableReportClicked()
{
    QModelIndexList index = ui->tableViewReports->selectionModel()->selectedRows();
    ReportWindow *w=new ReportWindow(m_modelReports->getReport(index[0].row()));
    if(w->exec()==QDialog::Accepted){

        m_passingPractice->setlist_of_reports(m_modelReports->getListReports());
    }

}

void PassingPracticeWindow::onInsertReportClicked()
{
    ReportWindow *w=new ReportWindow(m_passingPractice);
    if(w->exec()==QDialog::Accepted){
        m_modelReports->saveReport(w->getReport());
        m_passingPractice->setlist_of_reports(m_modelReports->getListReports());
    }

}

void PassingPracticeWindow::onDeleteReportClicked()
{
    QModelIndexList index = ui->tableViewReports->selectionModel()->selectedRows();
    if(index.count()!=0){

        m_modelReports->deleteReport(index[0].row());
        m_passingPractice->setlist_of_reports(m_modelReports->getListReports());

    }
    ui->tableViewReports->clearSelection();
    ui->tableViewReports->clearFocus();


}



PassingPracticeWindow::~PassingPracticeWindow()
{
    delete ui;
}
