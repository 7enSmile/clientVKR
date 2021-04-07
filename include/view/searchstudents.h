#ifndef SEARHSTUDENTS_H
#define SEARHSTUDENTS_H
#include "model/abstractstudentsmodel.h"
#include "model/abstractgroupsmodel.h"
#include <QDialog>

namespace Ui {
class SearchStudents;
}

class SearchStudents : public QDialog
{
    Q_OBJECT

public:
    explicit SearchStudents(QWidget *parent = nullptr);
    ~SearchStudents();
    Student_ptr getStudent();

private:
    Ui::SearchStudents *ui;
    AbstractStudentsModel *m_modelStudents;
    AbstractGroupsModel *m_modelGroups;
    Student_ptr m_student;

private slots:
    void textChanged();
    void onTableStudentsClicked();
};

#endif // SEARHSTUDENTS_H
