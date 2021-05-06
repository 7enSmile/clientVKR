#include "view/insertadditionaleducationalprogram.h"
#include "ui_insertadditionaleducationalprogram.h"

InsertAdditionalEducationalProgram::InsertAdditionalEducationalProgram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertAdditionalEducationalProgram)
{
    ui->setupUi(this);
}

InsertAdditionalEducationalProgram::~InsertAdditionalEducationalProgram()
{
    delete ui;
}
