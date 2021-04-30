#ifndef ABSTRACTEVENTSMODEL_H
#define ABSTRACTEVENTSMODEL_H
#include <QAbstractTableModel>
#include "Event.h"

class AbstractEventsModel:public QAbstractTableModel
{
public:

    AbstractEventsModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteEvent(int);

    void saveEvent(Events_ptr);

    Events_ptr getEvent(int);

private:
    ListOfEvent m_listEvent;
    void loadList();
};

#endif // ABSTRACTEVENTSMODEL_H
