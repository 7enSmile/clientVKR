#include "model/abstractemployermodel.h"

AbstractEmployerModel::AbstractEmployerModel()
{
    loadList();

}

int AbstractEmployerModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listEmployer.count() : 0;

}

int AbstractEmployerModel::columnCount(const QModelIndex &parent) const
{
     return !parent.isValid() ? 1 : 0;

}

QVariant AbstractEmployerModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        {

            if (index.column() == 0)
            {
               return m_listEmployer.getByIndex(index.row())->getname();
            }

        }

        return QVariant();

}

void AbstractEmployerModel::deleteEmployer(int)
{

}

void AbstractEmployerModel::saveEmployer(Employer_ptr employer)
{


}

Employer_ptr AbstractEmployerModel::getEmployer(int index)
{
    return m_listEmployer.getByIndex(index);

}

void AbstractEmployerModel::loadList()
{
    ListOfPerson persons;
    Person_ptr person;
    person.reset(new Person());
    qx::dao::fetch_all_with_all_relation(persons);
    ListOfHeadEmployer listHeadEmployer;
    ListOfContactEmployer listContactEmployer;
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listEmployer);
    for(int i=0;i<m_listEmployer.count();i++){
        listHeadEmployer=m_listEmployer.getByIndex(i)->getlist_of_head_employer();
        listContactEmployer=m_listEmployer.getByIndex(i)->getlist_of_contact_employer();
        for(int j=0;j<listHeadEmployer.count();j++){
            person=persons.getByKey(listHeadEmployer.getByIndex(j)->getperson()->getperson_id());
            listHeadEmployer.getByIndex(j)->setperson(person);
        }
        for(int j=0;j<listContactEmployer.count();j++){
            person=persons.getByKey(listContactEmployer.getByIndex(j)->getperson()->getperson_id());
            listContactEmployer.getByIndex(j)->setperson(person);
        }
        m_listEmployer.getByIndex(i)->setlist_of_head_employer(listHeadEmployer);
        m_listEmployer.getByIndex(i)->setlist_of_contact_employer(listContactEmployer);
    }
    endInsertRows();
    layoutChanged();

}

ListOfHeadEmployer AbstractEmployerModel::getListHeadEmployer(int index)
{
    return m_listEmployer.getByIndex(index)->getlist_of_head_employer();

}

ListOfContactEmployer AbstractEmployerModel::getListContactEmployer(int index)
{

    return m_listEmployer.getByIndex(index)->getlist_of_contact_employer();
}


