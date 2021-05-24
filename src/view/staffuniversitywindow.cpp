#include "view/staffuniversitywindow.h"
#include "ui_staffuniversitywindow.h"

StaffUniversityWindow::StaffUniversityWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffUniversityWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Сотрудники университета");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    m_staffUniversityModel=new AbstractStaffUniversityModel();
    ui->tableViewStaff->setModel(m_staffUniversityModel);
    m_departmentModel =new AbstractDepartmentsModel();
    ui->tableViewDepatment->setModel(m_departmentModel);
    connect(ui->pushButtonDeleteStaff,SIGNAL(clicked()),this,SLOT(onDeleteStaffClicked()));
    connect(ui->pushButtonInsertStaff,SIGNAL(clicked()),this,SLOT(onInsertStaffClicked()));
    connect(ui->tableViewStaff,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableStaffClicked()));
    connect(ui->pushButtonInsertDepartment,SIGNAL(clicked()),this,SLOT(onInsertDepartmentClicked()));
    connect(ui->pushButtonDeleteDepartment,SIGNAL(clicked()),this,SLOT(onDeleteDepartmentClicked()));
    connect(ui->tableViewDepatment,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTableDepartmentClicked()));
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
}

StaffUniversityWindow::~StaffUniversityWindow()
{
    delete ui;
}

void StaffUniversityWindow::onDeleteStaffClicked()
{
    QModelIndexList index = ui->tableViewStaff->selectionModel()->selectedRows();
    if(index.count()>0){
    m_staffUniversityModel->deleteStaffUniversityGlobal(index[0].row());
    QMessageBox::information(this,"Успех","Сотрудник удален!");
    }
    ui->tableViewStaff->clearSelection();
    ui->tableViewStaff->clearFocus();

}

void StaffUniversityWindow::onInsertStaffClicked()
{
    InsertStaffUniversity *insert=new InsertStaffUniversity(m_departmentModel->getList());

    if(insert->exec()==InsertStaffUniversity::Accepted){
       m_staffUniversityModel->saveStaffUniversityGlobal(insert->getStaffUniversity());
       QMessageBox::information(this,"Успех","Сотрудник добавлен!");
    }


}

void StaffUniversityWindow::onTableStaffClicked()
{
    HeadUniversity_ptr staff;
    staff.reset(new HeadUniversity());
    QModelIndexList index = ui->tableViewStaff->selectionModel()->selectedRows();
    staff=m_staffUniversityModel->getStaffUniversity(index[0].row());
    InsertStaffUniversity *insert=new InsertStaffUniversity(m_departmentModel->getList());
    insert->insert(staff);
    if(insert->exec()==InsertStaffUniversity::Accepted){
       m_staffUniversityModel->saveStaffUniversityGlobal(insert->getStaffUniversity());
       QMessageBox::information(this,"Успех","Изменения внесены!");
    }
    ui->tableViewStaff->clearSelection();
    ui->tableViewStaff->clearFocus();

}

void StaffUniversityWindow::onDeleteDepartmentClicked()
{
    QModelIndexList index = ui->tableViewDepatment->selectionModel()->selectedRows();
    if(index.count()>0){
    m_departmentModel->deleteDepartment(index[0].row());
    QMessageBox::information(this,"Успех","Кфедра удалена!");
    m_staffUniversityModel->loadListGlobal();
    }
    ui->tableViewDepatment->clearSelection();
    ui->tableViewDepatment->clearFocus();

}

void StaffUniversityWindow::onInsertDepartmentClicked()
{
    InsertDepartment*insert=new InsertDepartment();

    if(insert->exec()==InsertDepartment::Accepted){
      m_departmentModel->saveDepartment(insert->getDepartment());
       QMessageBox::information(this,"Успех","Кафедра добавлена!");
    }
    m_staffUniversityModel->loadListGlobal();
    ui->tableViewDepatment->clearSelection();
    ui->tableViewDepatment->clearFocus();

}

void StaffUniversityWindow::onTableDepartmentClicked()
{

    Department_ptr department;
    department.reset(new Department());
    QModelIndexList index = ui->tableViewDepatment->selectionModel()->selectedRows();
    department= m_departmentModel->getDepartment(index[0].row());
    InsertDepartment *insert=new InsertDepartment();
    insert->insert(department);
    if(insert->exec()==InsertDepartment::Accepted){
      m_departmentModel->saveDepartment(insert->getDepartment());
       QMessageBox::information(this,"Успех","Изменения внесены!");
    }
   m_staffUniversityModel->loadListGlobal();
   ui->tableViewDepatment->clearSelection();
   ui->tableViewDepatment->clearFocus();

}

void StaffUniversityWindow::onOkClicked()
{

    QDialog::accept();

}
