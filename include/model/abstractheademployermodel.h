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

    AbstractHeadEmployerModel(ListOfHeadEmployer);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteHeadEmployerGlobal(int);

    void deleteHeadEmployerLocal(int);

    void saveHeadEmployerGlobal(HeadEmployer_ptr);

    void saveHeadEmployerLocal(HeadEmployer_ptr);

    void changeHeadEmployerLocal(int,long,HeadEmployer_ptr);

    HeadEmployer_ptr getHeadEmployer(int);

    ListOfHeadEmployer& getListHeadEmployer();

    void loadListGlobal();

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;



    void search(QString,QString,long);

    ListOfEmployer m_listEmployers;
};

#endif // ABSTRACTHEADEMPLOYERMODEL_H
