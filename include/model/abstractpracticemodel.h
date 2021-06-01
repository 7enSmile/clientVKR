#include <QAbstractTableModel>
#include "Practice.h"
#ifndef ABSTRACTPRACTICEMODEL_H
#define ABSTRACTPRACTICEMODEL_H


class AbstractPracticeModel:public QAbstractTableModel
{
private:

    ListOfPractice m_listPractice;

    ListOfPractice m_GlobalistPractice;

    ListOfEmployer m_listEmployer;

    QStringList m_names;

public:

    AbstractPracticeModel();

    AbstractPracticeModel(ListOfPractice);



    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    void search(QRegExp,ListOfPractice,QString,QDate,QDate);

    ListOfPractice& getList();

    void savePracticeLocal(Practice_ptr);

    void deleteEducationProgram(int);

    void setSemester(int,int);

    void search(QRegExp,QRegExp,QDate,QDate);

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deletePractice(int);

    void savePractice(Practice_ptr);

    Practice_ptr getPractice(int);

    ListOfEmployer getListEmployer();

    void loadList();

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

    QStringList getNames();




};

#endif // ABSTRACTPRACTICEMODEL_H
