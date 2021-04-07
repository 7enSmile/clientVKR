#include "view/searchstudents.h"
#include "ui_searchstudents.h"

SearchStudents::SearchStudents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchStudents)
{
    ui->setupUi(this);
    m_modelStudents=new AbstractStudentsModel();
    ui->tableView->setModel(m_modelStudents);
    m_modelGroups=new AbstractGroupsModel();
    ListOfGroup list=m_modelGroups->getList();
    this->setWindowTitle("Поиск");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    for(int i=0;i<list.count();i++){
        ui->comboBox->addItem(list.getByIndex(i)->getnumber());
    }

    connect(ui->lineEditName, &QLineEdit::textChanged, this, &SearchStudents::textChanged);
    connect(ui->lineEditLastName, &QLineEdit::textChanged, this, &SearchStudents::textChanged);
    connect(ui->comboBox, SIGNAL(activated(QString)), this, SLOT(textChanged()));
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableStudentsClicked()));
    m_student.reset(new Student());

}


SearchStudents::~SearchStudents()
{
    delete ui;
}

Student_ptr SearchStudents::getStudent()
{
    return m_student;
}

void SearchStudents::textChanged()
{
    m_modelStudents->search(ui->lineEditName->text(),ui->lineEditLastName->text(),ui->comboBox->currentText());

}

void SearchStudents::onTableStudentsClicked()
{
    QModelIndexList index = ui->tableView->selectionModel()->selectedRows();
    m_student=m_modelStudents->getStudent(index[0].row());
    QDialog::accept();
}
