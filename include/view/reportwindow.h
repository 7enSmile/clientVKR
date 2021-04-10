#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QDialog>
#include "Report.h"
#include <QFileDialog>
#include <QStandardPaths>
namespace Ui {
class ReportWindow;
}

class ReportWindow : public QDialog
{
    Q_OBJECT

public:
    ReportWindow(PassingPractice_ptr,QWidget *parent = nullptr);
    ReportWindow(Report_ptr,QWidget *parent = nullptr);
    Report_ptr getReport();
    ~ReportWindow();

private:
    Report_ptr m_report;
    Ui::ReportWindow *ui;
private slots:
    void onActionClicked();
    void onOkClicked();
    void onInputReportClicked();
    void onGetReportClicked();
};

#endif // REPORTWINDOW_H
