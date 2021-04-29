#ifndef CHECKAUTHORIZATIONMODEL_H
#define CHECKAUTHORIZATIONMODEL_H


class CheckAuthorizationModel
{
public:
    CheckAuthorizationModel();
    bool checkUser(QString,QString);
    bool checkAdmin(QString);
    QString getError();
private:
    QString m_error;
};

#endif // CHECKAUTHORIZATIONMODEL_H
