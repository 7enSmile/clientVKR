#include "model/abstracteventsmodel.h"

AbstractEventsModel::AbstractEventsModel()
{
    loadList();

}

int AbstractEventsModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listEvent.count() : 0;

}

int AbstractEventsModel::columnCount(const QModelIndex &parent) const
{
     return !parent.isValid() ? 3 : 0;

}

QVariant AbstractEventsModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        {

            if (index.column() == 0)
            {

               return m_listEvent.getByIndex(index.row())->getname();
            }
            if (index.column() == 1)
            {

               return m_listEvent.getByIndex(index.row())->getbegin().toString("dd.MM.yy");
            }
            if (index.column() == 2)
            {



               return m_listEvent.getByIndex(index.row())->getending().toString("dd.MM.yy");
            }

        }
    if(role==Qt::TextAlignmentRole&&index.column()!=0){

        return Qt::AlignCenter;
    }


        return QVariant();

}

void AbstractEventsModel::deleteEvent(int index)
{
    qx::dao::delete_by_id(m_listEvent.getByIndex(index));
    loadList();
    layoutChanged();


}

void AbstractEventsModel::saveEvent(Events_ptr event)
{
    qx::dao::save_with_all_relation(event);
    loadList();
    layoutChanged();


}

Events_ptr AbstractEventsModel::getEvent(int index)
{
    return m_listEvent.getByIndex(index);

}

QVariant AbstractEventsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Наименование");
        case 1:
            return QString("Начало");
        case 2:
            return QString("Конец");
        }
    }

    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {

        return section+1;
    }
    return QVariant();

}

void AbstractEventsModel::loadList()
{
    qx::dao::fetch_all_with_all_relation(m_listEvent);
    m_listEvent.sortByKey();
}
