#ifndef EMPLOYERSWINDOW_H
#define EMPLOYERSWINDOW_H

#include <QDialog>
#include "Employer.h"
#include "model/abstractcontactemployermodel.h"
#include "model/abstractheademployermodel.h"
#include "view/insertstaffemployer.h"
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
    Employer_ptr getEmployer();

private:
    Ui::EmployersWindow *ui;
    Employer_ptr m_employer;
    AbstractContactEmployerModel *m_modelContactemployer;
    AbstractHeadEmployerModel *m_modelHeadEmployerModel;
private slots:
    void onInsertHeadEmployerClicked();
    void onTableHeadEmployerClicked();
    void onDeleteHeadEmployerClicked();
    void onActionClicked();
    void onInsertContactEmployerClicked();
    void onTableContactClicked();
    void onDeleteContactClicked();




};

#endif // EMPLOYERSWINDOW_H
