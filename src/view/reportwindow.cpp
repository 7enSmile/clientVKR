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
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Отчет");

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
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Отчет");



    if(m_report->getreport().isEmpty()){

        connect( ui->pushButtonReport,SIGNAL(clicked()),this,SLOT(onInputReportClicked()));


    }else{


        ui->pushButtonReport->setText("Отчет");
        connect( ui->pushButtonReport,SIGNAL(clicked()),this,SLOT(onGetReportClicked()));

    }
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    if(m_report->getpractice_result()!=nullptr){
        ui->comboBoxHEadEmployer->setCurrentText(m_report->getpractice_result()->getestimate_employer());
        ui->comboBoxHeadUniversity->setCurrentText(m_report->getpractice_result()->getestimate_university());
        qDebug()<<m_report->getpractice_result()->getpractice_result_id();
    }


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
    if(m_report->getpractice_result()==nullptr){
        PracticeResult_ptr practiceresult;
        practiceresult.reset(new PracticeResult);
        practiceresult->setestimate_employer(ui->comboBoxHEadEmployer->currentText());
        practiceresult->setestimate_university(ui->comboBoxHeadUniversity->currentText());
        m_report->setpractice_result(practiceresult);
    }else{
        PracticeResult_ptr practiceresult;
        practiceresult.reset(new PracticeResult);
        practiceresult=m_report->getpractice_result();
        practiceresult->setestimate_employer((ui->comboBoxHEadEmployer->currentText()));
        practiceresult->setestimate_university(ui->comboBoxHeadUniversity->currentText());
        m_report->setpractice_result(practiceresult);

    }
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

    QString fileName = QFileDialog::getOpenFileName(this, "Зазгрузить отчет", QStandardPaths::writableLocation(QStandardPaths::HomeLocation), QFileDialog::tr("Pdf (*.pdf)"));

    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly)){
        QByteArray array=file.readAll();

        m_report->setreport(array);

        file.close();
    }



}

void ReportWindow::onGetReportClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить отчет", QDir::currentPath(), QFileDialog::tr("Pdf (*.pdf)"));

    QFile file(fileName);

    if(file.open(QIODevice::WriteOnly)){

        file.write(m_report->getreport());

        file.close();
    }

}
