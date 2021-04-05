#ifndef INSERTSTaffUNIVERSITY_H
#define INSERTSTaffUNIVERSITY_H
#include "Head_university.h"
#include "QMessageBox"
#include <QDialog>

namespace Ui {
class InsertStaffUniversity;
}

class InsertStaffUniversity : public QDialog
{
    Q_OBJECT

public:
    InsertStaffUniversity(ListOfDepartment&,QWidget *parent = 0);
    ~InsertStaffUniversity();



    void insert(HeadUniversity_ptr&);
    HeadUniversity_ptr& getStaffUniversity();

private slots:
    void onActionClicked();
    void onOkClicked();


private:
    Ui::InsertStaffUniversity *ui;
    HeadUniversity_ptr m_staff;
    ListOfDepartment m_listDepartmens;
    void fillComboBox();
    void initInsert();


};

#endif // INSERTSTaffUNIVERSITY_H
