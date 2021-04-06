#ifndef ABSTRACTEMPLOYERMODEL_H
#define ABSTRACTEMPLOYERMODEL_H
#include <QAbstractTableModel>
#include "Employer.h"

class AbstractEmployerModel:public QAbstractTableModel
{
private:

    ListOfEmployer m_listEmployer;


public:
    AbstractEmployerModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteEmployer(int);

    void saveEmployer(Employer_ptr);

    Employer_ptr getEmployer(int);

    void loadList();

    ListOfHeadEmployer getListHeadEmployer(int);

    ListOfContactEmployer getListContactEmployer(int);

};


#endif // ABSTRACTEMPLOYERMODEL_H
