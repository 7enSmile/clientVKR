#ifndef INSERTDISCIPLINE_H
#define INSERTDISCIPLINE_H

#include <QDialog>
#include "Discipline.h"
#include "view/resultdisciplinewindow.h"

namespace Ui {
class InsertDiscipline;
}

class InsertDiscipline : public QDialog
{
    Q_OBJECT

public:
    InsertDiscipline(QWidget *parent = nullptr);
    InsertDiscipline(Discipline_ptr,QWidget *parent = nullptr);
    Discipline_ptr getDiscipline();
    ~InsertDiscipline();


private:
    Ui::InsertDiscipline *ui;
    Discipline_ptr m_discipline;
    void initconnection();
private slots:
    void onOkClicked();
    void onActionClicked();
    void onResultClicked();

};

#endif // INSERTDISCIPLINE_H
