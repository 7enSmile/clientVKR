/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/03/24 12:12) : please, do NOT modify this file ! **
************************************************************************************************/

#include "../include/department_precompiled_header.h"

#include "../include/Practice.h"
#include "../include/Employer.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Practice, Practice)

namespace qx {

template <>
void register_class(QxClass<Practice> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Practice");
   pData = t.data(& Practice::m_semester, "semester", 0, true, true);

   pData = t.data(& Practice::m_customid, "customid", 0, true, true);

   pData = t.id(& Practice::m_Practice_id, "Practice_id", 0);
   pData = t.data(& Practice::m_beginning, "beginning", 0, true, true);
   pData = t.data(& Practice::m_ending, "ending", 0, true, true);
   pRelation = t.relationManyToOne(& Practice::m_employer, "employer", 0);
   pRelation->getDataMember()->setName("employer_id");


   pRelation = t.relationOneToMany(& Practice::m_list_of_passing_practice, "list_of_passing_practice", "practice", 0);
   pRelation = t.relationManyToOne(& Practice::m_education_program, "Education_program", 0);
   pRelation->getDataMember()->setName("Education_program_id");
   pRelation = t.relationOneToMany(& Practice::m_list_of_TestPractice, "list_of_TestPractice", "practice", 0);


   qx::QxValidatorX<Practice> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Practice::Practice() : m_Practice_id(0) { ; }

Practice::Practice(const long & id) : m_Practice_id(id) { ; }

Practice::~Practice() { ; }

long Practice::getPractice_id() const { return m_Practice_id; }

QDate Practice::getbeginning() const { return m_beginning; }

QDate Practice::getending() const { return m_ending; }

int Practice::getsemester() const { return m_semester; }

QString Practice::getcustomid() const { return m_customid; }

Practice::Employer_ptr Practice::getemployer() const { return m_employer; }


Practice::ListOfPassingPractice Practice::getlist_of_passing_practice() const { return m_list_of_passing_practice; }

Practice::EducationProgram_ptr Practice::geteducation_program() const { return m_education_program; }


Practice::ListOfPassingPractice & Practice::list_of_passing_practice() { return m_list_of_passing_practice; }

const Practice::ListOfPassingPractice & Practice::list_of_passing_practice() const { return m_list_of_passing_practice; }


Practice::ListOfTestPractice Practice::getlist_of_TestPractice() const { return m_list_of_TestPractice; }

Practice::ListOfTestPractice & Practice::list_of_TestPractice() { return m_list_of_TestPractice; }

const Practice::ListOfTestPractice & Practice::list_of_TestPractice() const { return m_list_of_TestPractice; }

void Practice::setpractice_id(const long & val) { m_Practice_id = val; }

void Practice::setbeginning(const QDate & val) { m_beginning = val; }

void Practice::setending(const QDate & val) { m_ending = val; }

void Practice::setcustomid(const QString & val) { m_customid = val; }


void Practice::setlist_of_passing_practice(const Practice::ListOfPassingPractice & val) { m_list_of_passing_practice = val; }

void Practice::seteducation_program(const Practice::EducationProgram_ptr & val) { m_education_program = val; }

void Practice::setemployer(const Practice::Employer_ptr & val) { m_employer = val; }

void Practice::setsemester(const int & val) { m_semester = val; }

void Practice::setlist_of_TestPractice(const Practice::ListOfTestPractice & val) { m_list_of_TestPractice = val; }



Practice::ListOfPassingPractice Practice::getlist_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_passing_practice(); }
   QString sRelation = "{Practice_id} | list_of_passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Practice tmp;
   tmp.m_Practice_id = this->m_Practice_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passing_practice = tmp.m_list_of_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passing_practice;
}

Practice::ListOfPassingPractice & Practice::list_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_passing_practice(); }
   QString sRelation = "{Practice_id} | list_of_passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Practice tmp;
   tmp.m_Practice_id = this->m_Practice_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passing_practice = tmp.m_list_of_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passing_practice;
}

Practice::EducationProgram_ptr Practice::geteducation_program(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return geteducation_program(); }
   QString sRelation = "{Practice_id} | education_program";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Practice tmp;
   tmp.m_Practice_id = this->m_Practice_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_education_program = tmp.m_education_program; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_education_program;
}

Practice::Employer_ptr Practice::getemployer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getemployer(); }
   QString sRelation = "{practice_id} | employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Practice tmp;
   tmp.m_Practice_id = this->m_Practice_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_employer = tmp.m_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_employer;
}

Practice::ListOfTestPractice Practice::getlist_of_TestPractice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_TestPractice(); }
   QString sRelation = "{Practice_id} | list_of_TestPractice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Practice tmp;
   tmp.m_Practice_id = this->m_Practice_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_TestPractice = tmp.m_list_of_TestPractice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_TestPractice;
}

Practice::ListOfTestPractice & Practice::list_of_TestPractice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_TestPractice(); }
   QString sRelation = "{Practice_id} | list_of_TestPractice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Practice tmp;
   tmp.m_Practice_id = this->m_Practice_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_TestPractice = tmp.m_list_of_TestPractice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_TestPractice;
}

