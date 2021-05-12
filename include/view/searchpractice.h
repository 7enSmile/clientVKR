#ifndef SEARCHPRACTICE_H
#define SEARCHPRACTICE_H

#include <QDialog>
#include "Practice.h"
#include "model/abstractpracticemodel.h"
namespace Ui {
class SearchPractice;
}

class SearchPractice : public QDialog
{
    Q_OBJECT

public:
    SearchPractice(ListOfPractice,QWidget *parent = nullptr);
    ~SearchPractice();
    ListOfPractice& getList();


private:
    Ui::SearchPractice *ui;
    AbstractPracticeModel *m_modelPractice;
    ListOfPractice m_listPractice;
    ListOfPractice m_listNoContainsPractice;
private slots:

    void onActionCliced();
    void changed();
};

#endif // SEARCHPRACTICE_H
