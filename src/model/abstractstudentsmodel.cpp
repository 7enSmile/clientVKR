#include "model/abstractstudentsmodel.h"

void AbstractStudentsModel::loadList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listStudent);
    endInsertRows();

}



AbstractStudentsModel::AbstractStudentsModel()
{

    loadList();
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

void AbstractStudentsModel::deleteStudent(int index)
{
    Person_ptr person;
    person.reset(new Person());
    person->setperson_id(m_listStudent.getByIndex(index)->getperson()->getperson_id());
    qx::dao::delete_by_id(person);
    loadList();
    layoutChanged();
}

void AbstractStudentsModel::saveStudent(Student_ptr &student)
{
    qx::dao::save_with_all_relation(student);
    loadList();
    layoutChanged();

}

Student_ptr AbstractStudentsModel::getStudent(int index)

{
    Student_ptr student;
    student.reset(new Student());
    student=m_listStudent.getByIndex(index);
    return student;

}
