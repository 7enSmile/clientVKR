#ifndef STAFFEMPLOYERWINDOW_H
#define STAFFEMPLOYERWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "view/insertstaffemployer.h"
#include"model/abstractheademployermodel.h"
#include"model/abstractcontactemployermodel.h"

namespace Ui {
class StaffEmployerWindow;
}

class StaffEmployerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StaffEmployerWindow(QWidget *parent = nullptr);
    ~StaffEmployerWindow();
private slots:
    void onDeleteHeadEmployerClicked();
    void onInsertHeadEmployerClicked();
    void onTableHeadEmployerClicked();
    void onDeleteContactEmployerClicked();
    void onInsertContactEmployerClicked();
    void onTableContactEmployerClicked();
    void onOkClicked();
private:
    Ui::StaffEmployerWindow *ui;
    AbstractContactEmployerModel *m_modelContactEmployer;
    AbstractHeadEmployerModel *m_modelHeadEmployer;
};

#endif // STAFFEMPLOYERWINDOW_H
