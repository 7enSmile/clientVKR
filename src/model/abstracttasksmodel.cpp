#include "model/abstracttasksmodel.h"

AbstractTasksModel::AbstractTasksModel(ListOfTask listTasks)
{
    m_listLocalTask=listTasks;
    loadGlobalList();


}

int AbstractTasksModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listGlobalTask.count() : 0;

}

int AbstractTasksModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractTasksModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){

        if (index.column() == 0){

            return m_listGlobalTask.getByIndex(index.row())->getname();
        }

    }
    if (role==Qt::ToolTipRole){

        return m_listGlobalTask.getByIndex(index.row())->getdescription();

    }
    if(role==Qt::BackgroundColorRole){
        long key=m_listGlobalTask.getByIndex(index.row())->getTask_id();
        if(m_listLocalTask.contains(key)){
            return QBrush(Qt::lightGray);
        }
    }


    return QVariant();

}

void AbstractTasksModel::insertGlobalTask(Task_ptr task)
{
    qx::dao::save_with_all_relation(task);
    loadGlobalList();
    layoutChanged();


}

void AbstractTasksModel::deleteGlobal(int index)
{
    qx::dao::delete_by_id(m_listGlobalTask.getByIndex(index));
    if(m_listLocalTask.contains(m_listGlobalTask.getByIndex(index)->getTask_id())){
        m_listLocalTask.removeByKey(m_listGlobalTask.getByIndex(index)->getTask_id());
    }
    loadGlobalList();
    layoutChanged();

}

void AbstractTasksModel::action(int index)
{
    Task_ptr task;
    task.reset(new Task());
    task=m_listGlobalTask.getByIndex(index);
    if(m_listLocalTask.contains(task->getTask_id())){
        m_listLocalTask.removeByKey(task->getTask_id());

    }else{
        m_listLocalTask.insert(task->getTask_id(),task);

    }
    layoutChanged();

}

ListOfTask AbstractTasksModel::getTask()
{
    return m_listLocalTask;

}

void AbstractTasksModel::loadGlobalList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listGlobalTask);
    endInsertRows();
    layoutChanged();
}

