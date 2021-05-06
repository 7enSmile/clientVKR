#ifndef INSERTEDUCATIONALPROGRAM_H
#define INSERTEDUCATIONALPROGRAM_H

#include <QDialog>
#include "Educational_program.h"
#include "view/insertadditionaleducationalprogram.h"
#include "view/resultdisciplinewindow.h"


namespace Ui {
class InsertEducationalProgram;
}

class InsertEducationalProgram : public QDialog
{
    Q_OBJECT

public:
     InsertEducationalProgram(QWidget *parent = nullptr);
     InsertEducationalProgram(EducationalProgram_ptr,QWidget *parent = nullptr);
    ~InsertEducationalProgram();
     EducationalProgram_ptr getEducationalProgram();

private:

    Ui::InsertEducationalProgram *ui;

    EducationalProgram_ptr m_educationalProgram;

    void initconnection();

private slots:
    void onActionClicked();
    void onOKCliced();
    void onResultClicked();
    void onAdditionalClicked();

};

#endif // INSERTEDUCATIONALPROGRAM_H
