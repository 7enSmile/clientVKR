#ifndef EVENTSWINDOW_H
#define EVENTSWINDOW_H

#include <QDialog>
#include "model/abstracteventsmodel.h"
#include "view/insertevent.h"
#include "view/reporteventswindow.h"

namespace Ui {
class EventsWindow;
}

class EventsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EventsWindow(ListOfEmployer,QWidget *parent = nullptr);
    ~EventsWindow();

private:
    Ui::EventsWindow *ui;
    AbstractEventsModel *m_modelEvents;
    ListOfEmployer m_listEmployers;

private slots:
    void onDeleteClicked();
    void onInsertClicked();
    void onTableEventsClicked();
    void onReportClicked();
    void onOkClicked();
};

#endif // EVENTSWINDOW_H
