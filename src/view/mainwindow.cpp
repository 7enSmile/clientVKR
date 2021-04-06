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
    ui->tableViewEmployers->setModel(m_modelEmployer);
    connect(ui->tableViewEmployers,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onEmployersTableClicked()));
    connect(ui->pushButtonInsertEmployer,SIGNAL(clicked()),this,SLOT(onInsertEmployerClicked()));
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
    actionStaffEmployer->setText("Работники предприятия");
    ui->menubar->addAction(actionStaffEmployer);
    connect(actionStaffEmployer,SIGNAL(triggered()),this,SLOT(onStaffEmployerClicked()));
    QAction *actionStaffUniversity = new QAction(this);
    actionStaffUniversity->setObjectName("actioStaffUniversity");
    actionStaffUniversity->setText("Работники университета");
    ui->menubar->addAction(actionStaffUniversity);
    connect(actionStaffUniversity,SIGNAL(triggered()),this,SLOT(onStaffUniversityClicked()));
    QAction *actionExit = new QAction(this);
    actionExit->setObjectName("actioExit");
    actionExit->setText("Выход");
    ui->menubar->addAction(actionExit);
    connect(actionExit,SIGNAL(triggered()),this,SLOT(onExitClicked()));


}

void MainWindow::onEventsClicked()
{
   \

}

void MainWindow::onEducationProgramsClicked()
{

}

void MainWindow::onStudentsClicked()
{
    StudentsWindow *w=new StudentsWindow();
    w->exec();
    m_modelEmployer->loadList();


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
    m_modelEmployer->loadList();

}

void MainWindow::onExitClicked()
{

}

void MainWindow::onEmployersTableClicked()
{

    QModelIndexList index = ui->tableViewEmployers->selectionModel()->selectedRows();
    EmployersWindow *w =new EmployersWindow(m_modelEmployer->getEmployer(index[0].row()));
    if(w->exec()==QDialog::Accepted){
        m_modelEmployer->saveEmployer(w->getEmployer());
         m_modelEmployer->loadList();

    }




}

void MainWindow::onInsertEmployerClicked()
{
    EmployersWindow *w =new EmployersWindow();
    if(w->exec()==QDialog::Accepted){
        m_modelEmployer->saveEmployer(w->getEmployer());
        m_modelEmployer->loadList();

    }


}
