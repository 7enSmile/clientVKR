#include "view/eventswindow.h"
#include "ui_eventswindow.h"

EventsWindow::EventsWindow(ListOfEmployer list,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventsWindow)
{
    ui->setupUi(this);
    m_listEmployers=list;

    m_modelEvents=new AbstractEventsModel();
    connect(ui->pushButtonInsert,SIGNAL(clicked()),this,SLOT(onInsertClicked()));
    connect(ui->pushButtonDeleteEvent,SIGNAL(clicked()),this,SLOT(onDeleteClicked()));
    connect(ui->tableViewEvents,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableEventsClicked()));
    connect(ui->pushButtonReport,SIGNAL(clicked()),this,SLOT(onReportClicked()));
    ui->tableViewEvents->setModel(m_modelEvents);
    this->setWindowTitle("Мероприятия");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

}

EventsWindow::~EventsWindow()
{
    delete ui;
}

void EventsWindow::onDeleteClicked()

{
    QModelIndexList index = ui->tableViewEvents->selectionModel()->selectedRows();
    if(index.count()>0){
        m_modelEvents->deleteEvent(index[0].row());
    }
    ui->tableViewEvents->clearSelection();
    ui->tableViewEvents->clearFocus();



}

void EventsWindow::onInsertClicked()
{
    InsertEvent *w=new InsertEvent(m_listEmployers);
    if(w->exec()==QDialog::Accepted){
        m_modelEvents->saveEvent(w->getEvent());
    }

}

void EventsWindow::onTableEventsClicked()
{

    QModelIndexList index = ui->tableViewEvents->selectionModel()->selectedRows();
    InsertEvent *w=new InsertEvent( m_listEmployers,m_modelEvents->getEvent(index[0].row()));
    if(w->exec()==QDialog::Accepted){
        m_modelEvents->saveEvent(w->getEvent());
    }
    ui->tableViewEvents->clearSelection();
    ui->tableViewEvents->clearFocus();



}

void EventsWindow::onReportClicked()
{
    ReportEventsWindow *w=new ReportEventsWindow();
    w->exec();

}
