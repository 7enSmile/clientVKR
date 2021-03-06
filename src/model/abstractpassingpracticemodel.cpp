#include "model/abstractpassingpracticemodel.h"



AbstractPassingPracticeModel::AbstractPassingPracticeModel(ListOfPassingPractice listPassingPractice)
{
    m_listPassingPractice=listPassingPractice;


    loadList();

}

ListOfPassingPractice AbstractPassingPracticeModel::getListPassingpractice()
{

    return m_listPassingPractice;
}

void AbstractPassingPracticeModel::changePassingPractice(PassingPractice_ptr passingPractice,int index)
{

    m_listPassingPractice.removeByIndex(index);
    m_listPassingPractice.insert(passingPractice->getPassingPractice_id(),passingPractice);


}



int AbstractPassingPracticeModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listPassingPractice.count() : 0;

}

int AbstractPassingPracticeModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractPassingPracticeModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {

        if (index.column() == 0)
        {


            QString title;
            QString firstname;
            QString lastname;
            QString patronymic;
            QString group;
            if(m_listPassingPractice.getByIndex(index.row())->getstuden()!=nullptr){
                firstname=m_listPassingPractice.getByIndex(index.row())->getstuden()->getperson()->getfirstname();
                lastname=m_listPassingPractice.getByIndex(index.row())->getstuden()->getperson()->getlastname();
                patronymic=m_listPassingPractice.getByIndex(index.row())->getstuden()->getperson()->getpatronymic();
                group=m_listPassingPractice.getByIndex(index.row())->getstuden()->getgroup()->getnumber();
                title=lastname+" "+firstname+" "+patronymic;
            }
            return title;
        }

    }

    return QVariant();

}

QVariant AbstractPassingPracticeModel::headerData(int section, Qt::Orientation orientation, int role) const
{




    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("??????????????");

        }
    }

    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {

        return section+1;
    }
    return QVariant();

}

void AbstractPassingPracticeModel::save(PassingPractice_ptr passingpractice)
{



    if(!m_listPassingPractice.empty()){
        m_listPassingPractice.insert(m_listPassingPractice.getKeyByIndex(m_listPassingPractice.count()-1)+1,passingpractice);
    }
    else{

        m_listPassingPractice.insert(1,passingpractice);

    }



    layoutChanged();

}

void AbstractPassingPracticeModel::deletePassingPractice(int index)
{
    if(m_listPassingPractice.getByIndex(index)->getPassingPractice_id()!=0){

        qx::dao::delete_by_id(m_listPassingPractice.getByIndex(index));
    }
    m_listPassingPractice.removeByIndex(index);
    layoutChanged();

}

PassingPractice_ptr AbstractPassingPracticeModel::getPassingpractice(int index)
{

    return m_listPassingPractice.getByIndex(index);

}



void AbstractPassingPracticeModel::loadList()
{
    ListOfStudent listStudent;
    ListOfHeadEmployer listHEadEmployer;
    ListOfHeadUniversity listHeadUniversity;
    HeadEmployer_ptr headEmployer;
    HeadUniversity_ptr headUniversity;
    Student_ptr student;
    student.reset(new Student());
    headEmployer.reset(new HeadEmployer());
    headUniversity.reset(new HeadUniversity());
    for(int i=0;i<m_listPassingPractice.count();i++){
        if( m_listPassingPractice.getByIndex(i)->gethead_employer()!=nullptr){
            headEmployer=m_listPassingPractice.getByIndex(i)->gethead_employer();
            qx::dao::fetch_by_id_with_relation("person_id",headEmployer);
            m_listPassingPractice.getByIndex(i)->sethead_employer(headEmployer);
        }
        if( m_listPassingPractice.getByIndex(i)->gethead_university()!=nullptr){
            headUniversity=m_listPassingPractice.getByIndex(i)->gethead_university();
            qx::dao::fetch_by_id_with_relation("person",headUniversity);
            m_listPassingPractice.getByIndex(i)->sethead_university(headUniversity);
        }
        if( m_listPassingPractice.getByIndex(i)->getstuden()!=nullptr){
            student=m_listPassingPractice.getByIndex(i)->getstuden();
            qx::dao::fetch_by_id_with_relation("person_id",student);
            m_listPassingPractice.getByIndex(i)->setstuden(student);
        }

    }
    m_listPassingPractice.sortByKey();

}
