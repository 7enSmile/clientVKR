#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QDialog>
#include <QInputDialog>
#include "model/checkauthorizationmodel.h"
#include "view/adminwindow.h"
#include <QMessageBox>
#include "view/mainwindow.h"

namespace Ui {
class AuthorizationWindow;
}

class AuthorizationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorizationWindow(QWidget *parent = nullptr);
    ~AuthorizationWindow();

private:
    Ui::AuthorizationWindow *ui;

    CheckAuthorizationModel m_modelAuth;
private slots:

    void onEnterClicked();
    void onAdministrationClicked();

};

#endif // AUTHORIZATIONWINDOW_H
