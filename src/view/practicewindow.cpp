#include "view/practicewindow.h"
#include "ui_practicewindow.h"

PracticeWindow::PracticeWindow(QStringList names,ListOfEmployer listEmployers, Practice_ptr practice, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PracticeWindow)
{
    ui->setupUi(this);
    m_practice.reset(new Practice());
    m_names=names;
    m_practice=practice;
    m_listEmployers=listEmployers;
    initElementsChange();
    iniconnection();
    m_modelPassingPractice=new AbstractPassingPracticeModel(m_practice->getlist_of_passing_practice());
    ui->tableViewPassingPractice->setModel(m_modelPassingPractice);
    ui->lineEditCustomId->setText(m_practice->getcustomid());

    if(m_practice->getlist_of_TestPractice().count()!=0){

        connect(ui->pushButtonTest,SIGNAL(clicked()),this,SLOT(onGetTestClicked()));
        ui->pushButtonTest->setText("Тестовое задание");


    }else{

        connect(ui->pushButtonTest,SIGNAL(clicked()),this,SLOT(onInsertTestClicked()));
        ui->pushButtonDeleteTest->hide();



    }


}

PracticeWindow::PracticeWindow(QStringList names,ListOfEmployer listEmployers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PracticeWindow)
{
    ui->setupUi(this);
    m_practice.reset(new Practice());
    m_listEmployers=listEmployers;
    m_names=names;
    initElementInsert();
    iniconnection();
    m_modelPassingPractice=new AbstractPassingPracticeModel(m_practice->getlist_of_passing_practice());
    ui->tableViewPassingPractice->setModel(m_modelPassingPractice);
    ui->pushButtonDeleteTest->hide();
    //ui->pushButtonInserPassingPractice->setEnabled(false);
    //ui->pushButtonDeletePassingPractice->setEnabled(false);
    connect(ui->pushButtonTest,SIGNAL(clicked()),this,SLOT(onInsertTestClicked()));
    ui->pushButtonInserManyPassingPractice->setDisabled(true);
}

PracticeWindow::~PracticeWindow()
{
    delete ui;
}

Practice_ptr PracticeWindow::getPractice()
{

    m_practice->setlist_of_passing_practice(m_modelPassingPractice->getListPassingpractice());
    m_practice->setlist_of_TestPractice(m_listTestPractice);
    m_practice->setemployer(m_listEmployers.getByIndex(ui->comboBox->currentIndex()));
    m_practice->setbeginning(ui->dateEditbegining->date());
    m_practice->setending(ui->dateEditEnding->date());
    m_practice->setname(ui->lineEditName->text());
    if(!ui->lineEditCustomId->text().isEmpty()){
        m_practice->setcustomid(ui->lineEditCustomId->text());
    }else{

        m_practice->setcustomid(genCustomId());

    }

    return m_practice;
}

void PracticeWindow::iniconnection()
{
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(onOkClicked()));
    connect(ui->pushButtonAction,SIGNAL(clicked()),this,SLOT(onActionClicked()));
    connect(ui->tableViewPassingPractice,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onTablePassingPracticeclicked()));
    connect(ui->pushButtonInserPassingPractice,SIGNAL(clicked()),this,SLOT(onInsertPassingPracticeClicked()));
    connect(ui->pushButtonDeletePassingPractice,SIGNAL(clicked()),this,SLOT(onDeletePassingPractice()));
    connect(ui->pushButtonDeleteTest,SIGNAL(clicked()),this,SLOT(onDeleteTestClicked()));
    connect(ui->pushButtonGenCustomId,SIGNAL(clicked()),this,SLOT(onGenClicked()));
    connect(ui->pushButtonCopy,SIGNAL(clicked()),this,SLOT(onCopyClicked()));
    connect(ui->pushButtonInserManyPassingPractice,SIGNAL(clicked()),this,SLOT(onInsertManyPassingPracticeClicked()));
    connect(ui->comboBoxName, &QComboBox::currentTextChanged, this, &PracticeWindow::comboBoxNameChanged);


}

void PracticeWindow::initElementsChange()
{

    for(int i=0;i<m_listEmployers.count();i++){
        ui->comboBox->addItem(m_listEmployers.getByIndex(i)->getname());
    }
    for(int i=0;i<m_names.count();i++){
        ui->comboBoxName->addItem(m_names.at(i));
    }
    if(m_practice->getemployer()!=nullptr){
        ui->comboBox->setCurrentText(m_practice->getemployer()->getname());
    }
    ui->lineEditName->setText(m_practice->getname());
    ui->dateEditbegining->setDate(m_practice->getbeginning());
    ui->dateEditEnding->setDate(m_practice->getending());
    ui->pushButtonAction->setText("Изменить");
    ui->pushButtonOk->setText("Ок");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Практика");
    ui->comboBoxName->setCurrentText(m_practice->getname());


}

void PracticeWindow::initElementInsert()
{
    for(int i=0;i<m_listEmployers.count();i++){
        ui->comboBox->addItem(m_listEmployers.getByIndex(i)->getname());
    }
    for(int i=0;i<m_names.count();i++){
        ui->comboBoxName->addItem(m_names.at(i));
    }
    ui->pushButtonAction->setText("Создать");
    ui->pushButtonOk->setText("Отмена");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Практика");

}

