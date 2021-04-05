#ifndef ABSTRACTSTUDENTSMODEL_H
#define ABSTRACTSTUDENTSMODEL_H
#include <QAbstractTableModel>
#include <Student.h>

class AbstractStudentsModel:public QAbstractTableModel
{
private:
    ListOfStudent m_listStudent;


public:
    AbstractStudentsModel();

    AbstractStudentsModel(ListOfStudent&);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteStudentGlobal(int);



    void saveStudentGlobal(Student_ptr&);

    Student_ptr getStudent(int);

    void loadListGlobal();

    void saveStudentLocal(Student_ptr&);

    void changeStudentLocal(int,long,Student_ptr&);


    void deleteStudentLocal(int);

    ListOfStudent& getListStudents();

};

#endif // ABSTRACTSTUDENTSMODEL_H
