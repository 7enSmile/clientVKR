#include "view/reporteventswindow.h"
#include "ui_reporteventswindow.h"

ReportEventsWindow::ReportEventsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportEventsWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonSave,SIGNAL(clicked()),this,SLOT(onSaveClicked()));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Отчет");
}

ReportEventsWindow::~ReportEventsWindow()
{
    delete ui;

}

void ReportEventsWindow::onSaveClicked()
{
    ListOfEvent list;
    qx::dao::fetch_all_with_all_relation(list);
    QTextDocument  *document=new QTextDocument();;
    QTextCursor cursor(document);
    cursor.insertText(QObject::tr("Отчет о мероприятиях, проведенных с %1 по %2\n").arg(ui->dateEditBegin->text(),ui->dateEditEnd->text()));
    QTextTableFormat tableFormat;
    tableFormat.setCellPadding(5);
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 450));
    cursor.insertTable(1, 5, tableFormat);
    cursor.insertText(QObject::tr("Работодатель"));
    cursor.movePosition(QTextCursor::NextCell);
    cursor.insertText(QObject::tr("Наименование"));
    cursor.movePosition(QTextCursor::NextCell);
    cursor.insertText(QObject::tr("Описание"));
    cursor.movePosition(QTextCursor::NextCell);
    cursor.insertText(QObject::tr("Дата начала"));
    cursor.movePosition(QTextCursor::NextCell);
    cursor.insertText(QObject::tr("Дата конца"));
    QTextTable *table = cursor.currentTable();
    for(int i=0;i<list.count();i++){
        if(list.getByIndex(i)->getbegin()>=ui->dateEditBegin->date()&&list.getByIndex(i)->getending()<=ui->dateEditEnd->date()){
            table->appendRows(1);
            cursor.movePosition(QTextCursor::PreviousRow);
            cursor.movePosition(QTextCursor::NextCell);
            cursor.insertText(list.getByIndex(i)->getemployer()->getname());
            cursor.movePosition(QTextCursor::NextCell);
            cursor.insertText(list.getByIndex(i)->getname());
            cursor.movePosition(QTextCursor::NextCell);
            cursor.insertText(list.getByIndex(i)->getdescription());
            cursor.movePosition(QTextCursor::NextCell);
            cursor.insertText(list.getByIndex(i)->getbegin().toString("dd.MM.yy"));
            cursor.movePosition(QTextCursor::NextCell);
            cursor.insertText(list.getByIndex(i)->getending().toString("dd.MM.yy"));
        }

    }
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить отчет", QDir::currentPath(), QFileDialog::tr("odf (*.odf)"));
    QTextDocumentWriter writer(fileName);
    writer.write(document);
    QDialog::close();

}
