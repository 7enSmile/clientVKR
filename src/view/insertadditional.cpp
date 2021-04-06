#include "view/insertadditional.h"
#include "ui_insertadditional.h"

InsertAdditional::InsertAdditional(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertAdditional)
{
    ui->setupUi(this);
    this->setWindowTitle("Дополнительно");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onActionClick()));
    m_activity.reset(new Activity());
    m_task.reset(new Task());
    m_collaboration.reset(new Collaboration());
}

InsertAdditional::~InsertAdditional()
{
    delete ui;
}

Activity_ptr InsertAdditional::getActivity()
{
    return m_activity;

}

Task_ptr InsertAdditional::getTask()
{
    return m_task;

}

Collaboration_ptr InsertAdditional::getCollaboration()
{
    return m_collaboration;

}

void InsertAdditional::onActionClick()
{
    QString name;
    QString description;
    name=ui->lineEdit->text();
    description=ui->textEditDescription->toPlainText().trimmed();
    m_activity->setname(name);
    m_activity->setdescription(description);
    m_task->setname(name);
    m_task->setdescription(description);
    m_collaboration->setname(name);
    m_collaboration->setdescription(description);
    QDialog::accept();
}
