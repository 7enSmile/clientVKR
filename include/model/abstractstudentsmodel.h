#ifndef ABSTRACTSTUDENTSMODEL_H
#define ABSTRACTSTUDENTSMODEL_H
#include <QAbstractTableModel>
#include <Student.h>
#include <QRegExp>

class AbstractStudentsModel:public QAbstractTableModel
{
private:
    ListOfStudent m_listStudent;
    bool generateStudent(QStringList);


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

    void search(QString,QString,QString);

    int creatFromFile(QString,QString);

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

};

#endif // ABSTRACTSTUDENTSMODEL_H
