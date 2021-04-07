#ifndef INSEREVENT_H
#define INSEREVENT_H

#include <QDialog>

namespace Ui {
class InsertEvent;
}

class InsertEvent : public QDialog
{
    Q_OBJECT

public:
    explicit InsertEvent(QWidget *parent = nullptr);
    ~InsertEvent();

private:
    Ui::InsertEvent *ui;
};

#endif // INSEREVENT_H
