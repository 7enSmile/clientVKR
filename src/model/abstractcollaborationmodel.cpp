#include "model/abstractcollaborationmodel.h"



AbstractCollaborationModel::AbstractCollaborationModel(ListOfCollaboration list)
{
    m_listLocalCollaboration=list;
    loadGlobalList();

}

int AbstractCollaborationModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listGlobalCollaboration.count() : 0;

}

int AbstractCollaborationModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractCollaborationModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){

        if (index.column() == 0){

            return m_listGlobalCollaboration.getByIndex(index.row())->getname();
        }

    }
    if (role==Qt::ToolTipRole){

        return m_listGlobalCollaboration.getByIndex(index.row())->getdescription();

    }
    if(role==Qt::BackgroundColorRole){
        long key=m_listGlobalCollaboration.getByIndex(index.row())->getcollaboration_id();
        if(m_listLocalCollaboration.contains(key)){
            return QBrush(Qt::lightGray);

        }
    }


    return QVariant();

}

void AbstractCollaborationModel::insertGlobalCollaboration(Collaboration_ptr collaboation)
{
    qx::dao::save_with_all_relation(collaboation);
    loadGlobalList();
    layoutChanged();

}

void AbstractCollaborationModel::deleteGlobal(int index)
{
    qx::dao::delete_by_id(m_listGlobalCollaboration.getByIndex(index));
    if(m_listLocalCollaboration.contains(m_listGlobalCollaboration.getByIndex(index)->getcollaboration_id())){
        m_listLocalCollaboration.removeByKey(m_listGlobalCollaboration.getByIndex(index)->getcollaboration_id());
    }
    loadGlobalList();
    layoutChanged();

}

void AbstractCollaborationModel::action(int index)
{
    Collaboration_ptr collaboration;
    collaboration.reset(new Collaboration());
    collaboration=m_listGlobalCollaboration.getByIndex(index);
    if(m_listLocalCollaboration.contains(collaboration->getcollaboration_id())){
        m_listLocalCollaboration.removeByKey(collaboration->getcollaboration_id());

    }else{
         m_listLocalCollaboration.insert(collaboration->getcollaboration_id(),collaboration);

    }
    layoutChanged();

}

ListOfCollaboration AbstractCollaborationModel::getCollaboration()
{
     return m_listLocalCollaboration;

}

void AbstractCollaborationModel::loadGlobalList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listGlobalCollaboration);
    m_listGlobalCollaboration.sortByKey();
    endInsertRows();
    layoutChanged();
}
