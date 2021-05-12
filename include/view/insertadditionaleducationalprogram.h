#ifndef INSERTADDITIONALEDUCATIONALPROGRAM_H
#define INSERTADDITIONALEDUCATIONALPROGRAM_H

#include <QDialog>
#include "Educational_program.h"
#include "Practice.h"
#include "model/abstractdisciplinemodel.h"
#include "view/insertdiscipline.h"
#include "view/searchpractice.h"


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
     ListOfPractice& getListPractice();

private:
    Ui::InsertAdditionalEducationalProgram *ui;
    AbstractDisciplineModel *m_modelDescipline;
    AbstractPracticeModel *m_modelPractice;

private slots:
    void onActionClicked();
    void onOkClicked();
    void onInsertDisciplineClicked();
    void onDeleteDisciplineClicked();
    void onTableDisciplineClicked();
    void onInsertPracticeClicked();
    void onDeletePracticeClicked();
};

#endif // INSERTADDITIONALEDUCATIONALPROGRAM_H
