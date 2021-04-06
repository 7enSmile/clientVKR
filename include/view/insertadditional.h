#ifndef INSERTACTIVITY_H
#define INSERTACTIVITY_H

#include <QDialog>
#include "Activity.h"
#include "Collaboration.h"
namespace Ui {
class InsertAdditional;
}

class InsertAdditional : public QDialog
{
    Q_OBJECT

public:
    explicit InsertAdditional(QWidget *parent = nullptr);
    ~InsertAdditional();
    Activity_ptr getActivity();
    Task_ptr getTask();
    Collaboration_ptr getCollaboration();

private:
    Ui::InsertAdditional *ui;
    Activity_ptr m_activity;
    Task_ptr m_task;
    Collaboration_ptr m_collaboration;
private slots:
    void onActionClick();

};

#endif // INSERTACTIVITY_H
