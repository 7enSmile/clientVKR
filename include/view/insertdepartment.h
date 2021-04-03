#ifndef INSERTDEPARTMENT_H
#define INSERTDEPARTMENT_H

#include <QDialog>
#include "Department.h"
#include <QMessageBox>
namespace Ui {
class InsertDepartment;
}

class InsertDepartment : public QDialog
{
    Q_OBJECT

public:
    explicit InsertDepartment(QWidget *parent = nullptr);
    ~InsertDepartment();
    void insert(Department_ptr&);
    Department_ptr &getDepartment();

private:
    Ui::InsertDepartment *ui;
    Department_ptr m_department;
    void initInser();
private slots:
    void onOkClicked();
};

#endif // INSERTDEPARTMENT_H
