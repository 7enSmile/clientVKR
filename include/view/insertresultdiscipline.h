#ifndef INSERTRESULTDISCIPLINE_H
#define INSERTRESULTDISCIPLINE_H

#include <QDialog>
#include "Result_education.h"

namespace Ui {
class InsertResultDiscipline;
}

class InsertResultDiscipline : public QDialog
{
    Q_OBJECT

public:
    InsertResultDiscipline(ResultEducation_ptr,QWidget *parent = nullptr);
    InsertResultDiscipline(QWidget *parent = nullptr);
    ~InsertResultDiscipline();
    ResultEducation_ptr getResultDiscipline();

private:
    Ui::InsertResultDiscipline *ui;
    ResultEducation_ptr m_resultDiscipline;
private slots:
    void onOkClicked();
    void onActionClicked();
};

#endif // INSERTRESULTDISCIPLINE_H
