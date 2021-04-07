#include "view/insertevent.h"
#include "ui_inserevent.h"

InsertEvent::InsertEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertEvent)
{
    ui->setupUi(this);
}

InsertEvent::~InsertEvent()
{
    delete ui;
}
