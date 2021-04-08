#include "view/searchheademployer.h"
#include "ui_searchheademployer.h"

SearchHeadEmployer::SearchHeadEmployer(Employer_ptr employer,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchHeadEmployer)
{
    ui->setupUi(this);
    m_modelHeadEmployer=new AbstractHeadEmployerModel();
    ui->tableView->setModel(m_modelHeadEmployer);

    this->setWindowTitle("Поиск");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    m_employer.reset(new Employer());
    m_employer=employer;
    connect(ui->lineEditName, &QLineEdit::textChanged, this, &SearchHeadEmployer::textChanged);
    connect(ui->lineEditLastName, &QLineEdit::textChanged, this, &SearchHeadEmployer::textChanged);
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTablHeadEmployerClicked()));
    m_headEmployer.reset(new HeadEmployer());
}

SearchHeadEmployer::~SearchHeadEmployer()
{
    delete ui;
}

HeadEmployer_ptr SearchHeadEmployer::getHeadEmployer()
{
    return m_headEmployer;
}

void SearchHeadEmployer::textChanged()
{
   m_modelHeadEmployer->search(ui->lineEditName->text(),ui->lineEditLastName->text(),m_employer->getname());

}

void SearchHeadEmployer::onTablHeadEmployerClicked()
{
    QModelIndexList index = ui->tableView->selectionModel()->selectedRows();
    m_headEmployer=m_modelHeadEmployer->getHeadEmployer(index[0].row());
    QDialog::accept();
}
