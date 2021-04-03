#include "model/abstractstaffuniversitymodel.h"

AbstractStaffUniversityModel::AbstractStaffUniversityModel()
{
    loadList();
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

void AbstractStaffUniversityModel::deleteStaffUniversity(int index)
{
    Person_ptr person;
    person.reset(new Person());
    person->setperson_id(m_listStaffUniversity.getByIndex(index)->getperson()->getperson_id());
    qx::dao::delete_by_id(person);
    loadList();
    layoutChanged();

}

void AbstractStaffUniversityModel::saveStaffUniversity(HeadUniversity_ptr staffUniversity)
{
    qx::dao::save_with_all_relation(staffUniversity);
    loadList();
    layoutChanged();


}

HeadUniversity_ptr AbstractStaffUniversityModel::getStaffUniversity(int index)
{
    HeadUniversity_ptr staffUniversity;
    staffUniversity.reset(new HeadUniversity);
    staffUniversity=m_listStaffUniversity.getByIndex(index);
    return staffUniversity;
}

void AbstractStaffUniversityModel::loadList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listStaffUniversity);
    endInsertRows();
    layoutChanged();
}
