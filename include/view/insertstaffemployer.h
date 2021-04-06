#ifndef INSERTSTAFFEMPLOYER_H
#define INSERTSTAFFEMPLOYER_H

#include "Head_employer.h"
#include "Contact_employer.h"
#include "QMessageBox"
#include <QDialog>
enum TypeInsert{insertcontactemployer,insertheademployer};
namespace Ui {
class InsertStaffEmployer;
}

class InsertStaffEmployer : public QDialog
{
    Q_OBJECT

public:
    InsertStaffEmployer(TypeInsert,ListOfEmployer,QWidget *parent = nullptr);
    ~InsertStaffEmployer();
     void insertHeadEmployer(HeadEmployer_ptr&);
     void insertContactEmplyer(ContactEmployer_ptr&);
     HeadEmployer_ptr& getHeadEmployer();
     ContactEmployer_ptr& getContactEmployer();

private slots:
    void onActionClicked();
    void onOkClicked();
private:
    Ui::InsertStaffEmployer *ui;
    HeadEmployer_ptr m_headEmployer;
    ContactEmployer_ptr m_contactEmployer;
    void fillComboBox();
    void initInsertHeadEmployer();
    void initInsertContactEmployer();
    TypeInsert m_typeInsert;
    ListOfEmployer m_listEmployers;
};


#endif // INSERTSTAFFEMPLOYER_H
