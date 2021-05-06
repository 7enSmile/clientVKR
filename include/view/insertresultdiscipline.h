#ifndef INSERTRESULTDISCIPLINE_H
#define INSERTRESULTDISCIPLINE_H

#include <QDialog>

namespace Ui {
class InsertResultDiscipline;
}

class InsertResultDiscipline : public QDialog
{
    Q_OBJECT

public:
    explicit InsertResultDiscipline(QWidget *parent = nullptr);
    ~InsertResultDiscipline();

private:
    Ui::InsertResultDiscipline *ui;
};

#endif // INSERTRESULTDISCIPLINE_H
