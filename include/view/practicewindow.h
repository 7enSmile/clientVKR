#ifndef PRACTICEWINDOW_H
#define PRACTICEWINDOW_H

#include <QDialog>
#include "Practice.h"
#include "Employer.h"
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
    void iniconnection();
    void initElementsChange();
    void initElementInsert();
private slots:
    void onOkClicked();
    void onActionClicked();
};

#endif // PRACTICEWINDOW_H
