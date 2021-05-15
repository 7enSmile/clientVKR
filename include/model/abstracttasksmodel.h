#include <qabstractitemmodel.h>
#include "Task.h"
#include <QBrush>
#ifndef ABSTACTTASKSMODEL_H
#define ABSTACTTASKSMODEL_H


class AbstractTasksModel:public QAbstractTableModel
{
public:
    AbstractTasksModel(ListOfTask);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void insertGlobalTask(Task_ptr);

    void deleteGlobal(int);

    void action(int);



    ListOfTask getTask();
private:
    ListOfTask  m_listGlobalTask ;
    ListOfTask  m_listLocalTask ;
    void loadGlobalList();
};

#endif // ABSTACTTASKSMODEL_H
