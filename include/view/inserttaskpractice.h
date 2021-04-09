#ifndef INSERTTASKPRACTICE_H
#define INSERTTASKPRACTICE_H

#include <QDialog>
#include "Task_practice.h"

namespace Ui {
class InsertTaskPractice;
}

class InsertTaskPractice : public QDialog
{
    Q_OBJECT

public:
    explicit InsertTaskPractice(QWidget *parent = nullptr);
    ~InsertTaskPractice();
    TaskPractice_ptr getTaskPractice();




private:

    Ui::InsertTaskPractice *ui;
    TaskPractice_ptr m_taskPractice;

private slots:

    void onActionClicked();

    void onCancelClicked();


};

#endif // INSERTTASKPRACTICE_H
