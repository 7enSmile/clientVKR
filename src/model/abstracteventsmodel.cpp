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
     return !parent.isValid() ? 1 : 0;

}

QVariant AbstractEventsModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        {

            if (index.column() == 0)
            {
               QString title;
               QString name;
               QString date;
               name=m_listEvent.getByIndex(index.row())->getname();
               date=m_listEvent.getByIndex(index.row())->getbegin().toString("dd.MM.yy")+" - "+m_listEvent.getByIndex(index.row())->getending().toString("dd.MM.yy");
               title= name+" "+date;
               return title;
            }

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

void AbstractEventsModel::loadList()
{
    qx::dao::fetch_all_with_all_relation(m_listEvent);
    m_listEvent.sortByKey();
}
