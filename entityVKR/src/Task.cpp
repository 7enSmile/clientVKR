/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/03/24 12:12) : please, do NOT modify this file ! **
************************************************************************************************/

#include "../include/department_precompiled_header.h"

#include "../include/Task.h"
#include "../include/Employer.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Task, Task)

namespace qx {

template <>
void register_class(QxClass<Task> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Task");

   pData = t.id(& Task::m_Task_id, "Task_id", 0);

   pData = t.data(& Task::m_name, "name", 0, true, true);
   pData = t.data(& Task::m_description, "description", 0, true, true);

   pRelation = t.relationManyToMany(& Task::m_list_of_employers, "list_of_employers", "t_qxee_Task_Employer", "Task_id", "Employer_id", 0);

   qx::QxValidatorX<Task> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Task::Task() : m_Task_id(0) { ; }

Task::Task(const long & id) : m_Task_id(id) { ; }

Task::~Task() { ; }

long Task::getTask_id() const { return m_Task_id; }

QString Task::getname() const { return m_name; }

QString Task::getdescription() const { return m_description; }

Task::ListOfEmployer Task::getlist_of_employers() const { return m_list_of_employers; }

Task::ListOfEmployer & Task::list_of_employers() { return m_list_of_employers; }

const Task::ListOfEmployer & Task::list_of_employers() const { return m_list_of_employers; }

void Task::setTask_id(const long & val) { m_Task_id = val; }

void Task::setname(const QString & val) { m_name = val; }

void Task::setdescription(const QString & val) { m_description = val; }

void Task::setlist_of_employers(const Task::ListOfEmployer & val) { m_list_of_employers = val; }

Task::ListOfEmployer Task::getlist_of_employers(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_employers(); }
   QString sRelation = "{Task_id} | list_of_employers";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Task tmp;
   tmp.m_Task_id = this->m_Task_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_employers = tmp.m_list_of_employers; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_employers;
}

Task::ListOfEmployer & Task::list_of_employers(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_employers(); }
   QString sRelation = "{Task_id} | list_of_employers";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Task tmp;
   tmp.m_Task_id = this->m_Task_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_employers = tmp.m_list_of_employers; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_employers;
}

