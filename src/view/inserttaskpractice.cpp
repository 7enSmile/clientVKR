#include "view/inserttaskpractice.h"
#include "ui_inserttaskpractice.h"

InsertTaskPractice::InsertTaskPractice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertTaskPractice)
{
    ui->setupUi(this);
}

InsertTaskPractice::~InsertTaskPractice()
{
    delete ui;
}
