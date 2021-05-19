#include "view/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Главное меню");
    addSubMenu();
    m_modelEmployer=new AbstractEmployerModel();
    m_modelPractice=new AbstractPracticeModel();
    ui->tableViewPractice->setModel(m_modelPractice);
    ui->tableViewEmployers->setModel(m_modelEmployer);
    ui->tableViewPractice->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewPractice->setColumnWidth(0,400);
    ui->tableViewPractice->setColumnWidth(1,150);

    connect(ui->tableViewEmployers,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onEmployersTableClicked()));
    connect(ui->pushButtonInsertEmployer,SIGNAL(clicked()),this,SLOT(onInsertEmployerClicked()));
    connect(ui->tableViewPractice,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onPracticeTableClicked()));
    connect(ui->pushButtonInserPractice,SIGNAL(clicked()),this,SLOT(onInsertPracticeClicked()));
    connect(ui->pushButtonReport,SIGNAL(clicked()),this,SLOT(onReportPracticeClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addSubMenu()
{
    QAction *actionEvents = new QAction(this);
    actionEvents->setObjectName("actionEvents");
    actionEvents->setText("Мероприятия");
    ui->menubar->addAction(actionEvents);
    connect(actionEvents,SIGNAL(triggered()),this,SLOT(onEventsClicked()));
    QAction *actionEducationProgram = new QAction(this);
    actionEducationProgram->setObjectName("actionEducationProgram");
    actionEducationProgram->setText("Образовательные программы");
    ui->menubar->addAction(actionEducationProgram);
    connect(actionEducationProgram,SIGNAL(triggered()),this,SLOT(onEducationProgramClicked()));
    QAction *actionStudents = new QAction(this);
    actionStudents->setObjectName("actioStudents");
    actionStudents->setText("Студенты");
    ui->menubar->addAction(actionStudents);
    connect(actionStudents,SIGNAL(triggered()),this,SLOT(onStudentsClicked()));
    QAction *actionStaffEmployer = new QAction(this);
    actionStaffEmployer->setObjectName("actioStaffEmployer");
    actionStaffEmployer->setText("Сотрудники предприятия");
    ui->menubar->addAction(actionStaffEmployer);
    connect(actionStaffEmployer,SIGNAL(triggered()),this,SLOT(onStaffEmployerClicked()));
    QAction *actionStaffUniversity = new QAction(this);
    actionStaffUniversity->setObjectName("actioStaffUniversity");
    actionStaffUniversity->setText("Сотрудники университета");
    ui->menubar->addAction(actionStaffUniversity);
    connect(actionStaffUniversity,SIGNAL(triggered()),this,SLOT(onStaffUniversityClicked()));
    QAction *actionAbout = new QAction(this);
    actionAbout->setObjectName("actioAbout");
    actionAbout->setText("О программе");
    ui->menubar->addAction(actionAbout);
    connect(actionAbout,SIGNAL(triggered()),this,SLOT(onAboutClicked()));
    QAction *actionExit = new QAction(this);
    actionExit->setObjectName("actioExit");
    actionExit->setText("Выход");
    ui->menubar->addAction(actionExit);
    connect(actionExit,SIGNAL(triggered()),this,SLOT(onExitClicked()));




}

void MainWindow::onEventsClicked()
{
    EventsWindow *w=new EventsWindow(m_modelEmployer->getList());
    w->exec();
   \

}

void MainWindow::onEducationProgramsClicked()
{

}

void MainWindow::onStudentsClicked()
{
    StudentsWindow *w=new StudentsWindow();
    w->exec();
    m_modelPractice->loadList();



}

void MainWindow::onStaffEmployerClicked()
{
    StaffEmployerWindow *w=new StaffEmployerWindow();
    w->exec();
    m_modelEmployer->loadList();

}

void MainWindow::onStaffUniversityClicked()
{
    StaffUniversityWindow *w=new StaffUniversityWindow();
    w->exec();


}

void MainWindow::onExitClicked()
{
    MainWindow::close();

}

void MainWindow::onEmployersTableClicked()
{

    QModelIndexList index = ui->tableViewEmployers->selectionModel()->selectedRows();
    EmployersWindow *w =new EmployersWindow(m_modelEmployer->getEmployer(index[0].row()));
    if(w->exec()==QDialog::Accepted){
        m_modelEmployer->saveEmployer(w->getEmployer());
        m_modelPractice->loadList();


    }
      m_modelEmployer->loadList();
      ui->tableViewEmployers->clearSelection();
      ui->tableViewEmployers->clearFocus();
}

void MainWindow::onInsertEmployerClicked()
{
    EmployersWindow *w =new EmployersWindow();
    if(w->exec()==QDialog::Accepted){
        m_modelEmployer->saveEmployer(w->getEmployer());
        m_modelEmployer->loadList();


    }
     m_modelEmployer->loadList();
     ui->tableViewEmployers->clearSelection();
     ui->tableViewEmployers->clearFocus();


}

void MainWindow::onPracticeTableClicked()
{
    QModelIndexList index = ui->tableViewPractice->selectionModel()->selectedRows();
    PracticeWindow *w=new PracticeWindow(m_modelPractice->getListEmployer(),m_modelPractice->getPractice(index[0].row()));
    if(w->exec()==QDialog::Accepted){
        m_modelPractice->savePractice(w->getPractice());
        m_modelPractice->loadList();


    }



    ui->tableViewPractice->clearSelection();
    ui->tableViewPractice->clearFocus();

}

void MainWindow::onInsertPracticeClicked()
{
    PracticeWindow *w=new PracticeWindow(m_modelPractice->getListEmployer());
    if(w->exec()==QDialog::Accepted){
        m_modelPractice->savePractice(w->getPractice());
        m_modelPractice->loadList();
    }



    ui->tableViewPractice->clearSelection();
    ui->tableViewPractice->clearFocus();

}

void MainWindow::onReportPracticeClicked()
{
    ReportPracticeWindow *w=new ReportPracticeWindow();
    w->exec();

}

void MainWindow::onEducationProgramClicked()
{
    EducationalProgramWindow *w=new EducationalProgramWindow();
    w->exec();

}

void MainWindow::onAboutClicked()
{
    AboutWindow *w=new AboutWindow();
    w->exec();

}
