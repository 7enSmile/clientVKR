#ifndef ABSTACTGROUPSMODEL_H
#define ABSTACTGROUPSMODEL_H
#include "Group.h"
#include <QAbstractTableModel>

class AbstactGroupsModel:public QAbstractTableModel
{


private:
    ListOfGroup m_listGroup;
    void loadList();

public:
    AbstactGroupsModel();


    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    void deleteGroup(int);
    void saveGroup(Group_ptr&);
    ListOfGroup& getList();

};

#endif // ABSTACTGROUPSMODEL_H
