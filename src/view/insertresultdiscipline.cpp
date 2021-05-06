#include "view/insertresultdiscipline.h"
#include "ui_insertresultdiscipline.h"

InsertResultDiscipline::InsertResultDiscipline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertResultDiscipline)
{
    ui->setupUi(this);
}

InsertResultDiscipline::~InsertResultDiscipline()
{
    delete ui;
}
