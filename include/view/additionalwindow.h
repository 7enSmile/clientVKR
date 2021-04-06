#ifndef ADDITIONALWINDOW_H
#define ADDITIONALWINDOW_H

#include <QDialog>
#include "Employer.h"
#include "model/abstractactivitymodel.h"
#include "view/insertadditional.h"
#include"model/abstractcollaborationmodel.h"
#include "model/abstracttasksmodel.h"
namespace Ui {
class AdditionalWindow;
}

class AdditionalWindow : public QDialog
{
    Q_OBJECT

public:
    AdditionalWindow(Employer_ptr,QWidget *parent = nullptr);
    ~AdditionalWindow();
    ListOfActivity getListActivity();
    ListOfTask getListTasks();
    ListOfCollaboration getListCollaboration();

private:
    Ui::AdditionalWindow *ui;
    AbstractActivityModel *m_modelActivity;
    AbstractCollaborationModel *m_modelCollaboration;
    AbstractTasksModel *m_modelTask;


private slots:
    void onActivityTableClicked();
    void onCollaborationTableClicked();
    void onTasksTableClicked();
    void onActionClicked();
    void onInsertActivityClicked();
    void onInsertCollaborationClicked();
    void onInsertTasksClicked();
    void onDeleteActivityClicked();
    void onDeleteTasksClicked();
    void onDeleteCollaborationClicked();


};

#endif // ADDITIONALWINDOW_H
