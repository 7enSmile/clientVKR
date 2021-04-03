#ifndef STAFFEMPLOYERWINDOW_H
#define STAFFEMPLOYERWINDOW_H

#include <QDialog>
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
    void onDeleteHeadEmployer();
    void onInsertHeadEmployer();
    void onTableHeadEmployerClicked();
    void onDeleteContactEmployerClicket();
    void onInsertContactEmployerClicket();
    void onTableContactEmployerClicked();
    void onOkClicked();
private:
    Ui::StaffEmployerWindow *ui;
    AbstractContactEmployerModel *m_modelContactEmployer;
    AbstractHeadEmployerModel *m_modelHeadEmployer;
};

#endif // STAFFEMPLOYERWINDOW_H
