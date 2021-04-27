#include "model/abstractreportsmodel.h"

AbstractReportsModel::AbstractReportsModel(ListOfReport listReports)
{

    m_listReports=listReports;
    loadList();



}



void AbstractReportsModel::loadList()
{
    PracticeResult_ptr result;
    result.reset(new PracticeResult());
    for(int i=0;i<m_listReports.count();i++){
      if(m_listReports.getByIndex(i)->getpractice_result()!=nullptr){
        result=m_listReports.getByIndex(i)->getpractice_result();
        qx::dao::fetch_by_id(result);
        m_listReports.getByIndex(i)->setpractice_result(result);
        }
    }



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

    if(!m_listReports.empty()){
    m_listReports.insert(m_listReports.getKeyByIndex(m_listReports.count()-1)+1,report);
    }
    else{

         m_listReports.insert(1,report);

    }
    layoutChanged();

}

Report_ptr AbstractReportsModel::getReport(int index)
{


    return m_listReports.getByIndex(index);

}


