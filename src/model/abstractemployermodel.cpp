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

void AbstractEmployerModel::deleteEmployer(int index)
{

    qx::dao::delete_by_id(m_listEmployer.getByIndex(index));
    loadList();

}

void AbstractEmployerModel::saveEmployer(Employer_ptr employer)
{
    ListOfHeadEmployer listHeadEmployer=employer->getlist_of_head_employer();
    ListOfContactEmployer listContactEmployer=employer->getlist_of_contact_employer();
    for(int i=0;i<listHeadEmployer.count();i++){
        qx::dao::save_with_all_relation(listHeadEmployer.getByIndex(i));

    }
    for(int i=0;i<listContactEmployer.count();i++){
        qx::dao::save_with_all_relation(listContactEmployer.getByIndex(i));

    }
    qx::dao::save_with_all_relation(employer);
}

Employer_ptr AbstractEmployerModel::getEmployer(int index)
{
    return m_listEmployer.getByIndex(index);

}

ListOfEmployer &AbstractEmployerModel::getList()
{
    return m_listEmployer;

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
    QStringList relation;
    relation.append("list_of_activity");
    relation.append("list_of_collaboration");
    relation.append("list_of_task");
    relation.append("list_of_head_employer");
    relation.append("list_of_contact_employer");
    relation.append("list_of_result_education");
    qx::dao::fetch_all_with_relation(relation,m_listEmployer);
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

    m_listEmployer.sortByKey();
    endInsertRows();
    layoutChanged();

}

QVariant AbstractEmployerModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("????????????????????????");

        }
    }

    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {

        return section+1;
    }
    return QVariant();

}




