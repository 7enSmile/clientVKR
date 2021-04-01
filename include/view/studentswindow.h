#ifndef STUDENTSWINDOW_H
#define STUDENTSWINDOW_H

#include <QDialog>

namespace Ui {
class StudentsWindow;
}

class StudentsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StudentsWindow(QWidget *parent = nullptr);
    ~StudentsWindow();

private:
    Ui::StudentsWindow *ui;
};

#endif // STUDENTSWINDOW_H
