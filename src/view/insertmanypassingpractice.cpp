#include "view/insertmanypassingpractice.h"
#include "ui_insertmanypassingpractice.h"

InsertManyPassingPractice::InsertManyPassingPractice(Employer_ptr employer,Practice_ptr practice,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertManyPassingPractice)
{
    ui->setupUi(this);
    m_employer.reset(new Employer());
    m_employer=employer;
    m_practice.reset(new Practice());
    m_practice=practice;
    m_modelHeadEmployer=new AbstractHeadEmployerModel();
    m_modelHeadUniversity =new AbstractStaffUniversityModel();
    m_modelStudent =new AbstractStudentsModel();
    ui->tableViewHeadEmployer->setModel(m_modelHeadEmployer);
    ui->tableViewHeadUniversity->setModel(m_modelHeadUniversity);
    ui->tableViewStudent->setModel(m_modelStudent);
    ui->tableViewStudent->setSelectionMode(QAbstractItemView::MultiSelection);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Добавить несколько");
    fillComboBox();
    connect(ui->comboBoxGroup, SIGNAL(activated(QString)), this, SLOT(changeStudents()));
    connect(ui->lineEditNameHeadEmployer, &QLineEdit::textChanged, this, &InsertManyPassingPractice::changeHeadEmployer);
    connect(ui->lineEditLastNameHeadEmployer, &QLineEdit::textChanged, this, &InsertManyPassingPractice::changeHeadEmployer);
    connect(ui->lineEditNameHeadUniversity, &QLineEdit::textChanged, this, &InsertManyPassingPractice::changeHeadUniversity);
    connect(ui->lineEditLastNameHeadUniversity, &QLineEdit::textChanged, this, &InsertManyPassingPractice::changeHeadUniversity);
    connect(ui->comboBoxDepartmen, SIGNAL(activated(QString)), this, SLOT(changeHeadUniversity()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    changeHeadEmployer();
    changeHeadUniversity();
    changeHeadEmployer();
}

InsertManyPassingPractice::~InsertManyPassingPractice()
{
    delete ui;
}

ListOfPassingPractice &InsertManyPassingPractice::getList()
{
    return m_listPassingPractice;
}

void InsertManyPassingPractice::fillComboBox()

{
    ListOfDepartment listDepartment;
    ListOfGroup listGroup;
    m_modelGroup =new AbstractGroupsModel();
    m_modelDepartments = new AbstractDepartmentsModel();
    listDepartment=m_modelDepartments->getList();
    listGroup=m_modelGroup->getList();
    for(int i=0;i<listGroup.count();i++){
        ui->comboBoxGroup->addItem(listGroup.getByIndex(i)->getnumber());
    }
    for(int i=0;i<listDepartment.count();i++){
        ui->comboBoxDepartmen->addItem(listDepartment.getByIndex(i)->getname());
    }

}

void InsertManyPassingPractice::onActionClicked()
{
     QModelIndexList indexStudent = ui->tableViewStudent->selectionModel()->selectedRows();
     if(indexStudent.count()==0){
         QMessageBox::critical(this,"Ошибка","Выбeрbте студентов!");
         return;
     }
     QModelIndexList indexHeadEmployer = ui->tableViewHeadEmployer->selectionModel()->selectedRows();
     if(indexHeadEmployer.count()==0){
         QMessageBox::critical(this,"Ошибка","Выбeрите руководителя от предприятия!");
         return;
     }

     QModelIndexList indexHeadUniversity = ui->tableViewHeadUniversity->selectionModel()->selectedRows();
     if(indexHeadUniversity.count()==0){
         QMessageBox::critical(this,"Ошибка","Выбeрите руководителя от университета!");
         return;
     }

     for(int i=0;i<indexStudent.count();i++){

         PassingPractice_ptr passing;
         passing.reset(new PassingPractice());
         passing->setstuden(m_modelStudent->getStudent(i));
         passing->sethead_employer(m_modelHeadEmployer->getHeadEmployer(indexHeadEmployer[0].row()));
         passing->sethead_university(m_modelHeadUniversity->getStaffUniversity(indexHeadUniversity[0].row()));
         passing->setpractice(m_practice);
         m_listPassingPractice.insert(i,passing);
     }
     QDialog::accept();

}

void InsertManyPassingPractice::changeHeadEmployer()
{
    m_modelHeadEmployer->search(ui->lineEditNameHeadEmployer->text(),ui->lineEditLastNameHeadEmployer->text(),m_employer->getemployer_id());

}

void InsertManyPassingPractice::changeHeadUniversity()

{
    m_modelHeadUniversity->search(ui->lineEditNameHeadUniversity->text(),ui->lineEditLastNameHeadUniversity->text(),ui->comboBoxDepartmen->currentText());

}

void InsertManyPassingPractice::changeStudents()

{
    m_modelStudent->search("","",ui->comboBoxGroup->currentText());

}
