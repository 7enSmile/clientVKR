#include "model/abstractpracticemodel.h"

AbstractPracticeModel::AbstractPracticeModel()
{
    loadList();

}

AbstractPracticeModel::AbstractPracticeModel(ListOfPractice list)
{
    m_listPractice=list;
    m_listPractice.sortByKey();

}

int AbstractPracticeModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listPractice.count() : 0;

}

void AbstractPracticeModel::search(ListOfPractice list,QString employer, QDate beginning, QDate ending)
{
    ListOfPractice globalList;
    qx::dao::fetch_all_with_relation("employer",globalList);
    m_listPractice.clear();
    for(int i=0;i<globalList.count();i++){

        if(globalList.getByIndex(i)->geteducation_program()==nullptr &&
                globalList.getByIndex(i)->getemployer()->getname()==employer &&
                !list.contains(globalList.getKeyByIndex(i)) &&
                globalList.getByIndex(i)->getbeginning()>=beginning &&
                globalList.getByIndex(i)->getending()<=ending)
            m_listPractice.insert(globalList.getByIndex(i)->getPractice_id(),globalList.getByIndex(i));
    }
    layoutChanged();

}

ListOfPractice& AbstractPracticeModel::getList()
{
    return m_listPractice;

}

void AbstractPracticeModel::savePracticeLocal(Practice_ptr practice)
{
    m_listPractice.insert(practice->getPractice_id(),practice);
    layoutChanged();

}

void AbstractPracticeModel::deleteEducationProgram(int index)
{
    m_listPractice.getByIndex(index)->seteducation_program(nullptr);
    qx::dao::save(m_listPractice.getByIndex(index));
    m_listPractice.removeByIndex(index);
    layoutChanged();


}

void AbstractPracticeModel::setSemester(int index, int semester)
{

    m_listPractice.getByIndex(index)-> setsemester(semester);



}

int AbstractPracticeModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 3 : 0;

}

QVariant AbstractPracticeModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {

        if (index.column() == 0)
        {


            QString title;
            QString employer;

            employer=m_listPractice.getByIndex(index.row())->getemployer()->getname();


            title=employer;
            return title;
        }
        if (index.column() == 1){

            QString databegin;
            databegin=m_listPractice.getByIndex(index.row())->getbeginning().toString("dd.MM.yy");
            return databegin;


        }
        if (index.column() == 2){

            QString dataending;
            dataending=m_listPractice.getByIndex(index.row())->getending().toString("dd.MM.yy");
            return dataending;


        }




    }

    if(role==Qt::TextAlignmentRole&&index.column()!=0){

        return Qt::AlignCenter;
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
            listPassing.getByIndex(i)->list_of_reports().getByIndex(j)->getpractice_result()->setStudent((listPassing.getByIndex(i)->getstuden()));
            listPassing.getByIndex(i)->list_of_reports().getByIndex(j)->getpractice_result()->setpassing_practice((listPassing.getByIndex(i)));


        }
    }
    ListOfReport listReport;
    PracticeResult_ptr practiceresult;
    practiceresult.reset(new PracticeResult());
    for(int i=0;i<listPassing.count();i++){
        listReport=listPassing.getByIndex(i)->getlist_of_reports();

        qx::dao::save_with_all_relation(listReport);
        qx::dao::save_with_all_relation(listPassing.getByIndex(i));
        for(int j=0;j<listReport.count();j++){
            if(listReport.getByIndex(j)->getpractice_result()->getestimate_employer()!=""){
                practiceresult=listReport.getByIndex(j)->getpractice_result();
                qx::dao::save(practiceresult);
            }
        }
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
    m_listPractice.sortByKey();
    endInsertRows();
    layoutChanged();

}

QVariant AbstractPracticeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Работодатель");
        case 1:
            return QString("Начало");
        case 2:
            return QString("Конец");
        }
    }

    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {

        return section+1;
    }
    return QVariant();

}
