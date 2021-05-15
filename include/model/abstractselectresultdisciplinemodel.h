#ifndef ABSTRACTSELECTRESULTDISCIPLINEMODEL_H
#define ABSTRACTSELECTRESULTDISCIPLINEMODEL_H
#include <qabstractitemmodel.h>
#include "Result_education.h"
#include <QBrush>

class AbstractSelectResultDisciplineModel:public QAbstractTableModel
{
public:
    AbstractSelectResultDisciplineModel(ListOfResultEducation);

    ListOfResultEducation& getList();

    void action(int);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

private:
    ListOfResultEducation m_listGlobalResultDiscipline;
    ListOfResultEducation m_listLocalResultDiscipline;
};

#endif // ABSTRACTSELECTRESULTDISCIPLINEMODEL_H
