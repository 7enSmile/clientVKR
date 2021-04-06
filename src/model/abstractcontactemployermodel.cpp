#include "model/abstractcontactemployermodel.h"

AbstractContactEmployerModel:: AbstractContactEmployerModel()
{
    loadListGlobal();

}

AbstractContactEmployerModel::AbstractContactEmployerModel(ListOfContactEmployer &list)
{
    m_listContactEmployer=list;

}

int AbstractContactEmployerModel::rowCount(const QModelIndex &parent) const
{
     return !parent.isValid() ? m_listContactEmployer.count() : 0;

}

int AbstractContactEmployerModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractContactEmployerModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        {

            if (index.column() == 0)
            {


               QString title;
               QString firstname;
               QString lastname;
               QString patronymic;
               firstname=m_listContactEmployer.getByIndex(index.row())->getperson()->getfirstname();
               lastname=m_listContactEmployer.getByIndex(index.row())->getperson()->getlastname();
               patronymic=m_listContactEmployer.getByIndex(index.row())->getperson()->getpatronymic();
               title=lastname+" "+firstname+" "+patronymic;
               return title;
            }

        }

        return QVariant();

}

void AbstractContactEmployerModel::deleteContactEmployerGlobal(int index)
{
    Person_ptr person;
    person.reset(new Person());
    person->setperson_id(m_listContactEmployer.getByIndex(index)->getperson()->getperson_id());
    qx::dao::delete_by_id(person);
    loadListGlobal();
    layoutChanged();

}

void AbstractContactEmployerModel::deleteContactEmployerLocal(int index)
{
    m_listContactEmployer.removeByIndex(index);
    layoutChanged();

}

void AbstractContactEmployerModel::saveContactEmployerGlobal(ContactEmployer_ptr contactEmployer)
{
    qx::dao::save_with_all_relation(contactEmployer);
    loadListGlobal();
    layoutChanged();

}

void AbstractContactEmployerModel::saveContactEmployerLocal(ContactEmployer_ptr contact)
{
    m_listContactEmployer.insert( m_listContactEmployer.count(), contact);
    layoutChanged();


}

void AbstractContactEmployerModel::changeContactEmployerLocal(int index, long key, ContactEmployer_ptr contact)
{

    m_listContactEmployer.replace(index,key,contact);
    layoutChanged();

}

ContactEmployer_ptr AbstractContactEmployerModel::getContactEmployer(int index)
{
    ContactEmployer_ptr contactEmployer;
    contactEmployer.reset(new ContactEmployer());
    contactEmployer=m_listContactEmployer.getByIndex(index);
    return contactEmployer;

}

ListOfContactEmployer &AbstractContactEmployerModel::getListContactEmployer()
{
    return m_listContactEmployer;


}

void AbstractContactEmployerModel::loadListGlobal()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listContactEmployer);
    endInsertRows();
    qx::dao::fetch_all(m_listEmployers);
    layoutChanged();

}
