/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/03/24 12:12) : please, do NOT modify this file ! **
************************************************************************************************/

#include "../include/department_precompiled_header.h"

#include "../include/Employer.h"
#include "../include/Activity.h"
#include "../include/Collaboration.h"
#include "../include/Task.h"
#include "../include/Practice.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Employer, Employer)

namespace qx {

template <>
void register_class(QxClass<Employer> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Employer");

   pData = t.id(& Employer::m_Employer_id, "Employer_id", 0);

   pData = t.data(& Employer::m_name, "name", 0, true, true);

   pRelation = t.relationManyToMany(& Employer::m_list_of_activity, "list_of_activity", "t_qxee_activity_Employer", "Employer_id", "Activity_id", 0);
   pRelation = t.relationManyToMany(& Employer::m_list_of_collaboration, "list_of_collaboration", "t_qxee_collaboration_Employer", "Employer_id", "Collaboration_id", 0);
   pRelation = t.relationManyToMany(& Employer::m_list_of_task, "list_of_task", "t_qxee_task_Employer", "Employer_id", "Task_id", 0);
   pRelation = t.relationOneToMany(& Employer::m_list_of_practice, "list_of_practice", "employer", 0);
   pRelation = t.relationOneToMany(& Employer::m_list_of_events, "list_of_events", "employer", 0);
   pRelation = t.relationOneToMany(& Employer::m_list_of_head_employer, "list_of_head_employer", "employer", 0);
   pRelation = t.relationOneToMany(& Employer::m_list_of_contact_employer, "list_of_contact_employer", "employer", 0);
   pRelation = t.relationOneToMany(& Employer::m_list_of_passing_practice, "list_of_passing_practice", "employer", 0);
   pRelation = t.relationManyToMany(& Employer::m_list_of_result_education, "list_of_result_education", "t_qxee_Employer_result_education", "Employer_id", "Result_discipline_id", 0);
   pRelation = t.relationOneToMany(& Employer::m_list_of_TestPractice, "list_of_TestPractice", "employer", 0);



   qx::QxValidatorX<Employer> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Employer::Employer() : m_Employer_id(0) { ; }

Employer::Employer(const long & id) : m_Employer_id(id) { ; }

Employer::~Employer() { ; }

long Employer::getemployer_id() const { return m_Employer_id; }

QString Employer::getname() const { return m_name; }

Employer::ListOfActivity Employer::getlist_of_activity() const { return m_list_of_activity; }

Employer::ListOfActivity & Employer::list_of_activity() { return m_list_of_activity; }

const Employer::ListOfActivity & Employer::list_of_activity() const { return m_list_of_activity; }

Employer::ListOfCollaboration Employer::getlist_of_collaboration() const { return m_list_of_collaboration; }

Employer::ListOfCollaboration & Employer::list_of_collaboration() { return m_list_of_collaboration; }

const Employer::ListOfCollaboration & Employer::list_of_collaboration() const { return m_list_of_collaboration; }

Employer::ListOfTask Employer::getlist_of_task() const { return m_list_of_task; }

Employer::ListOfTask & Employer::list_of_task() { return m_list_of_task; }

const Employer::ListOfTask & Employer::list_of_task() const { return m_list_of_task; }

Employer::ListOfPractice Employer::getlist_of_practice() const { return m_list_of_practice; }

Employer::ListOfPractice & Employer::list_of_practice() { return m_list_of_practice; }

const Employer::ListOfPractice & Employer::list_of_practice() const { return m_list_of_practice; }

Employer::ListOfHeadEmployer Employer::getlist_of_head_employer() const { return m_list_of_head_employer; }

Employer::ListOfHeadEmployer & Employer::list_of_head_employer() { return m_list_of_head_employer; }

const Employer::ListOfHeadEmployer & Employer::list_of_head_employer() const { return m_list_of_head_employer; }

Employer::ListOfContactEmployer Employer::getlist_of_contact_employer() const { return m_list_of_contact_employer; }

Employer::ListOfContactEmployer & Employer::list_of_contact_employer() { return m_list_of_contact_employer; }

const Employer::ListOfContactEmployer & Employer::list_of_contact_employer() const { return m_list_of_contact_employer; }

Employer::ListOfPassingPractice Employer::getlist_of_passing_practice() const { return m_list_of_passing_practice; }

Employer::ListOfPassingPractice & Employer::list_of_passing_practice() { return m_list_of_passing_practice; }

const Employer::ListOfPassingPractice & Employer::list_of_passing_practice() const { return m_list_of_passing_practice; }

Employer::ListOfResultEducation Employer::getlist_of_result_education() const { return m_list_of_result_education; }

Employer::ListOfResultEducation & Employer::list_of_result_education() { return m_list_of_result_education; }

const Employer::ListOfResultEducation & Employer::list_of_result_education() const { return m_list_of_result_education; }


Employer::ListOfTestPractice Employer::getlist_of_TestPractice() const { return m_list_of_TestPractice; }

Employer::ListOfTestPractice & Employer::list_of_TestPractice() { return m_list_of_TestPractice; }

const Employer::ListOfTestPractice & Employer::list_of_TestPractice() const { return m_list_of_TestPractice; }





void Employer::setEmployer_id(const long & val) { m_Employer_id = val; }

void Employer::setname(const QString & val) { m_name = val; }

void Employer::setlist_of_activity(const Employer::ListOfActivity & val) { m_list_of_activity = val; }

void Employer::setlist_of_collaboration(const Employer::ListOfCollaboration & val) { m_list_of_collaboration = val; }

void Employer::setlist_of_task(const Employer::ListOfTask & val) { m_list_of_task = val; }

void Employer::setlist_of_practice(const Employer::ListOfPractice & val) { m_list_of_practice = val; }

void Employer::setlist_of_head_employer(const Employer::ListOfHeadEmployer & val) { m_list_of_head_employer = val; }

void Employer::setlist_of_contact_employer(const Employer::ListOfContactEmployer & val) { m_list_of_contact_employer = val; }

void Employer::setlist_of_passing_practice(const Employer::ListOfPassingPractice & val) { m_list_of_passing_practice = val; }

void Employer::setlist_of_result_education(const Employer::ListOfResultEducation & val) { m_list_of_result_education = val; }

void Employer::setlist_of_TestPractice(const Employer::ListOfTestPractice & val) { m_list_of_TestPractice = val; }

Employer::ListOfEvents Employer::getlist_of_events() const { return m_list_of_events; }

Employer::ListOfEvents & Employer::list_of_events() { return m_list_of_events; }

const Employer::ListOfEvents & Employer::list_of_events() const { return m_list_of_events; }


Employer::ListOfActivity Employer::getlist_of_activity(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)

{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_activity(); }
   QString sRelation = "{Employer_id} | list_of_activity";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_activity = tmp.m_list_of_activity; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_activity;
}

Employer::ListOfActivity & Employer::list_of_activity(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_activity(); }
   QString sRelation = "{Employer_id} | list_of_activity";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_activity = tmp.m_list_of_activity; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_activity;
}

