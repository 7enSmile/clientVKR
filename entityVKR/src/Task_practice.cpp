#include "../include/department_precompiled_header.h"

#include "../include/Task_practice.h"
#include "../include/Passing_practice.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(TaskPractice, TaskPractice)

namespace qx {

template <>
void register_class(QxClass<TaskPractice> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Task_practice");

   pData = t.id(& TaskPractice::m_Task_id, "Task_id", 0);

   pData = t.data(& TaskPractice::m_description, "description", 0, true, true);

   pData = t.data(& TaskPractice::m_name, "name", 0, true, true);

   pRelation = t.relationOneToMany(& TaskPractice::m_list_of_passeing_practice, "list_of_passeing_practice", "task", 0);

   qx::QxValidatorX<TaskPractice> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

TaskPractice::TaskPractice() : m_Task_id(0) { ; }

TaskPractice::TaskPractice(const long & id) : m_Task_id(id) { ; }

TaskPractice::~TaskPractice() { ; }

long TaskPractice::getTask_id() const { return m_Task_id; }

QString TaskPractice::getdescription() const { return m_description; }

QString TaskPractice::getname() const { return m_name; }

TaskPractice::ListOfPassingPractice TaskPractice::getlist_of_passeing_practice() const { return m_list_of_passeing_practice; }

TaskPractice::ListOfPassingPractice & TaskPractice::list_of_passeing_practice() { return m_list_of_passeing_practice; }

const TaskPractice::ListOfPassingPractice & TaskPractice::list_of_passeing_practice() const { return m_list_of_passeing_practice; }

void TaskPractice::setTask_id(const long & val) { m_Task_id = val; }

void TaskPractice::setdescription(const QString & val) { m_description = val; }

void TaskPractice::setname(const QString & val) { m_name = val; }

void TaskPractice::setlist_of_passeing_practice(const TaskPractice::ListOfPassingPractice & val) { m_list_of_passeing_practice = val; }

TaskPractice::ListOfPassingPractice TaskPractice::getlist_of_passeing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_passeing_practice(); }
   QString sRelation = "{Task_id} | list_of_passeing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   TaskPractice tmp;
   tmp.m_Task_id = this->m_Task_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passeing_practice = tmp.m_list_of_passeing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passeing_practice;
}

TaskPractice::ListOfPassingPractice & TaskPractice::list_of_passeing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_passeing_practice(); }
   QString sRelation = "{Task_id} | list_of_passeing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   TaskPractice tmp;
   tmp.m_Task_id = this->m_Task_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passeing_practice = tmp.m_list_of_passeing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passeing_practice;
}
