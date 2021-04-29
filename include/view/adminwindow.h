#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "model/abstractusersmodel.h"
#include "view/insertuser.h"
#include <QInputDialog>
namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private:
    Ui::AdminWindow *ui;
    AbstractUsersModel *m_modelUsers;
private slots:
    void onDeleteClicked();
    void onInsertUserCkicked();
    void onTableUsersClicked();
};

#endif // ADMINWINDOW_H
