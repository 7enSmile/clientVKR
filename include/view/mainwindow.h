#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QDebug>
#include "view/studentswindow.h"
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
private slots:
    void onEventsClicked();
    void onEducationProgramsClicked();
    void onStudentsClicked();
    void onStaffEmployerClicked();
    void onStaffUniversityClicked();
    void onExitClicked();

};

#endif // MAINWINDOW_H