QString PracticeWindow::genCustomId()
{
    QString res;
    static QMap<QString, QString> toTranslit;
    toTranslit["а"] = 'a';
    toTranslit["б"] = 'b';
    toTranslit["в"] = 'v';
    toTranslit["г"] = 'g';
    toTranslit["д"] = 'd';
    toTranslit["е"] = 'e';
    toTranslit["ё"] = "jo";
    toTranslit["ж"] = "zh";
    toTranslit["з"] = 'z';
    toTranslit["и"] = 'i';
    toTranslit["й"] = 'j';
    toTranslit["к"] = 'k';
    toTranslit["л"] = 'l';
    toTranslit["м"] = 'm';
    toTranslit["н"] = 'n';
    toTranslit["о"] = 'o';
    toTranslit["п"] = 'p';
    toTranslit["р"] = 'r';
    toTranslit["с"] = 's';
    toTranslit["т"] = 't';
    toTranslit["у"] = 'u';
    toTranslit["ф"] = 'f';
    toTranslit["х"] = 'h';
    toTranslit["ц"] = 'c';
    toTranslit["ч"] = "ch";
    toTranslit["ш"] = "sh";
    toTranslit["щ"] = 'w';
    toTranslit["ъ"] = '#';
    toTranslit["ы"] = 'y';
    toTranslit["ь"] = '\'';
    toTranslit["э"] = "e";
    toTranslit["ю"] = "ju";
    toTranslit["я"] = "ja";
    toTranslit[" "] = "_";
    QString name=ui->comboBox->currentText();
    for (int i = 0; i < name.length(); i++) {
        const QString ch = name.at(i);
        const QString lowerCh = ch.toLower();
        if (toTranslit.contains(lowerCh)) {
            QString tmp = ch == lowerCh ? toTranslit[lowerCh] : toTranslit[lowerCh].toUpper();
            res += tmp;
        } else
            res += ch;
    }
    res+=ui->dateEditbegining->date().toString("yy");
    return res;

}

void PracticeWindow::onOkClicked()
{
    QDialog::close();

}

void PracticeWindow::onActionClicked()
{


    QDialog::accept();

}

void PracticeWindow::onTablePassingPracticeclicked()
{
    QModelIndexList index = ui->tableViewPassingPractice->selectionModel()->selectedRows();

    PassingPracticeWindow *w=new PassingPracticeWindow(m_modelPassingPractice->getPassingpractice(index[0].row()));
    if(w->exec()==QDialog::Accepted){


        //m_practice->setlist_of_passing_practice(m_modelPassingPractice->getListPassingpractice());

    }



}

void PracticeWindow::onInsertPassingPracticeClicked()
{
    PassingPracticeWindow *w=new PassingPracticeWindow(m_practice->getemployer(),m_practice);
    if(w->exec()==QDialog::Accepted){
        m_modelPassingPractice->save(w->getPassingPractice());
        // m_practice->setlist_of_passing_practice(m_modelPassingPractice->getListPassingpractice());
    }
}

void PracticeWindow::onDeletePassingPractice()
{
    QModelIndexList index = ui->tableViewPassingPractice->selectionModel()->selectedRows();
    if(index.count()!=0){
        m_modelPassingPractice->deletePassingPractice(index[0].row());
        m_practice->setlist_of_passing_practice(m_modelPassingPractice->getListPassingpractice());
    }
    ui->tableViewPassingPractice->clearSelection();
    ui->tableViewPassingPractice->clearFocus();

}

void PracticeWindow::onInsertTestClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Загрузить тестовое задание", QStandardPaths::writableLocation(QStandardPaths::HomeLocation), QFileDialog::tr("*"));

    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly)){
        QByteArray array=file.readAll();

        QFileInfo fileInfo(file.fileName());
        QString nameTest(fileInfo.fileName());
        TestPractice_ptr testpractice;
        testpractice.reset(new TestPractice());
        testpractice->setdata(array);
        testpractice->setname(nameTest);
        testpractice->setpractice(m_practice);
        testpractice->setemployer(m_practice->getemployer());
        m_listTestPractice.insert(0,testpractice);
        file.close();
        disconnect(ui->pushButtonTest,SIGNAL(clicked()),this,SLOT(onInsertTestClicked()));
        connect(ui->pushButtonTest,SIGNAL(clicked()),this,SLOT(onGetTestClicked()));
        ui->pushButtonTest->setText("Тестовое задание");
        ui->pushButtonDeleteTest->show();
    }


}

void PracticeWindow::onGetTestClicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, "Тестовое задание", m_practice->getlist_of_TestPractice().getByIndex(0)->getname());

    QFile file(fileName);

    file.open(QIODevice::WriteOnly);

    file.write(m_practice->getlist_of_TestPractice().getByIndex(0)->getdata());

    file.close();


}

void PracticeWindow::onDeleteTestClicked()
{
    AbstactSubClassModel model;
    model.deleteTestPractice(m_practice->getlist_of_TestPractice().getByIndex(0));
    listOfTestPractice list;
    m_practice->setlist_of_TestPractice(list);
    disconnect(ui->pushButtonTest,SIGNAL(clicked()),this,SLOT(onGetTestClicked()));
    connect(ui->pushButtonTest,SIGNAL(clicked()),this,SLOT(onInsertTestClicked()));
    ui->pushButtonDeleteTest->hide();
    ui->pushButtonTest->setText("Загрузить задание");



}

void PracticeWindow::onGenClicked()
{

    ui->lineEditCustomId->setText(genCustomId());



}

void PracticeWindow::onCopyClicked()
{
    QApplication::clipboard()->setText(ui->lineEditCustomId->text());

}

void PracticeWindow::onInsertManyPassingPracticeClicked()
{
    InsertManyPassingPractice *w=new InsertManyPassingPractice(m_practice->getemployer(),m_practice);
    if(w->exec()==QDialog::Accepted){

        ListOfPassingPractice list=w->getList();
        for(int i=0;i<list.count();i++){
            m_modelPassingPractice->save(list.getByIndex(i));
        }

    }

}

void PracticeWindow::comboBoxNameChanged()
{
    ui->lineEditName->setText(ui->comboBoxName->currentText());

}


