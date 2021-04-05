#include "model/abstractheademployermodel.h"

AbstractHeadEmployerModel::AbstractHeadEmployerModel()
{
    loadListGlobal();

}

AbstractHeadEmployerModel::AbstractHeadEmployerModel(ListOfHeadEmployer &list)
{
    m_listHeadEmployer=list;

}

int AbstractHeadEmployerModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listHeadEmployer.count() : 0;
}

int AbstractHeadEmployerModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;
}

QVariant AbstractHeadEmployerModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        {

            if (index.column() == 0)
            {


               QString title;
               QString firstname;
               QString lastname;
               QString patronymic;
               firstname=m_listHeadEmployer.getByIndex(index.row())->getperson()->getfirstname();
               lastname=m_listHeadEmployer.getByIndex(index.row())->getperson()->getlastname();
               patronymic=m_listHeadEmployer.getByIndex(index.row())->getperson()->getpatronymic();
               title=lastname+" "+firstname+" "+patronymic;
               return title;
            }

        }

    return QVariant();
}



void AbstractHeadEmployerModel::deleteHeadEmployerGlobal(int index)
{
    Person_ptr person;
    person.reset(new Person());
    person->setperson_id(m_listHeadEmployer.getByIndex(index)->getperson()->getperson_id());
    qx::dao::delete_by_id(person);
    loadListGlobal();
    layoutChanged();

}

void AbstractHeadEmployerModel::deleteHeadEmployerLocal(int index)
{
    m_listHeadEmployer.removeByIndex(index);
    layoutChanged();


}

void AbstractHeadEmployerModel::saveHeadEmployerGlobal(HeadEmployer_ptr headEmployer)
{
    qx::dao::save_with_all_relation(headEmployer);
    loadListGlobal();
    layoutChanged();

}

void AbstractHeadEmployerModel::saveHeadEmployerLocal(HeadEmployer_ptr headEmployer)
{
    m_listHeadEmployer.insert(m_listHeadEmployer.count(),headEmployer);
    layoutChanged();

}

void AbstractHeadEmployerModel::changeHeadEmployerLocal(int index, long key, HeadEmployer_ptr& headEmployer)
{
    m_listHeadEmployer.replace(index,key,headEmployer);
    layoutChanged();

}

HeadEmployer_ptr AbstractHeadEmployerModel::getHeadEmployer(int index)
{
    HeadEmployer_ptr headEmployer;
    headEmployer.reset(new HeadEmployer);
    headEmployer=m_listHeadEmployer.getByIndex(index);
    return headEmployer;

}

ListOfHeadEmployer &AbstractHeadEmployerModel::getListHeadEmployer()
{

    return m_listHeadEmployer;

}

void AbstractHeadEmployerModel::loadListGlobal()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listHeadEmployer);
    endInsertRows();
    layoutChanged();

}
