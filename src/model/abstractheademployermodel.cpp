#include "model/abstractheademployermodel.h"

AbstractHeadEmployerModel::AbstractHeadEmployerModel()
{
    loadListGlobal();

}

AbstractHeadEmployerModel::AbstractHeadEmployerModel(ListOfHeadEmployer list)
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

    if(m_listHeadEmployer.getByIndex(index)->getHeadEmployer()!=0){
        Person_ptr person;
        person.reset(new Person());
        person->setperson_id(m_listHeadEmployer.getByIndex(index)->getperson()->getperson_id());
        qDebug()<<person->getperson_id();
        qx::dao::delete_by_id(person);
    }
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

void AbstractHeadEmployerModel::changeHeadEmployerLocal(int index, long key, HeadEmployer_ptr headEmployer)
{

    m_listHeadEmployer.replace(index,0,headEmployer);
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
    qx::dao::fetch_all(m_listEmployers);
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listHeadEmployer);
    endInsertRows();
    layoutChanged();

}

void AbstractHeadEmployerModel::search(QString searchName, QString searchLastname, QString searchEmployer)
{
    ListOfHeadEmployer list;
    m_listHeadEmployer._clear();
    qx::dao::fetch_all_with_all_relation(list);
    QRegExp regName("^"+searchName);
    QRegExp reglastname("^"+searchLastname);
    QRegExp regdemployer("^"+searchEmployer);
    QString name;
    QString lastname;
    QString employer;
    for(int i=0;i<list.count();i++){
        name=list.getByIndex(i)->getperson()->getfirstname();
        lastname=list.getByIndex(i)->getperson()->getlastname();
        employer=list.getByIndex(i)->getemployer()->getname();
        if(name.contains(regName)&&lastname.contains(reglastname)&&employer.contains(regdemployer)){
            m_listHeadEmployer.insert(list.getByIndex(i)->getHeadEmployer(),list.getByIndex(i));
        }
    }
    layoutChanged();


}
