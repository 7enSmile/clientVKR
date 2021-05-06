#include "model/abstracteducationalprogrammodel.h"

AbstractEducationalProgramModel::AbstractEducationalProgramModel()
{
    loadList();
    m_listEducationalProgram.sortByKey();

}

int AbstractEducationalProgramModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listEducationalProgram.count() : 0;

}

int AbstractEducationalProgramModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractEducationalProgramModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
            {

                if (index.column() == 0)
                {
                   return m_listEducationalProgram.getByIndex(index.row())->getname();
                }

            }


            return QVariant();

}

void AbstractEducationalProgramModel::deleteEducationalProgram(int index)

{
    qx::dao::delete_by_id(m_listEducationalProgram.getByIndex(index));
    loadList();

}

void AbstractEducationalProgramModel::saveEducationalProgram(EducationalProgram_ptr educationProgram)
{
    ListOfResultEducation list;
    list=educationProgram->getlist_of_result_education();
    for(int i=0;i<list.count();i++){

        list.getByIndex(i)->seteducational_program(educationProgram);
    }
    educationProgram->setlist_of_result_education(list);
    qx::dao::save_with_all_relation(educationProgram);
    loadList();

}

EducationalProgram_ptr AbstractEducationalProgramModel::getEducationalProgram(int index)
{
    return m_listEducationalProgram.getByIndex(index);

}

void AbstractEducationalProgramModel::loadList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listEducationalProgram);
    endInsertRows();
    layoutChanged();
}
