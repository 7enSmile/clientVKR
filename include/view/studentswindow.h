#ifndef STUDENTSWINDOW_H
#define STUDENTSWINDOW_H

#include <QDialog>
#include <model/abstractstudentsmodel.h>
#include <view/insertstudent.h>
#include <view/insertgroup.h>
#include "model/abstactgroupsmodel.h"
namespace Ui {
class StudentsWindow;
}

class StudentsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StudentsWindow(QWidget *parent = nullptr);
    ~StudentsWindow();

private slots:
    void onDeleteStudentClicked();
    void onInsertStudentClicked();
    void onTableStudentClicked();
    void onDeleteGroupClicked();
    void onInsertGroupClicked();
    void onTableGroupClicked();
private:
    Ui::StudentsWindow *ui;
    AbstractStudentsModel *m_modelStudents;
    AbstactGroupsModel *m_modelGroups;

};

#endif // STUDENTSWINDOW_H
