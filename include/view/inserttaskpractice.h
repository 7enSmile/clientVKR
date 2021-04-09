#ifndef INSERTTASKPRACTICE_H
#define INSERTTASKPRACTICE_H

#include <QDialog>

namespace Ui {
class InsertTaskPractice;
}

class InsertTaskPractice : public QDialog
{
    Q_OBJECT

public:
    explicit InsertTaskPractice(QWidget *parent = nullptr);
    ~InsertTaskPractice();

private:
    Ui::InsertTaskPractice *ui;
};

#endif // INSERTTASKPRACTICE_H
