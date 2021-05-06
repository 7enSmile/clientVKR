#ifndef INSERTEDUCATIONALPROGRAM_H
#define INSERTEDUCATIONALPROGRAM_H

#include <QDialog>

namespace Ui {
class InsertEducationalProgram;
}

class InsertEducationalProgram : public QDialog
{
    Q_OBJECT

public:
    explicit InsertEducationalProgram(QWidget *parent = nullptr);
    ~InsertEducationalProgram();

private:
    Ui::InsertEducationalProgram *ui;
};

#endif // INSERTEDUCATIONALPROGRAM_H
