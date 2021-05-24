#ifndef ABSTRACTUSERSMODEL_H
#define ABSTRACTUSERSMODEL_H
#include <QAbstractTableModel>


class AbstractUsersModel:public QAbstractTableModel
{
public:
    AbstractUsersModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void insertUser(QString,QString);

    void deleteUser(int);

    void changePassword(int,QString);


private:

    QList<QString>m_listUsers;

    QSqlQuery *m_query;

    void loadList();

};

#endif // ABSTRACTUSERSMODEL_H
