#include "view/insertdiscipline.h"
#include "ui_insertdiscipline.h"

InsertDiscipline::InsertDiscipline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertDiscipline)
{
    ui->setupUi(this);
}

InsertDiscipline::~InsertDiscipline()
{
    delete ui;
}
