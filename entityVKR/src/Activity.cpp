/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/03/24 12:12) : please, do NOT modify this file ! **
************************************************************************************************/

#include "../include/department_precompiled_header.h"

#include "../include/Activity.h"
#include "../include/Employer.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Activity, Activity)

namespace qx {

template <>
void register_class(QxClass<Activity> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Activity");

   pData = t.id(& Activity::m_Activity_id, "Activity_id", 0);

   pData = t.data(& Activity::m_name, "name", 0, true, true);
   pData = t.data(& Activity::m_description, "description", 0, true, true);

   pRelation = t.relationManyToMany(& Activity::m_list_of_employers, "list_of_employers", "t_qxee_Activity_Employer", "Activity_id", "Employer_id", 0);

   qx::QxValidatorX<Activity> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Activity::Activity() : m_Activity_id(0) { ; }

Activity::Activity(const long & id) : m_Activity_id(id) { ; }

Activity::~Activity() { ; }

long Activity::getactivity_id() const { return m_Activity_id; }

QString Activity::getname() const { return m_name; }

QString Activity::getdescription() const { return m_description; }

Activity::ListOfEmployers Activity::getlist_of_employers() const { return m_list_of_employers; }

Activity::ListOfEmployers & Activity::list_of_employers() { return m_list_of_employers; }

const Activity::ListOfEmployers & Activity::list_of_employers() const { return m_list_of_employers; }

void Activity::setactivity_id(const long & val) { m_Activity_id = val; }

void Activity::setname(const QString & val) { m_name = val; }

void Activity::setdescription(const QString & val) { m_description = val; }

void Activity::setlist_of_employers(const Activity::ListOfEmployers & val) { m_list_of_employers = val; }

Activity::ListOfEmployers Activity::getlist_of_employers(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_employers(); }
   QString sRelation = "{Activity_id} | list_of_employers";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Activity tmp;
   tmp.m_Activity_id = this->m_Activity_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_employers = tmp.m_list_of_employers; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_employers;
}

Activity::ListOfEmployers & Activity::list_of_employers(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_employers(); }
   QString sRelation = "{Activity_id} | list_of_employers";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Activity tmp;
   tmp.m_Activity_id = this->m_Activity_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_employers = tmp.m_list_of_employers; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_employers;
}

