#include "model/abstractstaffuniversitymodel.h"

AbstractStaffUniversityModel::AbstractStaffUniversityModel()
{
    loadListGlobal();
}

AbstractStaffUniversityModel::AbstractStaffUniversityModel(ListOfHeadUniversity &list)
{
    m_listStaffUniversity=list;

}

int AbstractStaffUniversityModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listStaffUniversity.count() : 0;
}

int AbstractStaffUniversityModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;
}

QVariant AbstractStaffUniversityModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        {

            if (index.column() == 0)
            {


               QString title;
               QString firstname;
               QString lastname;
               QString patronymic;
               firstname=m_listStaffUniversity.getByIndex(index.row())->getperson()->getfirstname();
               lastname=m_listStaffUniversity.getByIndex(index.row())->getperson()->getlastname();
               patronymic=m_listStaffUniversity.getByIndex(index.row())->getperson()->getpatronymic();
               title=lastname+" "+firstname+" "+patronymic;
               return title;
            }

        }

        return QVariant();

}

void AbstractStaffUniversityModel::deleteStaffUniversityGlobal(int index)
{
    Person_ptr person;
    person.reset(new Person());
    person->setperson_id(m_listStaffUniversity.getByIndex(index)->getperson()->getperson_id());
    qx::dao::delete_by_id(person);
    loadListGlobal();
    layoutChanged();

}

void AbstractStaffUniversityModel::deleteStaffUniversityLocal(int index)
{
    m_listStaffUniversity.removeByIndex(index);
    layoutChanged();
}

void AbstractStaffUniversityModel::changeStaffUniversityLocal(int index,long key,HeadUniversity_ptr staff)
{
    m_listStaffUniversity.replace(index,key,staff);
    layoutChanged();


}

void AbstractStaffUniversityModel::saveStaffUniversityGlobal(HeadUniversity_ptr staffUniversity)
{
    qx::dao::save_with_all_relation(staffUniversity);
    loadListGlobal();
    layoutChanged();


}

void AbstractStaffUniversityModel::saveStaffUniversityLocal(HeadUniversity_ptr staff)
{
    m_listStaffUniversity.insert(m_listStaffUniversity.count(),staff);
    layoutChanged();

}

HeadUniversity_ptr AbstractStaffUniversityModel::getStaffUniversity(int index)
{
    HeadUniversity_ptr staffUniversity;
    staffUniversity.reset(new HeadUniversity);
    staffUniversity=m_listStaffUniversity.getByIndex(index);
    return staffUniversity;
}

ListOfHeadUniversity &AbstractStaffUniversityModel::getListStaff()
{
    return m_listStaffUniversity;

}

void AbstractStaffUniversityModel::loadListGlobal()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listStaffUniversity);
    endInsertRows();
    layoutChanged();
}
