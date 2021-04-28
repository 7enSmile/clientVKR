#include "view/reportpracticewindow.h"
#include "ui_reportpracticewindow.h"









ReportPracticeWindow::ReportPracticeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportPracticeWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonSave,SIGNAL(clicked()),this,SLOT(onSaveClicked()));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Отчет");
}

ReportPracticeWindow::~ReportPracticeWindow()
{
    delete ui;
}

void ReportPracticeWindow::onSaveClicked()
{
    ListOfPractice list;
    qx::dao::fetch_all_with_all_relation(list);
    QTextDocument  *document=new QTextDocument();;
    QTextCursor cursor(document);
    cursor.insertText(QObject::tr("Отчет о практиках, проведенных с %1 по %2\n").arg(ui->dateEditBegin->text(),ui->dateEditEnd->text()));
    QTextTableFormat tableFormat;
    tableFormat.setCellPadding(5);
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 300));
    cursor.insertTable(1, 4, tableFormat);
    cursor.insertText(QObject::tr("Работодатель"));
    cursor.movePosition(QTextCursor::NextCell);
    cursor.insertText(QObject::tr("Начало"));
    cursor.movePosition(QTextCursor::NextCell);
    cursor.insertText(QObject::tr("Конец"));
    cursor.movePosition(QTextCursor::NextCell);
    cursor.insertText(QObject::tr("Количество студентов"));
    QTextTable *table = cursor.currentTable();
    for(int i=0;i<list.count();i++){
        if(list.getByIndex(i)->getbeginning()>=ui->dateEditBegin->date()&&list.getByIndex(i)->getending()<=ui->dateEditEnd->date()){
            table->appendRows(1);
            cursor.movePosition(QTextCursor::PreviousRow);
            cursor.movePosition(QTextCursor::NextCell);
            cursor.insertText(list.getByIndex(i)->getemployer()->getname());
            cursor.movePosition(QTextCursor::NextCell);
            cursor.insertText(list.getByIndex(i)->getbeginning().toString("dd.MM.yy"));
            cursor.movePosition(QTextCursor::NextCell);
            cursor.insertText(list.getByIndex(i)->getending().toString("dd.MM.yy"));
            cursor.movePosition(QTextCursor::NextCell);
            cursor.insertText(QString::number(list.getByIndex(i)->getlist_of_passing_practice().count()));
        }

    }
    QString fileName = QFileDialog::getSaveFileName(this, "Get PDF", QDir::currentPath(), QFileDialog::tr("odf (*.ODF)"));
    QTextDocumentWriter writer(fileName);
    writer.write(document);
    QDialog::close();




}
