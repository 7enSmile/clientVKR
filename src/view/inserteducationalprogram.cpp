#include "view/inserteducationalprogram.h"
#include "ui_inserteducationalprogram.h"

InsertEducationalProgram::InsertEducationalProgram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertEducationalProgram)
{
    ui->setupUi(this);
}

InsertEducationalProgram::~InsertEducationalProgram()
{
    delete ui;
}
