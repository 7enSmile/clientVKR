#ifndef ABSTRACTHEADEMPLOYERMODEL_H
#define ABSTRACTHEADEMPLOYERMODEL_H
#include "Head_employer.h"
#include <QAbstractTableModel>

class AbstractHeadEmployerModel:public QAbstractTableModel
{
private:

    ListOfHeadEmployer m_listHeadEmployer;

public:

    AbstractHeadEmployerModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteHeadEmployer(int);

    void saveHeadEmployer(HeadUniversity_ptr);

    HeadEmployer_ptr getHeadEmployer(int);

    void loadList();
};

#endif // ABSTRACTHEADEMPLOYERMODEL_H
