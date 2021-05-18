#include "../include/department_precompiled_header.h"

#include "../include/Head_employer.h"
#include "../include/Employer.h"
#include "../include/Person.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(HeadEmployer, HeadEmployer)

namespace qx {

template <>
void register_class(QxClass<HeadEmployer> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Head_employer");

   pData = t.id(& HeadEmployer::m_head_employer, "Head_employer_id", 0);

   pRelation = t.relationManyToOne(& HeadEmployer::m_employer, "employer", 0);
   pRelation = t.relationManyToOne(& HeadEmployer::m_person, "person_id", 0);
   pRelation = t.relationOneToMany(& HeadEmployer::m_list_of_passing_practice, "list_of_passing_practice", "head_employer_id", 0);
   pRelation = t.relationOneToMany(& HeadEmployer::m_list_of_reports, "list_of_reports", "Head_employer_id", 0);



   qx::QxValidatorX<HeadEmployer> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

HeadEmployer::HeadEmployer() : m_head_employer(0) { ; }

HeadEmployer::HeadEmployer(const long & id) : m_head_employer(id) { ; }

HeadEmployer::~HeadEmployer() { ; }

long HeadEmployer::getHeadEmployer() const { return m_head_employer; }

HeadEmployer::Employer_ptr HeadEmployer::getemployer() const { return m_employer; }

HeadEmployer::Person_ptr HeadEmployer::getperson() const { return m_person; }

HeadEmployer::ListOfPassingPractice HeadEmployer::getlist_of_passing_practice() const { return m_list_of_passing_practice; }

HeadEmployer::ListOfPassingPractice & HeadEmployer::list_of_passing_practice() { return m_list_of_passing_practice; }

const HeadEmployer::ListOfPassingPractice & HeadEmployer::list_of_passing_practice() const { return m_list_of_passing_practice; }

HeadEmployer::ListOfReport HeadEmployer::getlist_of_reports() const { return m_list_of_reports; }

HeadEmployer::ListOfReport & HeadEmployer::list_of_reports() { return m_list_of_reports; }

const HeadEmployer::ListOfReport & HeadEmployer::list_of_reports() const { return m_list_of_reports; }


void HeadEmployer::setHeadEmployer_id(const long & val) { m_head_employer = val; }

void HeadEmployer::setemployer(const HeadEmployer::Employer_ptr & val) { m_employer = val; }

void HeadEmployer::setperson(const HeadEmployer::Person_ptr & val) { m_person = val; }

void HeadEmployer::setlist_of_passing_practice(const HeadEmployer::ListOfPassingPractice & val) { m_list_of_passing_practice = val; }

void HeadEmployer::setlist_of_reports(const HeadEmployer::ListOfReport & val) { m_list_of_reports = val; }

HeadEmployer::Employer_ptr HeadEmployer::getemployer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getemployer(); }
   QString sRelation = "{HeadEmployer_id} | employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadEmployer tmp;
   tmp.m_head_employer = this->m_head_employer;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_employer = tmp.m_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_employer;
}

HeadEmployer::Person_ptr HeadEmployer::getperson(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getperson(); }
   QString sRelation = "{HeadEmployer_id} | person_id";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadEmployer tmp;
   tmp.m_head_employer = this->m_head_employer;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_person = tmp.m_person; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_person;
}

HeadEmployer::ListOfPassingPractice HeadEmployer::getlist_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_passing_practice(); }
   QString sRelation = "{HeadEmployer_id} | list_of_passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadEmployer tmp;
   tmp.m_head_employer = this->m_head_employer;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passing_practice = tmp.m_list_of_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passing_practice;
}

HeadEmployer::ListOfPassingPractice & HeadEmployer::list_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_passing_practice(); }
   QString sRelation = "{HeadEmployer_id} | list_of_passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadEmployer tmp;
   tmp.m_head_employer = this->m_head_employer;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passing_practice = tmp.m_list_of_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passing_practice;
}

HeadEmployer::ListOfReport HeadEmployer::getlist_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_reports(); }
   QString sRelation = "{HeadEmployer_id} | list_of_reports";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadEmployer tmp;
   tmp.m_head_employer = this->m_head_employer;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_reports = tmp.m_list_of_reports; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_reports;
}

HeadEmployer::ListOfReport & HeadEmployer::list_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_reports(); }
   QString sRelation = "{HeadEmployer_id} | list_of_reports";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadEmployer tmp;
   tmp.m_head_employer = this->m_head_employer;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_reports = tmp.m_list_of_reports; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_reports;
}

