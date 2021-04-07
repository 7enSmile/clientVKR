#include <QAbstractTableModel>
#include "Practice.h"
#ifndef ABSTRACTPRACTICEMODEL_H
#define ABSTRACTPRACTICEMODEL_H


class AbstractPracticeModel:public QAbstractTableModel
{
private:

    ListOfPractice m_listPractice;

public:
    AbstractPracticeModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;


    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deletePractice(int);

    void savePractice(Practice_ptr);

    Practice_ptr getPractice(int);

    void loadList();




};

#endif // ABSTRACTPRACTICEMODEL_H
