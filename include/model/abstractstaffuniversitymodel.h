#ifndef ABSTRACTSTaffUNIVERSITYMODEL_H
#define ABSTRACTSTaffUNIVERSITYMODEL_H
#include <QAbstractTableModel>
#include "Head_university.h"

class AbstractStaffUniversityModel:public QAbstractTableModel
{
private:
    ListOfHeadUniversity m_listStaffUniversity;

public:

    AbstractStaffUniversityModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteStaffUniversity(int);

    void saveStaffUniversity(HeadUniversity_ptr);

    HeadUniversity_ptr getStaffUniversity(int);

    void loadList();



};

#endif // AbstraCTSTaffUNIVERSITYMODEL_H
