#include "../include/department_precompiled_header.h"

#include "../include/Report.h"
#include "../include/Practice_result.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Report, Report)

namespace qx {

template <>
void register_class(QxClass<Report> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Report");

   pData = t.id(& Report::m_Report_id, "Report_id", 0);

   pData = t.data(& Report::m_report, "report", 0, true, true);
   pData = t.data(& Report::m_feedback_university, "feedback_university", 0, true, true);
   pData = t.data(& Report::m_feedback_employer, "feedback_employer", 0, true, true);

   pRelation = t.relationManyToOne(& Report::m_practice_result, "practice_result", 0);
   pRelation = t.relationManyToOne(& Report::m_head_university, "Head_university_id", 0);

   pRelation = t.relationManyToOne(& Report::m_head_employer, "Head_employer_id", 0);

   pRelation = t.relationManyToOne(& Report::m_student, "Student_id", 0);

   pRelation = t.relationManyToOne(& Report::m_passing_practice, "passing_practice", 0);
   pRelation->getDataMember()->setName("passing_practice_id");


   qx::QxValidatorX<Report> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Report::Report() : m_Report_id(0) { ; }

Report::Report(const long & id) : m_Report_id(id) { ; }

Report::~Report() { ; }

long Report::getReport_id() const { return m_Report_id; }

QByteArray Report::getreport() const { return m_report; }

QString Report::getfeedback_university() const { return m_feedback_university; }

QString Report::getfeedback_employer() const { return m_feedback_employer; }

Report::PracticeResult_ptr Report::getpractice_result() const { return m_practice_result; }

Report::HeadUniversity_ptr Report::gethead_university() const { return m_head_university; }

Report::HeadEmployer_ptr Report::gethead_employer() const { return m_head_employer; }

Report::Student_ptr Report::getstudent() const { return m_student; }

Report::PassingPractice_ptr Report::getpassing_practice() const { return m_passing_practice; }

void Report::setReport_id(const long & val) { m_Report_id = val; }

void Report::setreport(const QByteArray & val) { m_report = val; }

void Report::setfeedback_university(const QString & val) { m_feedback_university = val; }

void Report::setfeedback_employer(const QString & val) { m_feedback_employer = val; }

void Report::setpractice_result(const Report::PracticeResult_ptr & val) { m_practice_result = val; }

void Report::sethead_university(const Report::HeadUniversity_ptr & val) { m_head_university = val; }

void Report::sethead_employer(const Report::HeadEmployer_ptr & val) { m_head_employer = val; }

void Report::setstudent(const Report::Student_ptr & val) { m_student = val; }

void Report::setpassing_practice(const Report::PassingPractice_ptr & val) { m_passing_practice = val; }


Report::PracticeResult_ptr Report::getpractice_result(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getpractice_result(); }
   QString sRelation = "{Report_id} | practice_result";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Report tmp;
   tmp.m_Report_id = this->m_Report_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_practice_result = tmp.m_practice_result; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_practice_result;
}

Report::HeadUniversity_ptr Report::gethead_university(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return gethead_university(); }
   QString sRelation = "{Report_id} | Head_university";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Report tmp;
   tmp.m_Report_id = this->m_Report_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_head_university = tmp.m_head_university; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_head_university;
}

Report::HeadEmployer_ptr Report::gethead_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return gethead_employer(); }
   QString sRelation = "{Report_id} | Head_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Report tmp;
   tmp.m_Report_id = this->m_Report_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_head_employer = tmp.m_head_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_head_employer;
}

Report::Student_ptr Report::getstudent(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getstudent(); }
   QString sRelation = "{Report_id} | Student";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Report tmp;
   tmp.m_Report_id = this->m_Report_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_student = tmp.m_student; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_student;
}

Report::PassingPractice_ptr Report::getpassing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getpassing_practice(); }
   QString sRelation = "{report_id} | passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Report tmp;
   tmp.m_Report_id = this->m_Report_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_passing_practice = tmp.m_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_passing_practice;
}
