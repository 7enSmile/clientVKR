#ifndef RESULTDISCIPLINEWINDOW_H
#define RESULTDISCIPLINEWINDOW_H

#include <QDialog>
#include "Result_education.h"
#include "model/abstractresultdisciplinemodel.h"
#include "view/insertresultdiscipline.h"

namespace Ui {
class ResultDisciplineWindow;
}

class ResultDisciplineWindow : public QDialog
{
    Q_OBJECT

public:
    ResultDisciplineWindow(ListOfResultEducation,QWidget *parent = nullptr);
    ~ResultDisciplineWindow();
    ListOfResultEducation& getList();

private:
    Ui::ResultDisciplineWindow *ui;
    AbstractResultDisciplineModel *m_modelResult;
private slots:
    void onOkClicked();
    void onActionClicked();
    void onInsertClicked();
    void onTableResultClicked();
    void onDeleteclicked();



};

#endif // RESULTDISCIPLINEWINDOW_H
