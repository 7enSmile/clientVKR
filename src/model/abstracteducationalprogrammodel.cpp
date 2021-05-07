#include "model/abstracteducationalprogrammodel.h"

AbstractEducationalProgramModel::AbstractEducationalProgramModel()
{
    loadList();


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
    ListOfResultEducation listResultEducation;
    list=educationProgram->getlist_of_result_education();
    ListOfDiscipline listDiscipline;
    listDiscipline=educationProgram->getlist_of_discipline();
    if(educationProgram->geteducational_program_id()==0){

        qx::dao::save_with_all_relation(educationProgram);
    }
    for(int i=0;i<list.count();i++){

        list.getByIndex(i)->seteducational_program(educationProgram);
    }
    for(int i=0;i<listDiscipline.count();i++){

        listDiscipline.getByIndex(i)->seteducational_program(educationProgram);
        listResultEducation=listDiscipline.getByIndex(i)->getlist_of_result_educational();
        for(int j=0;j<listResultEducation.count();j++){

            listResultEducation.getByIndex(j)->setdiscipline(listDiscipline.getByIndex(i));

        }
        if(listDiscipline.getByIndex(i)->getdiscipline_id()==0){
            qx::dao::save(listDiscipline.getByIndex(i));
        }
        qx::dao::save(listResultEducation);


    }

    educationProgram->setlist_of_result_education(list);
    educationProgram->setlist_of_discipline(listDiscipline);
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
    ListOfDiscipline list;
    for(int i=0;i<m_listEducationalProgram.count();i++){
        list = m_listEducationalProgram.getByIndex(i)->getlist_of_discipline();
        qx::dao::fetch_by_id_with_all_relation(list);
        m_listEducationalProgram.getByIndex(i)->setlist_of_discipline(list);
    }
    m_listEducationalProgram.sortByKey();
    endInsertRows();
    layoutChanged();
}
