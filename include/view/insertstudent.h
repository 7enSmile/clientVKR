#ifndef INSERTSTUDENT_H
#define INSERTSTUDENT_H

#include <QDialog>
#include "Student.h"

namespace Ui {
class InsertStudent;
}

class InsertStudent : public QDialog
{
    Q_OBJECT

public:
    explicit InsertStudent(QWidget *parent = nullptr);
    ~InsertStudent();
    void setGroups(ListOfGroup&);


    void insert(Student_ptr&);
    Student_ptr& getStudent();

private slots:
    void onActionCliced();
    void onOkCliced();


private:
    Ui::InsertStudent *ui;
    Student_ptr m_student;
    ListOfGroup m_listGroups;
    void fillComboBox();
};

#endif // INSERTSTUDENT_H
