#ifndef INSERTDEPARTMENT_H
#define INSERTDEPARTMENT_H

#include <QDialog>

namespace Ui {
class InsertDepartment;
}

class InsertDepartment : public QDialog
{
    Q_OBJECT

public:
    explicit InsertDepartment(QWidget *parent = nullptr);
    ~InsertDepartment();

private:
    Ui::InsertDepartment *ui;
};

#endif // INSERTDEPARTMENT_H
