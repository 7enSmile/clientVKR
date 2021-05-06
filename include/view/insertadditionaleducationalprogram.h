#ifndef INSERTADDITIONALEDUCATIONALPROGRAM_H
#define INSERTADDITIONALEDUCATIONALPROGRAM_H

#include <QDialog>

namespace Ui {
class InsertAdditionalEducationalProgram;
}

class InsertAdditionalEducationalProgram : public QDialog
{
    Q_OBJECT

public:
    explicit InsertAdditionalEducationalProgram(QWidget *parent = nullptr);
    ~InsertAdditionalEducationalProgram();

private:
    Ui::InsertAdditionalEducationalProgram *ui;
};

#endif // INSERTADDITIONALEDUCATIONALPROGRAM_H