Employer::ListOfCollaboration Employer::getlist_of_collaboration(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_collaboration(); }
   QString sRelation = "{Employer_id} | list_of_collaboration";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_collaboration = tmp.m_list_of_collaboration; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_collaboration;
}

Employer::ListOfCollaboration & Employer::list_of_collaboration(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_collaboration(); }
   QString sRelation = "{Employer_id} | list_of_collaboration";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_collaboration = tmp.m_list_of_collaboration; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_collaboration;
}

Employer::ListOfTask Employer::getlist_of_task(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_task(); }
   QString sRelation = "{Employer_id} | list_of_task";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_task = tmp.m_list_of_task; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_task;
}

Employer::ListOfTask & Employer::list_of_task(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_task(); }
   QString sRelation = "{Employer_id} | list_of_task";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_task = tmp.m_list_of_task; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_task;
}

Employer::ListOfPractice Employer::getlist_of_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_practice(); }
   QString sRelation = "{Employer_id} | list_of_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_practice = tmp.m_list_of_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_practice;
}

Employer::ListOfPractice & Employer::list_of_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_practice(); }
   QString sRelation = "{Employer_id} | list_of_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_practice = tmp.m_list_of_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_practice;
}
Employer::ListOfEvents Employer::getlist_of_events(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_events(); }
   QString sRelation = "{Employer_id} | list_of_events";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_events = tmp.m_list_of_events; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_events;
}

Employer::ListOfEvents & Employer::list_of_events(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_events(); }
   QString sRelation = "{Employer_id} | list_of_events";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_events = tmp.m_list_of_events; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_events;
}
Employer::ListOfHeadEmployer Employer::getlist_of_head_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_head_employer(); }
   QString sRelation = "{Employer_id} | list_of_head_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_head_employer = tmp.m_list_of_head_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_head_employer;
}

Employer::ListOfHeadEmployer & Employer::list_of_head_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_head_employer(); }
   QString sRelation = "{Employer_id} | list_of_head_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_head_employer = tmp.m_list_of_head_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_head_employer;
}
Employer::ListOfContactEmployer Employer::getlist_of_contact_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_contact_employer(); }
   QString sRelation = "{Employer_id} | list_of_contact_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_contact_employer = tmp.m_list_of_contact_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_contact_employer;
}

Employer::ListOfContactEmployer & Employer::list_of_contact_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_contact_employer(); }
   QString sRelation = "{Employer_id} | list_of_contact_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_contact_employer = tmp.m_list_of_contact_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_contact_employer;
}

Employer::ListOfPassingPractice Employer::getlist_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_passing_practice(); }
   QString sRelation = "{Employer_id} | list_of_passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passing_practice = tmp.m_list_of_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passing_practice;
}

Employer::ListOfPassingPractice & Employer::list_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_passing_practice(); }
   QString sRelation = "{Employer_id} | list_of_passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passing_practice = tmp.m_list_of_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passing_practice;
}

Employer::ListOfResultEducation Employer::getlist_of_result_education(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_result_education(); }
   QString sRelation = "{Employer_id} | list_of_result_education";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_result_education = tmp.m_list_of_result_education; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_result_education;
}

Employer::ListOfResultEducation & Employer::list_of_result_education(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_result_education(); }
   QString sRelation = "{Employer_id} | list_of_result_education";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_result_education = tmp.m_list_of_result_education; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_result_education;
}

Employer::ListOfTestPractice Employer::getlist_of_TestPractice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_TestPractice(); }
   QString sRelation = "{Employer_id} | list_of_TestPractice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_TestPractice = tmp.m_list_of_TestPractice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_TestPractice;
}

Employer::ListOfTestPractice & Employer::list_of_TestPractice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_TestPractice(); }
   QString sRelation = "{Employer_id} | list_of_TestPractice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Employer tmp;
   tmp.m_Employer_id = this->m_Employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_TestPractice = tmp.m_list_of_TestPractice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_TestPractice;
}


