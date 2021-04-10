#ifndef ABSTRACTREPORTSMODEL_H
#define ABSTRACTREPORTSMODEL_H
#include <QAbstractTableModel>
#include "Report.h"

class AbstractReportsModel:public QAbstractTableModel
{
private:

    ListOfReport m_listReports;

    void loadList();

public:

    AbstractReportsModel(ListOfReport);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    ListOfReport& getListReports();

    void saveReport(Report_ptr);

    Report_ptr getReport(int);






};

#endif // ABSTRACTREPORTSMODEL_H
