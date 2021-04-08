#ifndef SEARCHSTAFFUNIVERSITY_H
#define SEARCHSTAFFUNIVERSITY_H
#include "model/abstractstaffuniversitymodel.h"
#include "model/abstractdepartmentsmodel.h"
#include "model/abstractgroupsmodel.h"
#include <QDialog>
#include <QDialog>

namespace Ui {
class SearchStaffUniversity;
}

class SearchStaffUniversity : public QDialog
{
    Q_OBJECT

public:
    explicit SearchStaffUniversity(QWidget *parent = nullptr);
    ~SearchStaffUniversity();
    HeadUniversity_ptr getStaffUniversity();

private:
    Ui::SearchStaffUniversity *ui;
    AbstractStaffUniversityModel *m_modelStaffUniversity;
    AbstractDepartmentsModel *m_modelDepartment;

    HeadUniversity_ptr m_staff;
private slots:
    void textChanged();
    void onTableStaffUniversityClicked();
};

#endif // SEARCHSTAFFUNIVERSITY_H
