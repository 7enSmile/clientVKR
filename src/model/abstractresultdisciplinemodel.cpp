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

ListOfResultEducation &AbstractResultDisciplineModel::getListReports()
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


}

ResultEducation_ptr AbstractResultDisciplineModel::getResultEducation(int index)
{
    return m_listResultEducation.getByIndex(index);

}
