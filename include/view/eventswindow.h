#ifndef EVENTSWINDOW_H
#define EVENTSWINDOW_H

#include <QDialog>

namespace Ui {
class EventsWindow;
}

class EventsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EventsWindow(QWidget *parent = nullptr);
    ~EventsWindow();

private:
    Ui::EventsWindow *ui;
};

#endif // EVENTSWINDOW_H
