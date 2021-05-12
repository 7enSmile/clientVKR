#ifndef ABSTRACTDISCIPLINEMODEL_H
#define ABSTRACTDISCIPLINEMODEL_H
#include <QAbstractTableModel>
#include "Discipline.h"

class AbstractDisciplineModel:public QAbstractTableModel
{
public:
    AbstractDisciplineModel(ListOfDiscipline);

public:

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    ListOfDiscipline& getListDiscipline();

    void saveDiscipline(Discipline_ptr);

    Discipline_ptr getDiscipline(int);

    void deleteDiscipline(int);

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

private:
    ListOfDiscipline m_listDiscipline;
};

#endif // ABSTRACTDISCIPLINEMODEL_H
