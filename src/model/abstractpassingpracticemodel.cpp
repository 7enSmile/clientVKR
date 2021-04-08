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
                title=lastname+" "+firstname+" "+patronymic+" "+group;
            }
            return title;
        }

    }

    return QVariant();

}

void AbstractPassingPracticeModel::save(PassingPractice_ptr passingpractice)
{

    m_listPassingPractice.insert(m_listPassingPractice.count(),passingpractice);

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
            qx::dao::fetch_by_id_with_all_relation(headEmployer);
            m_listPassingPractice.getByIndex(i)->sethead_employer(headEmployer);
        }
        if( m_listPassingPractice.getByIndex(i)->gethead_university()!=nullptr){
            headUniversity=m_listPassingPractice.getByIndex(i)->gethead_university();
            qx::dao::fetch_by_id_with_all_relation(headUniversity);
            m_listPassingPractice.getByIndex(i)->sethead_university(headUniversity);
        }
        if( m_listPassingPractice.getByIndex(i)->getstuden()!=nullptr){
            student=m_listPassingPractice.getByIndex(i)->getstuden();
            qx::dao::fetch_by_id_with_all_relation(student);
            m_listPassingPractice.getByIndex(i)->setstuden(student);
        }

    }

}
