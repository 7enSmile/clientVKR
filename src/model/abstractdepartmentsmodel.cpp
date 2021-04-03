#include "model/abstractdepartmentsmodel.h"

void AbstractDepartmentsModel::loadList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listDepartment);
    endInsertRows();
    layoutChanged();
}

AbstractDepartmentsModel::AbstractDepartmentsModel()
{
    loadList();
}

int AbstractDepartmentsModel::rowCount(const QModelIndex &parent) const
{
     return !parent.isValid() ? m_listDepartment.count() : 0;
}

int AbstractDepartmentsModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;
}

QVariant AbstractDepartmentsModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {

        if (index.column() == 0)
        {
           return m_listDepartment.getByIndex(index.row())->getname();
        }

    }

    return QVariant();

}

void AbstractDepartmentsModel::deleteDepartment(int index)
{
    Department_ptr department;
    department.reset(new Department());
    department->setdepartment_id(m_listDepartment.getByIndex(index)->getdepartment_id());
    qx::dao::delete_by_id(department);
    loadList();
    layoutChanged();

}

void AbstractDepartmentsModel::saveDepartment(Department_ptr department)
{
    qx::dao::save_with_all_relation(department);
    loadList();
    layoutChanged();

}

Department_ptr AbstractDepartmentsModel::getDepartment(int index)
{
    Department_ptr department;
    department.reset(new Department());
    department=m_listDepartment.getByIndex(index);
    return department;

}

ListOfDepartment &AbstractDepartmentsModel::getList()
{
    return m_listDepartment;
}
