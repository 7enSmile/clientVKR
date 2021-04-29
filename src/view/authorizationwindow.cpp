#include "view/authorizationwindow.h"
#include "ui_authorizationwindow.h"

AuthorizationWindow::AuthorizationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorizationWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Вход в систему");
    connect(ui->pushButtonAdministator,SIGNAL(clicked()),this,SLOT(onAdministrationClicked()));
    connect(ui->pushButtonEnter,SIGNAL(clicked()),this,SLOT(onEnterClicked()));

}

AuthorizationWindow::~AuthorizationWindow()
{
    delete ui;
}

void AuthorizationWindow::onEnterClicked()
{
    if(m_modelAuth.checkUser(ui->lineEditLogin->text(),ui->lineEditPassword->text())){

        MainWindow *w=new MainWindow();
        QDialog::close();
        w->show();


    }else{

         QMessageBox::critical(this,"Ошибка",m_modelAuth.getError());
    }

}

void AuthorizationWindow::onAdministrationClicked()

{
    bool ok;
    QString password = QInputDialog::getText(this, tr("Введите пароль"),tr("Пароль:"), QLineEdit::Password,"", &ok,Qt::WindowCloseButtonHint);
    if (ok && !password.isEmpty()){
        if(m_modelAuth.checkAdmin(password)){
            AdminWindow *w=new AdminWindow();
            QDialog::close();
            w->exec();

        }else{

            QMessageBox::critical(this,"Ошибка",m_modelAuth.getError());
        }
    }

}


