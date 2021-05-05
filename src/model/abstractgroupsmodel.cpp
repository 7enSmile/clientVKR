#include "model/abstractgroupsmodel.h"

void AbstractGroupsModel::loadList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listGroup);
    m_listGroup.sortByKey();
    endInsertRows();
    layoutChanged();

}

AbstractGroupsModel::AbstractGroupsModel()
{
    loadList();
}

int AbstractGroupsModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listGroup.count() : 0;
}

int AbstractGroupsModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;
}

QVariant AbstractGroupsModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {

        if (index.column() == 0)
        {



           return m_listGroup.getByIndex(index.row())->getnumber();
        }

    }

    return QVariant();

}

void AbstractGroupsModel::deleteGroup(int index)
{
    Group_ptr group;
    group.reset(new Group());
    group->setgroup_id(m_listGroup.getByIndex(index)->getgroup_id());
    qx::dao::delete_by_id(group);
    loadList();
    layoutChanged();

}

void AbstractGroupsModel::saveGroup(Group_ptr group)
{
    qx::dao::save_with_all_relation(group);
    loadList();
    layoutChanged();
}

ListOfGroup &AbstractGroupsModel::getList()
{
    return m_listGroup;
}

Group_ptr AbstractGroupsModel::getGroup(int index)
{
    Group_ptr group;
    group.reset(new Group());
    group=m_listGroup.getByIndex(index);
    return group;
}
