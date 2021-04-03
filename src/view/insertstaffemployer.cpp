#include "view/insertstaffemployer.h"
#include "ui_insertstaffemployer.h"

InsertStaffEmployer::InsertStaffEmployer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertStaffEmployer)
{
    ui->setupUi(this);
}

InsertStaffEmployer::~InsertStaffEmployer()
{
    delete ui;
}
