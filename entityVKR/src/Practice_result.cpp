#include "../include/department_precompiled_header.h"

#include "../include/Practice_result.h"
#include "../include/Report.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(PracticeResult, PracticeResult)

namespace qx {

template <>
void register_class(QxClass<PracticeResult> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_practice_result");

   pData = t.id(& PracticeResult::m_practice_result_id, "practice_result_id", 0);

   pData = t.data(& PracticeResult::m_estimate_employer, "estimate_employer", 0, true, true);
   pData = t.data(& PracticeResult::m_estimate_university, "estimate_university", 0, true, true);

   pRelation = t.relationOneToMany(& PracticeResult::m_list_of_reports, "list_of_reports", "practice_result", 0);

   pRelation = t.relationManyToOne(& PracticeResult::m_student, "Student_id", 0);

   pRelation = t.relationManyToOne(& PracticeResult::m_passing_practice, "passing_practice", 0);
   pRelation->getDataMember()->setName("passing_practice_id");

   qx::QxValidatorX<PracticeResult> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

PracticeResult::PracticeResult() : m_practice_result_id(0) { ; }

PracticeResult::PracticeResult(const long & id) : m_practice_result_id(id) { ; }

PracticeResult::~PracticeResult() { ; }

long PracticeResult::getpractice_result_id() const { return m_practice_result_id; }

QString PracticeResult::getestimate_employer() const { return m_estimate_employer; }

QString PracticeResult::getestimate_university() const { return m_estimate_university; }

PracticeResult::ListOfReport PracticeResult::getlist_of_reports() const { return m_list_of_reports; }

PracticeResult::ListOfReport & PracticeResult::list_of_reports() { return m_list_of_reports; }

const PracticeResult::ListOfReport & PracticeResult::list_of_reports() const { return m_list_of_reports; }

PracticeResult::Student_ptr PracticeResult::getStudent() const { return m_student; }

PracticeResult::PassingPractice_ptr PracticeResult::getpassing_practice() const { return m_passing_practice; }

void PracticeResult::setpractice_result_id(const long & val) { m_practice_result_id = val; }

void PracticeResult::setestimate_employer(const QString & val) { m_estimate_employer = val; }

void PracticeResult::setestimate_university(const QString & val) { m_estimate_university = val; }

void PracticeResult::setlist_of_reports(const PracticeResult::ListOfReport & val) { m_list_of_reports = val; }



void PracticeResult::setStudent(const PracticeResult::Student_ptr & val) { m_student = val; }

void PracticeResult::setpassing_practice(const PracticeResult::PassingPractice_ptr & val) { m_passing_practice = val; }

PracticeResult::ListOfReport PracticeResult::getlist_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_reports(); }
   QString sRelation = "{practice_result_id} | list_of_reports";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   PracticeResult tmp;
   tmp.m_practice_result_id = this->m_practice_result_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_reports = tmp.m_list_of_reports; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_reports;
}

PracticeResult::ListOfReport & PracticeResult::list_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_reports(); }
   QString sRelation = "{practice_result_id} | list_of_reports";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   PracticeResult tmp;
   tmp.m_practice_result_id = this->m_practice_result_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_reports = tmp.m_list_of_reports; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_reports;
}



PracticeResult::Student_ptr PracticeResult::getStudent(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getStudent(); }
   QString sRelation = "{PracticeResult_id} | Student";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   PracticeResult tmp;
   tmp.m_practice_result_id = this->m_practice_result_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_student = tmp.m_student; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_student;
}

PracticeResult::PassingPractice_ptr PracticeResult::getpassing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getpassing_practice(); }
   QString sRelation = "{practice_result_id} | passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   PracticeResult tmp;
   tmp.m_practice_result_id = this->m_practice_result_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_passing_practice = tmp.m_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_passing_practice;
}

