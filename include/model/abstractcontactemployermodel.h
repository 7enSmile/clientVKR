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

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteContactEmployer(int);

    void saveContactEmployer(ContactEmployer_ptr);

    ContactEmployer_ptr getContactEmployer(int);

    void loadList();
};

#endif // ABSTRACTCONTACTEMPLOYERMODEL_H
