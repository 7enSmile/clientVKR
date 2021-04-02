#ifndef INSERTGROUP_H
#define INSERTGROUP_H

#include <QDialog>
#include "Group.h"
#include "QMessageBox"
namespace Ui {
class InsertGroup;
}

class InsertGroup : public QDialog
{
    Q_OBJECT

public:
    explicit InsertGroup(QWidget *parent = nullptr);
    ~InsertGroup();
    void insert(Group_ptr&);
    Group_ptr &getGroup();


private:
    Ui::InsertGroup *ui;
    Group_ptr m_group;
    void initInser();
private slots:
    void onOkClicked();
};

#endif // INSERTGROUP_H
