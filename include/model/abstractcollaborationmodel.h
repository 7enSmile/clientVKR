#include <qabstractitemmodel.h>
#include "Collaboration.h"
#ifndef ABSTRACTCOLLABORATIONMODEL_H
#define ABSTRACTCOLLABORATIONMODEL_H
#include <qbrush.h>

class AbstractCollaborationModel:public QAbstractTableModel
{
public:
    AbstractCollaborationModel(ListOfCollaboration);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void insertGlobalCollaboration(Collaboration_ptr);

    void deleteGlobal(int);

    void action(int);

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

    ListOfCollaboration getCollaboration();
private:
    ListOfCollaboration m_listGlobalCollaboration;
    ListOfCollaboration m_listLocalCollaboration;
    void loadGlobalList();
};

#endif // ABSTRACTCOLLABORATIONMODEL_H
