#include "view/insertevent.h"
#include "ui_insertevent.h"

InsertEvent::InsertEvent(ListOfEmployer list,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertEvent)
{
    ui->setupUi(this);
    m_event.reset(new Events);
    m_listEmployers=list;
    init();


    this->setWindowTitle("Мероприятие");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

InsertEvent::InsertEvent(ListOfEmployer list,Events_ptr event,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertEvent)
{
    ui->setupUi(this);
    m_event.reset(new Events);
    m_event=event;
    m_listEmployers=list;
    init();

    ui->pushButton->setText("Изменить");
    ui->pushButtonOk->setText("Ok");
    ui->comboBox->setCurrentText(m_event->getemployer()->getname());
    ui->lineEditName->setText(m_event->getname());
    ui->textEditDescription->setText(m_event->getdescription());
    ui->dateEditBegin->setDate(m_event->getbegin());
    ui->dateEditEnding->setDate(m_event->getending());
    this->setWindowTitle("Мероприятие");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);


}

Events_ptr InsertEvent::getEvent()
{
    return m_event;

}

InsertEvent::~InsertEvent()
{
    delete ui;
}

void InsertEvent::init()
{




    for(int i=0;i<m_listEmployers.count();i++){
        ui->comboBox->addItem(m_listEmployers.getByIndex(i)->getname());
    }
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onCancelClicked()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onActictionClicked()));

}

void InsertEvent::onActictionClicked()
{
    m_event->setbegin(ui->dateEditBegin->date());
    m_event->setending(ui->dateEditEnding->date());
    m_event->setname(ui->lineEditName->text());
    m_event->setdescription(ui->textEditDescription->toPlainText());
    m_event->setemployer(m_listEmployers.getByIndex(ui->comboBox->currentIndex()));
    QDialog::accept();

}

void InsertEvent::onCancelClicked()
{
    QDialog::close();

}
