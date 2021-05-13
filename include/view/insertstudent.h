#ifndef INSERTSTUDENT_H
#define INSERTSTUDENT_H

#include <QDialog>
#include "Student.h"
#include "QMessageBox"
#include "model/abstracteducationalprogrammodel.h"

namespace Ui {
class InsertStudent;
}

class InsertStudent : public QDialog
{
    Q_OBJECT

public:
    InsertStudent(ListOfGroup&,QWidget *parent = nullptr);
    ~InsertStudent();



    void insert(Student_ptr&);
    Student_ptr& getStudent();

private slots:
    void onActionClicked();
    void onOkClicked();


private:
    Ui::InsertStudent *ui;
    Student_ptr m_student;
    ListOfGroup m_listGroups;
    AbstractEducationalProgramModel *m_modelEducationalProgram;
    void fillComboBox();
    void initInsert();

};

#endif // INSERTSTUDENT_H
