#include "model/abstractpracticemodel.h"

AbstractPracticeModel::AbstractPracticeModel()
{
    loadList();

}

int AbstractPracticeModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listPractice.count() : 0;

}

int AbstractPracticeModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractPracticeModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {

        if (index.column() == 0)
        {


            QString title;
            QString employer;
            QString databegin;
            QString dataending;
            employer=m_listPractice.getByIndex(index.row())->getemployer()->getname();
            databegin=m_listPractice.getByIndex(index.row())->getbeginning().toString("dd.MM.yy");
            dataending=m_listPractice.getByIndex(index.row())->getending().toString("dd.MM.yy");
            title=employer+"  "+databegin+" - "+dataending;
            return title;
        }

    }

    return QVariant();

}

void AbstractPracticeModel::deletePractice(int index)
{

}

void AbstractPracticeModel::savePractice(Practice_ptr practic)

{
    ListOfPassingPractice listPassing;
    listPassing=practic->getlist_of_passing_practice();
    Employer_ptr employer;
    employer.reset(new Employer());
    employer=practic->getemployer();
    PassingPractice_ptr passing;
    passing.reset(new PassingPractice);
    for(int i=0;i<listPassing.count();i++){
     listPassing.getByIndex(i)->setemployer(employer);
    }
    for(int i=0;i<listPassing.count();i++){
        for(int j=0;j<listPassing.getByIndex(i)->list_of_reports().count();j++){

            listPassing.getByIndex(i)->list_of_reports().getByIndex(j)->sethead_employer(listPassing.getByIndex(i)->gethead_employer());
            listPassing.getByIndex(i)->list_of_reports().getByIndex(j)->sethead_university(listPassing.getByIndex(i)->gethead_university());
            listPassing.getByIndex(i)->list_of_reports().getByIndex(j)->setstudent(listPassing.getByIndex(i)->getstuden());

        }
    }
    ListOfReport listReport;
    for(int i=0;i<listPassing.count();i++){
     listReport=listPassing.getByIndex(i)->getlist_of_reports();
     qx::dao::save_with_all_relation(listReport);
     qx::dao::save_with_all_relation(listPassing.getByIndex(i));
    }


    qx::dao::save_with_all_relation(practic);


}

Practice_ptr AbstractPracticeModel::getPractice(int index)
{
    return m_listPractice.getByIndex(index);

}

ListOfEmployer AbstractPracticeModel::getListEmployer()
{
    qx::dao::fetch_all(m_listEmployer);
    return m_listEmployer;

}

void AbstractPracticeModel::loadList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listPractice);
    ListOfPassingPractice listPassing;

    for(int i=0;i<m_listPractice.count();i++){
       listPassing=m_listPractice.getByIndex(i)->getlist_of_passing_practice();
       qx::dao::fetch_by_id_with_all_relation(listPassing);
       m_listPractice.getByIndex(i)->setlist_of_passing_practice(listPassing);
    }
    endInsertRows();
    layoutChanged();

}
