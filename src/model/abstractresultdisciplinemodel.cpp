#include "model/abstractresultdisciplinemodel.h"

AbstractResultDisciplineModel::AbstractResultDisciplineModel(ListOfResultEducation list)
{
    m_listResultEducation=list;
    m_listResultEducation.sortByKey();

}

int AbstractResultDisciplineModel::rowCount(const QModelIndex &parent) const
{
     return !parent.isValid() ? m_listResultEducation.count() : 0;
}

int AbstractResultDisciplineModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractResultDisciplineModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        {

            if (index.column() == 0)
            {
               return m_listResultEducation.getByIndex(index.row())->getacquired_skills();
            }

        }

        return QVariant();

}

ListOfResultEducation &AbstractResultDisciplineModel::getListResult()
{
    return m_listResultEducation;

}

void AbstractResultDisciplineModel::saveResultEducation(ResultEducation_ptr result)
{
    if(m_listResultEducation.count()!=0){

        m_listResultEducation.insert(m_listResultEducation.getKeyByIndex(m_listResultEducation.count()-1)+1,result);
    }else{

         m_listResultEducation.insert(1,result);
    }
    layoutChanged();


}

ResultEducation_ptr AbstractResultDisciplineModel::getResultEducation(int index)
{
    return m_listResultEducation.getByIndex(index);

}

void AbstractResultDisciplineModel::deleteResultEducation(int index)

{
    if(m_listResultEducation.getByIndex(index)->getResult_discipline_id()!=0){

        qx::dao::delete_by_id(m_listResultEducation.getByIndex(index));
    }
    m_listResultEducation.removeByIndex(index);
    layoutChanged();

}

QVariant AbstractResultDisciplineModel::headerData(int section, Qt::Orientation orientation, int role) const
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
