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

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteStudent(int);

    void saveStudent(Student_ptr&);

    Student_ptr getStudent(int);

    void loadList();

};

#endif // ABSTRACTSTUDENTSMODEL_H
