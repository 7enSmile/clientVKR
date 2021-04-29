#include "view/adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Администратор");
    m_modelUsers=new AbstractUsersModel();
    ui->tableViewUsers->setModel(m_modelUsers);
    connect(ui->pushButtonDelete,SIGNAL(clicked()),this,SLOT(onDeleteClicked()));
    connect(ui->pushButtonInsert,SIGNAL(clicked()),this,SLOT(onInsertUserCkicked()));
    connect(ui->tableViewUsers,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableUsersClicked()));
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::onDeleteClicked()

{
    QModelIndexList index = ui->tableViewUsers->selectionModel()->selectedRows();
    if(index.count()>0){

        m_modelUsers->deleteUser(index[0].row());
    }
    ui->tableViewUsers->clearSelection();
    ui->tableViewUsers->clearFocus();

}

void AdminWindow::onInsertUserCkicked()
{
    InsertUser *w =new InsertUser();
    if(w->exec()==QDialog::Accepted){

        m_modelUsers->insertUser(w->getLogin(),w->getPassword());

    }


}

void AdminWindow::onTableUsersClicked()
{

    QModelIndexList index = ui->tableViewUsers->selectionModel()->selectedRows();
    bool ok;

    QString password = QInputDialog::getText(this, tr("Введите новый пароль"),tr("Пароль:"), QLineEdit::Password,"", &ok,Qt::WindowCloseButtonHint);
    if (ok && !password.isEmpty()){
        m_modelUsers->changePassword(index[0].row(),password);
    }
    ui->tableViewUsers->clearSelection();
    ui->tableViewUsers->clearFocus();

}
