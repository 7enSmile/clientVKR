#ifndef SEARCHHEADEMPLOYER_H
#define SEARCHHEADEMPLOYER_H

#include <QDialog>
#include"Head_employer.h"
#include "model/abstractheademployermodel.h"
namespace Ui {
class SearchHeadEmployer;
}

class SearchHeadEmployer : public QDialog
{
    Q_OBJECT

public:
    SearchHeadEmployer(Employer_ptr,QWidget *parent = nullptr);
    ~SearchHeadEmployer();
    HeadEmployer_ptr getHeadEmployer();

private:
    Ui::SearchHeadEmployer *ui;
    AbstractHeadEmployerModel *m_modelHeadEmployer;
    HeadEmployer_ptr m_headEmployer;
    Employer_ptr m_employer;

private slots:
    void textChanged();
    void onTablHeadEmployerClicked();
};

#endif // SEARCHHEADEMPLOYER_H
