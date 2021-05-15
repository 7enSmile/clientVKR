#ifndef ABSTRACTRESULTDISCIPLINEMODEL_H
#define ABSTRACTRESULTDISCIPLINEMODEL_H
#include <QAbstractTableModel>
#include "Result_education.h"


class AbstractResultDisciplineModel:public QAbstractTableModel
{
public:
    AbstractResultDisciplineModel(ListOfResultEducation);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    ListOfResultEducation& getListResult();

    void saveResultEducation(ResultEducation_ptr);

    ResultEducation_ptr getResultEducation(int);

    void deleteResultEducation(int);

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;



private:
    ListOfResultEducation m_listResultEducation;
};

#endif // ABSTRACTRESULTDISCIPLINEMODEL_H
