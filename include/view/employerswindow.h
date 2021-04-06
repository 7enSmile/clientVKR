#ifndef EMPLOYERSWINDOW_H
#define EMPLOYERSWINDOW_H

#include <QDialog>
#include "Employer.h"
#include "model/abstractcontactemployermodel.h"
#include "model/abstractheademployermodel.h"

namespace Ui {
class EmployersWindow;
}

class EmployersWindow : public QDialog
{
    Q_OBJECT

public:
    EmployersWindow(Employer_ptr,QWidget *parent = nullptr);
    EmployersWindow(QWidget *parent = nullptr);
    ~EmployersWindow();

private:
    Ui::EmployersWindow *ui;
    Employer_ptr m_employer;
    AbstractContactEmployerModel *m_modelContactemployer;
    AbstractHeadEmployerModel *m_modelHeadEmployerModel;
};

#endif // EMPLOYERSWINDOW_H
