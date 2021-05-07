#ifndef PRACTICEWINDOW_H
#define PRACTICEWINDOW_H

#include <QDialog>
#include <QClipboard>
#include "Practice.h"
#include "Employer.h"
#include "model/abstractpassingpracticemodel.h"
#include "view/passingpracticewindow.h"
#include "model/abstactsubclassmodel.h"
namespace Ui {
class PracticeWindow;
}

class PracticeWindow : public QDialog
{
    Q_OBJECT

public:
    PracticeWindow(ListOfEmployer,QWidget *parent = nullptr);
    PracticeWindow(ListOfEmployer,Practice_ptr,QWidget *parent = nullptr);
    ~PracticeWindow();
    Practice_ptr getPractice();

private:
    Ui::PracticeWindow *ui;
    Practice_ptr m_practice;
    ListOfEmployer m_listEmployers;
    AbstractPassingPracticeModel *m_modelPassingPractice;
    void iniconnection();
    void initElementsChange();
    void initElementInsert();
    QString genCustomId();
private slots:
    void onOkClicked();
    void onActionClicked();
    void onTablePassingPracticeclicked();
    void onInsertPassingPracticeClicked();
    void onDeletePassingPractice();
    void onInsertTestClicked();
    void onGetTestClicked();
    void onDeleteTestClicked();
    void onGenClicked();
    void onCopyClicked();

};

#endif // PRACTICEWINDOW_H
