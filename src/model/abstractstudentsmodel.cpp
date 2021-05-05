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

void AbstractStudentsModel::search(QString searchName, QString searchLastname, QString searchGroup)
{
    ListOfStudent list;
    m_listStudent._clear();
    qx::dao::fetch_all_with_all_relation(list);
    QRegExp regName("^"+searchName);
    QRegExp reglastname("^"+searchLastname);
    QRegExp reggroup("^"+searchGroup);
    QString name;
    QString lastname;
    QString group;
    for(int i=0;i<list.count();i++){
        name=list.getByIndex(i)->getperson()->getfirstname();
        lastname=list.getByIndex(i)->getperson()->getlastname();
        group=list.getByIndex(i)->getgroup()->getnumber();
        if(name.contains(regName)&&lastname.contains(reglastname)&&group.contains(reggroup)){
            m_listStudent.insert(list.getByIndex(i)->getstudent_id(),list.getByIndex(i));
        }
    }
    layoutChanged();



}

void AbstractStudentsModel::creatFromFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {

        return;
    }
    QStringList wordList;
    QString word;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if(line.count()==5){
            word=QString::fromLocal8Bit(line.split(';').at(0));
            wordList.append(word);
            word=QString::fromLocal8Bit(line.split(';').at(1));
            wordList.append(word);
            word=QString::fromLocal8Bit(line.split(';').at(2));
            wordList.append(word);
            word=QString::fromLocal8Bit(line.split(';').at(3));
            wordList.append(word);
            word=QString::fromLocal8Bit(line.split(';').at(4));
            word.remove(word.size()-2,2);
            wordList.append(word);
            generateStudent(wordList);
            wordList.clear();
        }

    }
    loadListGlobal();
    layoutChanged();


}



void AbstractStudentsModel::generateStudent(QStringList wordList)
{

    qx::QxSqlQuery queryPerson("WHERE t_Person.fistname=:name AND t_Person.lastname=:lastname AND t_Person.patronymic=:patronymic");
    queryPerson.bind(":name",wordList.at(1));
    queryPerson.bind(":lastname",wordList.at(0));
    queryPerson.bind(":patronymic",wordList.at(2));
    qx::QxSqlQuery queryGroup("WHERE t_Group.number=:number");
    queryGroup.bind(":number",wordList.at(3));
    qx::QxSqlQuery queryPractice("WHERE t_Practice.customid=:customid");
    queryPractice.bind(":customid",wordList.at(4));
    Practice_ptr practice;
    practice.reset(new Practice());
    qx::dao::fetch_by_query(queryPractice, practice);
    if(practice->getPractice_id()==0)
        return;
    Group_ptr group;
    group.reset(new Group());
    qx::dao::fetch_by_query(queryGroup, group);
    Person_ptr person;
    person.reset(new Person);
    qx::dao::fetch_by_query(queryPerson, person);
    qx::QxSqlQuery queryStudent("WHERE t_Student.group_id=:id_group AND t_Student.person_id=:id_person");
    Student_ptr student;
    student.reset(new Student());
    if(group->getgroup_id()!=0&&person->getperson_id()!=0){
        queryStudent.bind(":id_group",QString::number(group->getgroup_id()));
        queryStudent.bind(":id_person",QString::number(person->getperson_id()));
        qx::dao::fetch_by_query(queryStudent, student);
        if(student->getstudent_id()==0){
            student->setgroup(group);
            student->setperson(person);
            qx::dao::save_with_all_relation(student);
        }

    }else{
        if(group->getgroup_id()==0){

            group->setnumber(wordList.at(3));
            person->setperson_id(0);

        }
        if(person->getperson_id()==0){

            person->setfirstname(wordList.at(1));
            person->setlastname(wordList.at(0));
            person->setpatronymic(wordList.at(2));
        }
        student->setgroup(group);
        student->setperson(person);
        qx::dao::save_with_all_relation(student);
    }

    PassingPractice_ptr passingPractice;
    passingPractice.reset(new PassingPractice);
    qx::QxSqlQuery queryPassingPractice("WHERE t_Passing_practice.practice_id=:practice_id AND t_Passing_practice.Student_id=:student_id");
    queryPassingPractice.bind(":practice_id",QString::number(practice->getPractice_id()));
    queryPassingPractice.bind(":student_id",QString::number(student->getstudent_id()));
    qx::dao::fetch_by_query(queryPassingPractice, passingPractice);
    if(passingPractice->getPassingPractice_id()==0){
        passingPractice->setpractice(practice);
        passingPractice->setstuden(student);
        passingPractice->setemployer(practice->getemployer());
        qx::dao::save(passingPractice);
    }


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
