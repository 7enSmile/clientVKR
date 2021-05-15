#include "model/abstractselectresultdisciplinemodel.h"

AbstractSelectResultDisciplineModel::AbstractSelectResultDisciplineModel(ListOfResultEducation list)
{
    m_listLocalResultDiscipline=list;

    qx::dao::fetch_all_with_all_relation(m_listGlobalResultDiscipline);

    m_listGlobalResultDiscipline.sortByKey();

}

ListOfResultEducation& AbstractSelectResultDisciplineModel::getList()
{
    return m_listLocalResultDiscipline;

}

void AbstractSelectResultDisciplineModel::action(int index)
{

    if(m_listLocalResultDiscipline.contains(m_listGlobalResultDiscipline.getByIndex(index)->getResult_discipline_id())){
        m_listLocalResultDiscipline.removeByKey(m_listGlobalResultDiscipline.getByIndex(index)->getResult_discipline_id());

    }else{
        m_listLocalResultDiscipline.insert(m_listGlobalResultDiscipline.getByIndex(index)->getResult_discipline_id(),m_listGlobalResultDiscipline.getByIndex(index));

    }
    layoutChanged();

}

int AbstractSelectResultDisciplineModel::rowCount(const QModelIndex &parent) const
{
     return !parent.isValid() ? m_listGlobalResultDiscipline.count() : 0;

}

int AbstractSelectResultDisciplineModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractSelectResultDisciplineModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){

        if (index.column() == 0){

            return m_listGlobalResultDiscipline.getByIndex(index.row())->getacquired_skills();
        }

    }

    if(role==Qt::BackgroundColorRole){
        long key=m_listGlobalResultDiscipline.getByIndex(index.row())->getResult_discipline_id();
        if(m_listLocalResultDiscipline.contains(key)){
            return QBrush(Qt::lightGray);
        }
    }


    return QVariant();

}

QVariant AbstractSelectResultDisciplineModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Образовательный результат");

        }
    }

    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {

        return section+1;
    }
    return QVariant();

}
