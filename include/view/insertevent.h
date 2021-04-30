#ifndef INSEREVENT_H
#define INSEREVENT_H

#include <QDialog>
#include "Event.h"
#include "model/abstractemployermodel.h"

namespace Ui {
class InsertEvent;
}

class InsertEvent : public QDialog
{
    Q_OBJECT

public:
    InsertEvent(ListOfEmployer,QWidget *parent = nullptr);
    InsertEvent(ListOfEmployer,Events_ptr,QWidget *parent = nullptr);
    Events_ptr getEvent();

    ~InsertEvent();

private:

    Ui::InsertEvent *ui;
    Events_ptr m_event;
    ListOfEmployer m_listEmployers;
    void init();
private slots:
    void onActictionClicked();
    void onCancelClicked();

};

#endif // INSEREVENT_H
