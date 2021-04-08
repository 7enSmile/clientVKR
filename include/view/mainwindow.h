#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QDebug>
#include "view/studentswindow.h"
#include "view/staffuniversitywindow.h"
#include "view/staffemployerwindow.h"
#include "model/abstractemployermodel.h"
#include "view/employerswindow.h"
#include "model/abstractpracticemodel.h"
#include "view/practicewindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void addSubMenu();
    AbstractEmployerModel *m_modelEmployer;
    AbstractPracticeModel *m_modelPractice;
private slots:
    void onEventsClicked();
    void onEducationProgramsClicked();
    void onStudentsClicked();
    void onStaffEmployerClicked();
    void onStaffUniversityClicked();
    void onExitClicked();
    void onEmployersTableClicked();
    void onInsertEmployerClicked();
    void onPracticeTableClicked();
    void onInsertPracticeClicked();



};

#endif // MAINWINDOW_H
