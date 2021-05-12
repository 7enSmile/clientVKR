#include "model/abstractdisciplinemodel.h"

AbstractDisciplineModel::AbstractDisciplineModel(ListOfDiscipline list)
{
    m_listDiscipline=list;
    m_listDiscipline.sortByKey();

}

int AbstractDisciplineModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listDiscipline.count() : 0;


}

int AbstractDisciplineModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractDisciplineModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
            {

                if (index.column() == 0)
                {
                   return  m_listDiscipline.getByIndex(index.row())->getname();
                }

            }


            return QVariant();

}

ListOfDiscipline &AbstractDisciplineModel::getListDiscipline()
{
    return m_listDiscipline;

}

void AbstractDisciplineModel::saveDiscipline(Discipline_ptr discipline)

{
    if(m_listDiscipline.count()!=0){


        m_listDiscipline.insert(m_listDiscipline.getKeyByIndex(m_listDiscipline.count()-1)+1,discipline);

    }else{

        m_listDiscipline.insert(1,discipline);

    }
    layoutChanged();


}

Discipline_ptr AbstractDisciplineModel::getDiscipline(int index)
{
    return m_listDiscipline.getByIndex(index);

}

void AbstractDisciplineModel::deleteDiscipline(int index)
{
    if(m_listDiscipline.getByIndex(index)->getdiscipline_id()!=0){

        qx::dao::delete_by_id(m_listDiscipline.getByIndex(index));
    }
    m_listDiscipline.removeByIndex(index);
    layoutChanged();

}

QVariant AbstractDisciplineModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Дисциплина");

        }
    }

    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {

        return section+1;
    }
    return QVariant();

}
