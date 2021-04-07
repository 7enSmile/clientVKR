#ifndef PRACTICEWINDOW_H
#define PRACTICEWINDOW_H

#include <QDialog>

namespace Ui {
class PracticeWindow;
}

class PracticeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PracticeWindow(QWidget *parent = nullptr);
    ~PracticeWindow();

private:
    Ui::PracticeWindow *ui;
};

#endif // PRACTICEWINDOW_H
