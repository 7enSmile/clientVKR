#include "view/reportwindow.h"
#include "ui_reportwindow.h"

ReportWindow::ReportWindow(PassingPractice_ptr passingPractice,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportWindow)
{
    ui->setupUi(this);
    m_report.reset(new Report());
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect( ui->pushButtonReport,SIGNAL(clicked()),this,SLOT(onInputReportClicked()));
    m_report->setpassing_practice(passingPractice);

}

ReportWindow::ReportWindow(Report_ptr report, QWidget *parent):
    QDialog(parent),
    ui(new Ui::ReportWindow)
{
    ui->setupUi(this);
    m_report.reset(new Report());
    m_report=report;
    ui->pushButtonAction->setText("Изменить");
    ui->pushButtonOk->setText("Ок");
    ui->plainTextEditHEadEmployer->setPlainText(m_report->getfeedback_employer());
    ui->plainTextEditHeadUniversity->setPlainText(m_report->getfeedback_university());



    if(m_report->getreport().isEmpty()){


        connect( ui->pushButtonReport,SIGNAL(clicked()),this,SLOT(onInputReportClicked()));


    }else{


        ui->pushButtonReport->setText("Отчет");
        connect( ui->pushButtonReport,SIGNAL(clicked()),this,SLOT(onGetReportClicked()));

    }
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));


}


Report_ptr ReportWindow::getReport()
{
    return m_report;

}

ReportWindow::~ReportWindow()
{
    delete ui;
}

void ReportWindow::onActionClicked()
{

    m_report->setfeedback_employer(ui->plainTextEditHEadEmployer->toPlainText());
    m_report->setfeedback_university(ui->plainTextEditHeadUniversity->toPlainText());
    QDialog::accept();

}

void ReportWindow::onOkClicked()
{
    QDialog::close();

}

void ReportWindow::onInputReportClicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, "Get PDF", QStandardPaths::writableLocation(QStandardPaths::HomeLocation), QFileDialog::tr("Pdf (*.pdf)"));

    QFile file(fileName);

    file.open(QIODevice::ReadOnly);
    QByteArray array=file.readAll();

    m_report->setreport(array);

    file.close();

}

void ReportWindow::onGetReportClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Get PDF", QDir::currentPath(), QFileDialog::tr("Pdf (*.pdf)"));

    QFile file(fileName);

    file.open(QIODevice::WriteOnly);

    file.write(m_report->getreport());

    file.close();

}
