#ifndef STaffUNIVERSITY_H
#define STaffUNIVERSITY_H

#include <QDialog>
#include "model/abstractstaffuniversitymodel.h"
#include "model/abstractdepartmentsmodel.h"
#include <QMessageBox>
#include "view/insertstaffuniversity.h"
#include "view/insertdepartment.h"
namespace Ui {
class StaffUniversityWindow;
}

class StaffUniversityWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StaffUniversityWindow(QWidget *parent = nullptr);
    ~StaffUniversityWindow();
private slots:
    void onDeleteStaffClicked();
    void onInsertStaffClicked();
    void onTableStaffClicked();
    void onDeleteDepartmentClicked();
    void onInsertDepartmentClicked();
    void onTableDepartmentClicked();
    void onOkClicked();

private:
    Ui::StaffUniversityWindow *ui;
    AbstractStaffUniversityModel *m_staffUniversityModel;
    AbstractDepartmentsModel *m_departmentModel;


};


#endif // STaffUNIVERSITY_H
