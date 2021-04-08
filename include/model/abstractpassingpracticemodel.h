#ifndef ABSTRACTPASSINGPRACTICEMODEL_H
#define ABSTRACTPASSINGPRACTICEMODEL_H
#include "Passing_practice.h"
#include <QAbstractTableModel>
class AbstractPassingPracticeModel:public QAbstractTableModel
{
public:

    AbstractPassingPracticeModel(ListOfPassingPractice);
    PassingPractice_ptr getPassingpractice(int);


private:

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    ListOfPassingPractice m_listPassingPractice;

    void loadList();


};

#endif // ABSTRACTPASSINGPRACTICEMODEL_H
