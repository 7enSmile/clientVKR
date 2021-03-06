#ifndef PASSINGPRACTICEWINDOW_H
#define PASSINGPRACTICEWINDOW_H

#include <QDialog>
#include "Passing_practice.h"
#include "model/abstracttaskspracticemodel.h"
#include "view/searchstudents.h"
#include "view/searchstaffuniversity.h"
#include "view/searchheademployer.h"
#include "view/inserttaskpractice.h"
#include "model/abstractreportsmodel.h"
#include "view/reportwindow.h"
namespace Ui {
class PassingPracticeWindow;
}

class PassingPracticeWindow : public QDialog
{
    Q_OBJECT

public:

    PassingPracticeWindow(PassingPractice_ptr,QWidget *parent = nullptr);

    PassingPracticeWindow(Employer_ptr,Practice_ptr ,QWidget *parent = nullptr);

    PassingPractice_ptr& getPassingPractice();



private:

    PassingPractice_ptr m_passingPractice;

    AbstractTasksPracticeModel *m_modelTasks;
    AbstractReportsModel *m_modelReports;
    void initconnect();
    ~PassingPracticeWindow();
    Ui::PassingPracticeWindow *ui;

private slots:

    void onTableTasksClicked();
    void onInsertStudentClicked();
    void onInserStaffUniversityClicked();
    void onInsertHeadEmployerClicked();
    void onOkClicked();
    void onActionClicked();
    void onInsertTaskClicked();
    void onDeleteTaskClicked();
    void onTableReportClicked();
    void onInsertReportClicked();
    void onDeleteReportClicked();

};

#endif // PASSINGPRACTICEWINDOW_H
