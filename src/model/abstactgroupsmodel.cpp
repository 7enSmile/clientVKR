#include "model/abstactgroupsmodel.h"

void AbstactGroupsModel::loadList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listGroup);
    endInsertRows();
}

AbstactGroupsModel::AbstactGroupsModel()
{
    loadList();
}

int AbstactGroupsModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listGroup.count() : 0;
}

int AbstactGroupsModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;
}

QVariant AbstactGroupsModel::data(const QModelIndex &index, int role) const
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

void AbstactGroupsModel::deleteGroup(int index)
{
    Group_ptr group;
    group.reset(new Group);
    group->setgroup_id(m_listGroup.getByIndex(index)->getgroup_id());
    qx::dao::delete_by_id(group);
    loadList();
    layoutChanged();

}

void AbstactGroupsModel::saveGroup(Group_ptr group)
{
    qx::dao::save_with_all_relation(group);
    loadList();
    layoutChanged();
}

ListOfGroup &AbstactGroupsModel::getList()
{
    return m_listGroup;
}

Group_ptr AbstactGroupsModel::getGroup(int index)
{
    Group_ptr group;
    group.reset(new Group());
    group=m_listGroup.getByIndex(index);
    return group;
}
