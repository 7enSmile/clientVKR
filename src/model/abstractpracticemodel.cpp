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

void AbstractPracticeModel::search(QRegExp name,ListOfPractice list,QString employer, QDate beginning, QDate ending)
{

    m_listPractice.clear();
    for(int i=0;i<m_GlobalistPractice.count();i++){

        if(m_GlobalistPractice.getByIndex(i)->geteducation_program()==nullptr &&
                m_GlobalistPractice.getByIndex(i)->getemployer()->getname()==employer &&
                !list.contains(m_GlobalistPractice.getKeyByIndex(i)) &&
                m_GlobalistPractice.getByIndex(i)->getbeginning()>=beginning &&
                m_GlobalistPractice.getByIndex(i)->getending()<=ending&&
                m_GlobalistPractice.getByIndex(i)->getname().contains(name))
            m_listPractice.insert(m_GlobalistPractice.getByIndex(i)->getPractice_id(),m_GlobalistPractice.getByIndex(i));
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

void AbstractPracticeModel::search(QRegExp name,QRegExp employer, QDate beginning, QDate ending)
{
    m_listPractice.clear();
    for(int i=0;i<m_GlobalistPractice.count();i++){

        if( m_GlobalistPractice.getByIndex(i)->getemployer()->getname().contains(employer) &&
                m_GlobalistPractice.getByIndex(i)->getbeginning()>=beginning &&
                m_GlobalistPractice.getByIndex(i)->getending()<=ending&&
                m_GlobalistPractice.getByIndex(i)->getname().contains(name))
            m_listPractice.insert(m_GlobalistPractice.getByIndex(i)->getPractice_id(),m_GlobalistPractice.getByIndex(i));
    }
    layoutChanged();


}

int AbstractPracticeModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 4 : 0;

}

QVariant AbstractPracticeModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
        {


            QString title;
            QString employer;

            employer=m_listPractice.getByIndex(index.row())->getname();


            title=employer;
            return title;
        }

        if (index.column() == 1)
        {


            QString title;
            QString employer;

            employer=m_listPractice.getByIndex(index.row())->getemployer()->getname();


            title=employer;
            return title;
        }
        if (index.column() == 2){

            QString databegin;
            databegin=m_listPractice.getByIndex(index.row())->getbeginning().toString("dd.MM.yy");
            return databegin;


        }
        if (index.column() == 3){

            QString dataending;
            dataending=m_listPractice.getByIndex(index.row())->getending().toString("dd.MM.yy");
            return dataending;


        }




    }

    if(role==Qt::TextAlignmentRole&&index.column()!=0&&index.column()!=1){

        return Qt::AlignCenter;
    }



    return QVariant();

}

void AbstractPracticeModel::deletePractice(int index)
{
    qx::dao::delete_by_id(m_listPractice.getByIndex(index));
    loadList();
    layoutChanged();

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
            qDebug()<<listPassing.getByIndex(i)->list_of_reports().count();
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
        if(listPassing.getByIndex(i)->getPassingPractice_id()==0){

            qx::dao::save(listPassing.getByIndex(i));

        }else
        {
            qx::dao::save_with_all_relation(listPassing.getByIndex(i));

        }

        qDebug()<<listPassing.getByIndex(i)->getPassingPractice_id();
        listReport=listPassing.getByIndex(i)->getlist_of_reports();
        for(int j=0;j<listReport.count();j++){

            if(!listReport.getByIndex(j)->getpractice_result()->getestimate_employer().isEmpty()){
                qx::dao::save_with_all_relation(listReport.getByIndex(j));
            }
        }




    }

    qx::dao::save_with_all_relation(practic);





}

Practice_ptr AbstractPracticeModel::getPractice(int index)
{
    Practice_ptr practice;
    practice.reset(new Practice());
    practice->setpractice_id(m_listPractice.getByIndex(index)->getPractice_id());
    qx::dao::fetch_by_id_with_relation("list_of_TestPractice",practice);
    m_listPractice.getByIndex(index)->setlist_of_TestPractice(practice->getlist_of_TestPractice());
    return m_listPractice.getByIndex(index);

}

ListOfEmployer AbstractPracticeModel::getListEmployer()
{
    qx::dao::fetch_all(m_listEmployer);
    return m_listEmployer;

}

void AbstractPracticeModel::loadList()
{
    m_names.clear();
    beginInsertRows(QModelIndex(),0,0);
    QStringList relation;
    relation.append("employer");
    relation.append("list_of_passing_practice");
    relation.append("Education_program");

    qx::dao::fetch_all_with_relation(relation,m_listPractice);
    ListOfPassingPractice listPassing;
    relation.clear();
    relation.append("head_employer_id");
    relation.append("head_university_id");
    relation.append("studen");
    relation.append("task");
    relation.append("list_of_reports");

    for(int i=0;i<m_listPractice.count();i++){
        if(!m_names.contains(m_listPractice.getByIndex(i)->getname())){

            m_names.append(m_listPractice.getByIndex(i)->getname());
        }
        listPassing=m_listPractice.getByIndex(i)->getlist_of_passing_practice();
        qx::dao::fetch_by_id_with_relation(relation,listPassing);
        m_listPractice.getByIndex(i)->setlist_of_passing_practice(listPassing);
    }
    m_listPractice.sortByKey();
    endInsertRows();
    layoutChanged();
    m_GlobalistPractice=m_listPractice;

}

QVariant AbstractPracticeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Наименование");
        case 1:
            return QString("Работодатель");
        case 2:
            return QString("Начало");
        case 3:
            return QString("Конец");
        }
    }

    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {

        return section+1;
    }
    return QVariant();

}

QStringList AbstractPracticeModel::getNames()
{
    return m_names;

}
