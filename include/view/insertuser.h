#ifndef INSERTUSER_H
#define INSERTUSER_H

#include <QDialog>

namespace Ui {
class InsertUser;
}

class InsertUser : public QDialog
{
    Q_OBJECT

public:
    explicit InsertUser(QWidget *parent = nullptr);
    ~InsertUser();
public:
    QString getLogin();
    QString getPassword();





private:
    Ui::InsertUser *ui;
    QString m_login;
    QString m_password;
private slots:
    void onActionClicked();
    void onCancelCkicked();



};

#endif // INSERTUSER_H
