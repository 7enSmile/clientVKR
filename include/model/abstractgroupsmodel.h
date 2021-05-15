#ifndef ABSTRACTGROUPSMODEL_H
#define ABSTRACTGROUPSMODEL_H
#include "Group.h"
#include <QAbstractTableModel>

class AbstractGroupsModel:public QAbstractTableModel
{


private:
    ListOfGroup m_listGroup;


public:
    AbstractGroupsModel();


    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteGroup(int);

    void saveGroup(Group_ptr);

    ListOfGroup& getList();

    Group_ptr getGroup(int);

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;


    void loadList();

};

#endif
