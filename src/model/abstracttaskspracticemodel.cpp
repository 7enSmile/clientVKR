#include "model/abstracttaskspracticemodel.h"





AbstractTasksPracticeModel::AbstractTasksPracticeModel(TaskPractice_ptr task)
{
    m_taskInserted.reset(new TaskPractice());
    m_taskInserted=task;
    loadList();

}

TaskPractice_ptr AbstractTasksPracticeModel::gettask()
{
    return m_taskInserted;

}

void AbstractTasksPracticeModel::insertTaskLocal(int index)
{
    m_taskInserted=m_listTasksPractice.getByIndex(index);

}

void AbstractTasksPracticeModel::insertTaskGlobal(TaskPractice_ptr task)
{
    qx::dao::save_with_all_relation(task);
    loadList();
    layoutChanged();


}

void AbstractTasksPracticeModel::deleteTask(int index)
{
    qx::dao::delete_by_id(m_listTasksPractice.getByIndex(index));
    loadList();
    layoutChanged();
}

int AbstractTasksPracticeModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ?m_listTasksPractice.count() : 0;

}

int AbstractTasksPracticeModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractTasksPracticeModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){

        if (index.column() == 0){

            return m_listTasksPractice.getByIndex(index.row())->getname();
        }

    }
    if (role==Qt::ToolTipRole){

        return  m_listTasksPractice.getByIndex(index.row())->getdescription();

    }
    if(role==Qt::BackgroundColorRole){
        long key=m_listTasksPractice.getByIndex(index.row())->getTask_id();
        if(m_taskInserted!=nullptr){
            if(m_taskInserted->getTask_id()==key){
                return QBrush(Qt::lightGray);
            }
        }
    }


    return QVariant();

}

QVariant AbstractTasksPracticeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Задание");

        }
    }

    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {

        return section+1;
    }
    return QVariant();

}

void AbstractTasksPracticeModel::loadList()
{
    qx::dao::fetch_all_with_all_relation(m_listTasksPractice);
}
