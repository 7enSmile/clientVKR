#include "model/abstractstudentsmodel.h"

void AbstractStudentsModel::loadListGlobal()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listStudent);
    endInsertRows();
    layoutChanged();

}

void AbstractStudentsModel::saveStudentLocal(Student_ptr &student)
{
    m_listStudent.insert(m_listStudent.count(),student);
    layoutChanged();


}

void AbstractStudentsModel::changeStudentLocal( int index,long key, Student_ptr &student)
{
    m_listStudent.replace(index,key,student);
    layoutChanged();


}

void AbstractStudentsModel::deleteStudentLocal(int index)
{
    m_listStudent.removeByIndex(index);
    layoutChanged();

}

ListOfStudent &AbstractStudentsModel::getListStudents()
{
    return m_listStudent;
}



AbstractStudentsModel::AbstractStudentsModel()
{

    loadListGlobal();
}

AbstractStudentsModel::AbstractStudentsModel(ListOfStudent & list)
{
    m_listStudent=list;

}

int AbstractStudentsModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listStudent.count() : 0;
}

int AbstractStudentsModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;
}

QVariant AbstractStudentsModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {

        if (index.column() == 0)
        {


           QString title;
           QString firstname;
           QString lastname;
           QString patronymic;
           firstname=m_listStudent.getByIndex(index.row())->getperson()->getfirstname();
           lastname=m_listStudent.getByIndex(index.row())->getperson()->getlastname();
           patronymic=m_listStudent.getByIndex(index.row())->getperson()->getpatronymic();
           title=lastname+" "+firstname+" "+patronymic;
           return title;
        }

    }

    return QVariant();

}

void AbstractStudentsModel::deleteStudentGlobal(int index)
{
    Person_ptr person;
    person.reset(new Person());
    person->setperson_id(m_listStudent.getByIndex(index)->getperson()->getperson_id());
    qx::dao::delete_by_id(person);
    loadListGlobal();
    layoutChanged();
}

void AbstractStudentsModel::saveStudentGlobal(Student_ptr &student)
{
    qx::dao::save_with_all_relation(student);
    loadListGlobal();
    layoutChanged();

}

Student_ptr AbstractStudentsModel::getStudent(int index)

{
    Student_ptr student;
    student.reset(new Student());
    student=m_listStudent.getByIndex(index);
    return student;

}
