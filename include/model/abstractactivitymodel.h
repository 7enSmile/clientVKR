
#include <qabstractitemmodel.h>
#include "Activity.h"
#include <QBrush>
#ifndef ABSTRACTACTIVITYMODEL_H
#define ABSTRACTACTIVITYMODEL_H


class AbstractActivityModel:public QAbstractTableModel
{
public:
    AbstractActivityModel(ListOfActivity);


    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void insertGlobalActivity(Activity_ptr);

    void deleteGlobal(int);

    void action(int);

    ListOfActivity getActivity();
private:
    ListOfActivity m_listGlobalActivity;
    ListOfActivity m_listLocalActivity;
    void loadGlobalList();
};

#endif // ABSTRACTACTIVITYMODEL_H
