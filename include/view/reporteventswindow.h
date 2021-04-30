#ifndef REPORTEVENTSWINDOW_H
#define REPORTEVENTSWINDOW_H

#include <QDialog>
#include "Event.h"
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextDocumentWriter>

namespace Ui {
class ReportEventsWindow;
}

class ReportEventsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ReportEventsWindow(QWidget *parent = nullptr);
    ~ReportEventsWindow();

private:
    Ui::ReportEventsWindow *ui;
private slots:
    void onSaveClicked();
};

#endif // REPORTEVENTSWINDOW_H
