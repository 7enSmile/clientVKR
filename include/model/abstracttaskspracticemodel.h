#include <qabstractitemmodel.h>
#include "Task_practice.h"
#ifndef ABSTRACTTASKSPRACTICEMODEL_H
#define ABSTRACTTASKSPRACTICEMODEL_H
#include <qbrush.h>

class AbstractTasksPracticeModel:public QAbstractTableModel
{
public:

    AbstractTasksPracticeModel(TaskPractice_ptr);

    TaskPractice_ptr gettask();

    void insertTaskLocal(int);

    void insertTaskGlobal(TaskPractice_ptr);

    void deleteTask(int);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;


private:

    ListOfTaskPractice m_listTasksPractice;
    TaskPractice_ptr m_taskInserted;
    void loadList();
};

#endif // ABSTRACTTASKSPRACTICEMODEL_H
