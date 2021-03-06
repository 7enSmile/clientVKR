#ifndef ABSTRACTCONTACTEMPLOYERMODEL_H
#define ABSTRACTCONTACTEMPLOYERMODEL_H
#include <QAbstractTableModel>
#include "Contact_employer.h"

class AbstractContactEmployerModel:public QAbstractTableModel
{
private:

    ListOfContactEmployer m_listContactEmployer;

public:
    AbstractContactEmployerModel();

    AbstractContactEmployerModel(ListOfContactEmployer);


    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteContactEmployerGlobal(int);

    void deleteContactEmployerLocal(int);

    void saveContactEmployerGlobal(ContactEmployer_ptr);

    void saveContactEmployerLocal(ContactEmployer_ptr);

    void changeContactEmployerLocal(int,long,ContactEmployer_ptr);

    ContactEmployer_ptr getContactEmployer(int);

    ListOfContactEmployer& getListContactEmployer();

    void loadListGlobal();

    ListOfEmployer m_listEmployers;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

};

#endif // ABSTRACTCONTACTEMPLOYERMODEL_H
