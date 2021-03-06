#include "view/searchpractice.h"
#include "ui_searchpractice.h"

SearchPractice::SearchPractice(ListOfPractice list,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchPractice)
{
    ui->setupUi(this);
    m_modelPractice=new AbstractPracticeModel();
    ui->tableViewPractice->setModel(m_modelPractice);
    m_listNoContainsPractice=list;
    changed();
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &SearchPractice::changed);
    connect(ui->dateEditBegininng, &QDateEdit::dateChanged, this, &SearchPractice::changed);
    connect(ui->dateEditEnd, &QDateEdit::dateChanged, this, &SearchPractice::changed);
    connect(ui->comboBoxName, &QComboBox::currentTextChanged, this, &SearchPractice::changed);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onActionCliced()));
    ListOfEmployer listEmployer;
    listEmployer=m_modelPractice->getListEmployer();
    ui->tableViewPractice->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setWindowTitle("Поиск практики");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->tableViewPractice->setColumnWidth(0,200);
    ui->tableViewPractice->setColumnWidth(1,160);


    for(int i=0;i<listEmployer.count();i++){
        ui->comboBox->addItem(listEmployer.getByIndex(i)->getname());
    }
    ui->comboBoxName->addItem("Все");
    for(int i=0;i<m_modelPractice->getNames().count();i++){
        ui->comboBoxName->addItem(m_modelPractice->getNames().at(i));
    }
    ui->comboBoxName->setCurrentIndex(0);

}

SearchPractice::~SearchPractice()
{
    delete ui;
}

ListOfPractice& SearchPractice::getList()
{
    return m_listPractice;


}

void SearchPractice::onActionCliced()
{
    QModelIndexList index = ui->tableViewPractice->selectionModel()->selectedRows();
    for(int i=0;i<index.count();i++){

        m_listPractice.insert(m_modelPractice->getPractice(index[i].row())->getPractice_id(),m_modelPractice->getPractice(index[i].row()));
    }
    QDialog::accept();

}

void SearchPractice::changed()
{
    if(ui->comboBoxName->currentText()!="Все"){
        QRegExp name("^"+ui->comboBoxName->currentText()+"$");
        m_modelPractice->search(name,m_listNoContainsPractice,ui->comboBox->currentText(),ui->dateEditBegininng->date(),ui->dateEditEnd->date());
    }else{

        QRegExp name("^");
        m_modelPractice->search(name,m_listNoContainsPractice,ui->comboBox->currentText(),ui->dateEditBegininng->date(),ui->dateEditEnd->date());

    }


}
