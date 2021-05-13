#ifndef ABSTRACTEDUCATIONALPROGRAMMODEL_H
#define ABSTRACTEDUCATIONALPROGRAMMODEL_H
#include <QAbstractTableModel>
#include "Educational_program.h"

class AbstractEducationalProgramModel:public QAbstractTableModel
{
public:

    AbstractEducationalProgramModel();


    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void deleteEducationalProgram(int);

    void saveEducationalProgram(EducationalProgram_ptr);

    ListOfEducationalProgram& getList();

    EducationalProgram_ptr getEducationalProgram(int);

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;


private:

    ListOfEducationalProgram m_listEducationalProgram;

    void loadList();
};

#endif // ABSTRACTEDUCATIONALPROGRAMMODEL_H
