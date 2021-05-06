#ifndef EDUCATIONALPROGRAMWINDOW_H
#define EDUCATIONALPROGRAMWINDOW_H

#include <QDialog>

namespace Ui {
class EducationalProgramWindow;
}

class EducationalProgramWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EducationalProgramWindow(QWidget *parent = nullptr);
    ~EducationalProgramWindow();

private:
    Ui::EducationalProgramWindow *ui;
};

#endif // EDUCATIONALPROGRAMWINDOW_H
