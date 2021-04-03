#ifndef INSERTSTAFFEMPLOYER_H
#define INSERTSTAFFEMPLOYER_H

#include "Head_employer.h"
#include "Contact_employer.h"
#include "QMessageBox"
#include <QDialog>

namespace Ui {
class InsertStaffEmployer;
}

class InsertStaffEmployer : public QDialog
{
    Q_OBJECT

public:
    explicit InsertStaffEmployer(QWidget *parent = nullptr);
    ~InsertStaffEmployer();

private:
    Ui::InsertStaffEmployer *ui;
};

#endif // INSERTSTAFFEMPLOYER_H
