#include "view/inserdiscipline.h"
#include "ui_inserdiscipline.h"

InserDiscipline::InserDiscipline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InserDiscipline)
{
    ui->setupUi(this);
}

InserDiscipline::~InserDiscipline()
{
    delete ui;
}
