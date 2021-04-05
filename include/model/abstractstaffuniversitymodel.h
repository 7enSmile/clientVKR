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

    AbstractStaffUniversityModel(ListOfHeadUniversity&);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteStaffUniversityGlobal(int);

    void deleteStaffUniversityLocal(int);

    void saveStaffUniversityGlobal(HeadUniversity_ptr);

    void changeStaffUniversityLocal(int,long,HeadUniversity_ptr);

    void saveStaffUniversityLocal(HeadUniversity_ptr);

    HeadUniversity_ptr getStaffUniversity(int);

    ListOfHeadUniversity& getListStaff();

    void loadListGlobal();



};

#endif // AbstraCTSTaffUNIVERSITYMODEL_H
