#ifndef EMPLOYERSWINDOW_H
#define EMPLOYERSWINDOW_H

#include <QDialog>

namespace Ui {
class EmployersWindow;
}

class EmployersWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EmployersWindow(QWidget *parent = nullptr);
    ~EmployersWindow();

private:
    Ui::EmployersWindow *ui;
};

#endif // EMPLOYERSWINDOW_H
