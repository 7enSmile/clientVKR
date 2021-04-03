#ifndef ABSTRACTDEPARTMENTSMODEL_H
#define ABSTRACTDEPARTMENTSMODEL_H
#include <QAbstractTableModel>
#include "Department.h"
class AbstractDepartmentsModel: public QAbstractTableModel
{
private:

    ListOfDepartment m_listDepartment;
    void loadList();


public:

    AbstractDepartmentsModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteDepartment(int);

    void saveDepartment(Department_ptr);

    Department_ptr getDepartment(int);

    ListOfDepartment& getList();
};

#endif
