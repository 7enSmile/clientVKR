#ifndef INSERTDISCIPLINE_H
#define INSERTDISCIPLINE_H

#include <QDialog>

namespace Ui {
class InsertDiscipline;
}

class InsertDiscipline : public QDialog
{
    Q_OBJECT

public:
    explicit InsertDiscipline(QWidget *parent = nullptr);
    ~InsertDiscipline();

private:
    Ui::InsertDiscipline *ui;
};

#endif // INSERTDISCIPLINE_H
