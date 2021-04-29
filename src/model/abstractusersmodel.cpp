#include "model/abstractusersmodel.h"

AbstractUsersModel::AbstractUsersModel()
{
    m_query=new QSqlQuery(qx::QxSqlDatabase::getDatabase());
    loadList();



}

int AbstractUsersModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? m_listUsers.count() : 0;

}

int AbstractUsersModel::columnCount(const QModelIndex &parent) const
{
     return !parent.isValid() ? 1 : 0;

}

QVariant AbstractUsersModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){

        if (index.column() == 0){

            return m_listUsers.at(index.row());
        }

    }

    return QVariant();

}

void AbstractUsersModel::insertUser(QString login, QString password)
{


    m_query->exec("CREATE USER "+login+" WITH PASSWORD '"+password+"';GRANT read_write to "+login+";");

    loadList();




}

void AbstractUsersModel::deleteUser(int index)
{
    m_query->exec("DROP ROLE "+ m_listUsers.at(index));
    loadList();


}

void AbstractUsersModel::changePassword(int index,QString password)
{

     m_query->exec("ALTER ROLE " + m_listUsers.at(index) + " WITH PASSWORD '" + password + "';");
     loadList();


}

void AbstractUsersModel::loadList()
{
    m_listUsers.clear();

    if(m_query ->exec("SELECT * FROM pg_shadow")){

        while(m_query->next()){

            m_listUsers.push_back(m_query->value(0).toString());
        }
    }
    layoutChanged();

}
