#include "model/abstractactivitymodel.h"





AbstractActivityModel::AbstractActivityModel(ListOfActivity listActivity)
{
    m_listLocalActivity=listActivity;
    loadGlobalList();


}

int AbstractActivityModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listGlobalActivity.count() : 0;

}

int AbstractActivityModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractActivityModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){

        if (index.column() == 0){

            return m_listGlobalActivity.getByIndex(index.row())->getname();
        }

    }
    if (role==Qt::ToolTipRole){

        return m_listGlobalActivity.getByIndex(index.row())->getdescription();

    }
    if(role==Qt::BackgroundColorRole){
        long key=m_listGlobalActivity.getByIndex(index.row())->getactivity_id();
        if(m_listLocalActivity.contains(key)){
            return QBrush(Qt::lightGray);
        }
    }


    return QVariant();

}

void AbstractActivityModel::insertGlobalActivity(Activity_ptr activity)
{
    qx::dao::save_with_all_relation(activity);
    loadGlobalList();
    layoutChanged();


}

void AbstractActivityModel::deleteGlobal(int index)
{
    qDebug()<<"Delete";
    qx::dao::delete_by_id(m_listGlobalActivity.getByIndex(index));
    if(m_listLocalActivity.contains(m_listGlobalActivity.getByIndex(index)->getactivity_id())){
        m_listLocalActivity.removeByKey(m_listGlobalActivity.getByIndex(index)->getactivity_id());
    }
    loadGlobalList();
    layoutChanged();

}

void AbstractActivityModel::action(int index)
{
    Activity_ptr activity;
    activity.reset(new Activity());
    activity=m_listGlobalActivity.getByIndex(index);
    if(m_listLocalActivity.contains(activity->getactivity_id())){
        m_listLocalActivity.removeByKey(activity->getactivity_id());

    }else{
        m_listLocalActivity.insert(activity->getactivity_id(),activity);

    }
    layoutChanged();

}

ListOfActivity AbstractActivityModel::getActivity()
{
    return m_listLocalActivity;

}

void AbstractActivityModel::loadGlobalList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listGlobalActivity);
    endInsertRows();
    layoutChanged();
}
