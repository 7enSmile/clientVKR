#ifndef INSERTMANYPASSINGPRACTICE_H
#define INSERTMANYPASSINGPRACTICE_H

#include <QDialog>
#include "model/abstractstudentsmodel.h"
#include "model/abstractheademployermodel.h"
#include "model/abstractstaffuniversitymodel.h"
#include "model/abstractgroupsmodel.h"
#include "model/abstractdepartmentsmodel.h"
#include "QMessageBox"

namespace Ui {
class InsertManyPassingPractice;
}

class InsertManyPassingPractice : public QDialog
{
    Q_OBJECT

public:
    InsertManyPassingPractice(Employer_ptr,Practice_ptr,QWidget *parent = nullptr);
    ~InsertManyPassingPractice();
    ListOfPassingPractice& getList();

private:
    Ui::InsertManyPassingPractice *ui;
    AbstractStudentsModel *m_modelStudent;
    AbstractHeadEmployerModel *m_modelHeadEmployer;
    AbstractStaffUniversityModel *m_modelHeadUniversity;
    AbstractDepartmentsModel *m_modelDepartments;
    AbstractGroupsModel *m_modelGroup;
    ListOfPassingPractice m_listPassingPractice;
    Employer_ptr m_employer;
    Practice_ptr m_practice;
    void fillComboBox();
private slots:

    void onActionClicked();
    void changeHeadEmployer();
    void changeHeadUniversity();
    void changeStudents();

};

#endif // INSERTMANYPASSINGPRACTICE_H
