#include "model/checkauthorizationmodel.h"

CheckAuthorizationModel::CheckAuthorizationModel()
{

}

bool CheckAuthorizationModel::checkUser(QString login, QString password)
{
    QSettings sett("conf.ini", QSettings::IniFormat);
    QString address = sett.value("server/address", "").toString();
    qx::QxSqlDatabase::getSingleton()->setDriverName("QPSQL");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("department");
    qx::QxSqlDatabase::getSingleton()->setHostName(address);
    qx::QxSqlDatabase::getSingleton()->setUserName(login);
    qx::QxSqlDatabase::getSingleton()->setPassword(password);
    qx::QxSqlDatabase::getSingleton()->setVerifyOffsetRelation(true);
    QSqlError error;
    qx::QxSqlDatabase::getDatabase(error);
    if(error.isValid()){

        m_error=error.databaseText();
        return false;


    }else{

        return true;
    }


}

bool CheckAuthorizationModel::checkAdmin(QString password)
{
    qx::QxSqlDatabase::getSingleton()->setDriverName("QPSQL");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("department");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("postgres");
    qx::QxSqlDatabase::getSingleton()->setPassword(password);
    qx::QxSqlDatabase::getSingleton()->setVerifyOffsetRelation(true);
    QSqlError error;
    qx::QxSqlDatabase::getDatabase(error);
    if(error.isValid()){

        m_error=error.databaseText();

        return false;

    }else{

        return true;
    }

}

QString CheckAuthorizationModel::getError()
{
    return m_error;

}
