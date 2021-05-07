#ifndef INSERTADDITIONALEDUCATIONALPROGRAM_H
#define INSERTADDITIONALEDUCATIONALPROGRAM_H

#include <QDialog>
#include "Educational_program.h"
#include "model/abstractdisciplinemodel.h"
#include "view/insertdiscipline.h"


namespace Ui {
class InsertAdditionalEducationalProgram;
}

class InsertAdditionalEducationalProgram : public QDialog
{
    Q_OBJECT

public:
     InsertAdditionalEducationalProgram(ListOfDiscipline,ListOfPractice,ListOfStudent,QWidget *parent = nullptr);
    ~InsertAdditionalEducationalProgram();
     ListOfDiscipline& getListDiscipline();

private:
    Ui::InsertAdditionalEducationalProgram *ui;
    AbstractDisciplineModel *m_modelDescipline;
private slots:
    void onActionClicked();
    void onOkClicked();
    void onInsertDisciplineClicked();
    void onDeleteDisciplineClicked();
    void onTableDisciplineClicked();
};

#endif // INSERTADDITIONALEDUCATIONALPROGRAM_H
