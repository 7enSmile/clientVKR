#include "view/searchstaffuniversity.h"
#include "ui_searchstaffuniversity.h"

SearchStaffUniversity::SearchStaffUniversity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchStaffUniversity)
{
    ui->setupUi(this);
    m_modelStaffUniversity=new AbstractStaffUniversityModel();
    ui->tableView->setModel(m_modelStaffUniversity);
    m_modelDepartment=new AbstractDepartmentsModel();
    ListOfDepartment list=m_modelDepartment->getList();
    this->setWindowTitle("Поиск");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    for(int i=0;i<list.count();i++){
        ui->comboBox->addItem(list.getByIndex(i)->getname());
    }

    connect(ui->lineEditName, &QLineEdit::textChanged, this, &SearchStaffUniversity::textChanged);
    connect(ui->lineEditLastName, &QLineEdit::textChanged, this, &SearchStaffUniversity::textChanged);
    connect(ui->comboBox, SIGNAL(activated(QString)), this, SLOT(textChanged()));
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableStaffUniversityClicked()));
    m_staff.reset(new HeadUniversity());
}

SearchStaffUniversity::~SearchStaffUniversity()
{
    delete ui;
}

HeadUniversity_ptr SearchStaffUniversity::getStaffUniversity()
{
    return m_staff;
}

void SearchStaffUniversity::textChanged()
{
    m_modelStaffUniversity->search(ui->lineEditName->text(),ui->lineEditLastName->text(),ui->comboBox->currentText());

}



void SearchStaffUniversity::onTableStaffUniversityClicked()
{
    QModelIndexList index = ui->tableView->selectionModel()->selectedRows();
    m_staff=m_modelStaffUniversity->getStaffUniversity(index[0].row());
    QDialog::accept();

}
