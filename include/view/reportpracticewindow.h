#ifndef REPORTPRACTICEWINDOW_H
#define REPORTPRACTICEWINDOW_H

#include <QDialog>
#include "Practice.h"
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextDocumentWriter>

namespace Ui {
class ReportPracticeWindow;
}

class ReportPracticeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ReportPracticeWindow(QWidget *parent = nullptr);
    ~ReportPracticeWindow();

private:
    Ui::ReportPracticeWindow *ui;
private slots:
    void onSaveClicked();
};

#endif // REPORTPRACTICEWINDOW_H
