#ifndef EDUCATIONALPROGRAMWINDOW_H
#define EDUCATIONALPROGRAMWINDOW_H

#include <QDialog>
#include "model/abstracteducationalprogrammodel.h"
#include "view/inserteducationalprogram.h"
namespace Ui {
class EducationalProgramWindow;
}

class EducationalProgramWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EducationalProgramWindow(QWidget *parent = nullptr);
    ~EducationalProgramWindow();


private:

    Ui::EducationalProgramWindow *ui;

    AbstractEducationalProgramModel *m_modelEducationProgram;

private slots:

    void onDeleteClicket();

    void onInsertClicket();

    void onTableEducationProgramClicket();

    void onOkCliced();

};

#endif // EDUCATIONALPROGRAMWINDOW_H
