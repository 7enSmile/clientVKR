#include "model/abstractpracticemodel.h"

AbstractPracticeModel::AbstractPracticeModel()
{
    loadList();

}

int AbstractPracticeModel::rowCount(const QModelIndex &parent) const
{
     return !parent.isValid() ? m_listPractice.count() : 0;

}

int AbstractPracticeModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractPracticeModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        {

            if (index.column() == 0)
            {


               QString title;
               QString employer;
               QString databegin;
               QString dataending;
               employer=m_listPractice.getByIndex(index.row())->getemployer()->getname();
               databegin=m_listPractice.getByIndex(index.row())->getbeginning().toString("dd.MM.yy");
               dataending=m_listPractice.getByIndex(index.row())->getending().toString("dd.MM.yy");
               title=employer+"  "+databegin+" - "+dataending;
               return title;
            }

        }

    return QVariant();

}

void AbstractPracticeModel::deletePractice(int index)
{

}

void AbstractPracticeModel::savePractice(Practice_ptr practic)
{
    qx::dao::save_with_all_relation(practic);


}

Practice_ptr AbstractPracticeModel::getPractice(int index)
{
    return m_listPractice.getByIndex(index);

}

ListOfEmployer AbstractPracticeModel::getListEmployer()
{
    qx::dao::fetch_all_with_all_relation(m_listEmployer);
    return m_listEmployer;

}

void AbstractPracticeModel::loadList()
{
    beginInsertRows(QModelIndex(),0,0);
    qx::dao::fetch_all_with_all_relation(m_listPractice);
    endInsertRows();
    layoutChanged();

}
