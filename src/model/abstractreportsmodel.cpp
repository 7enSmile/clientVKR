#include "model/abstractreportsmodel.h"

AbstractReportsModel::AbstractReportsModel(ListOfReport listReports)
{

    m_listReports=listReports;
    qDebug()<<m_listReports.count();
    loadList();

}



void AbstractReportsModel::loadList()
{
   qx::dao::fetch_by_id_with_all_relation(m_listReports);
}





int AbstractReportsModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listReports.count() : 0;

}

int AbstractReportsModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 1 : 0;

}

QVariant AbstractReportsModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        {

            if (index.column() == 0)
            {


               QString title="Отчет "+QString::number(index.row()+1);

               return title;
            }

        }

        return QVariant();

}

ListOfReport &AbstractReportsModel::getListReports()
{
    return m_listReports;

}

void AbstractReportsModel::saveReport(Report_ptr report)
{
    m_listReports.insert(m_listReports.count(),report);

}

Report_ptr AbstractReportsModel::getReport(int index)
{

    return m_listReports.getByIndex(index);

}
