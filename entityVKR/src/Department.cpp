#include "../include/department_precompiled_header.h"

#include "../include/Department.h"
#include "../include/Head_university.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Department, Department)

namespace qx {

template <>
void register_class(QxClass<Department> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_department");

   pData = t.id(& Department::m_Department_id, "Department_id", 0);

   pData = t.data(& Department::m_name, "name", 0, true, true);

   pRelation = t.relationOneToMany(& Department::m_list_of_head_university, "list_of_head_university", "department_id", 0);

   qx::QxValidatorX<Department> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Department::Department() : m_Department_id(0) { ; }

Department::Department(const long & id) : m_Department_id(id) { ; }

Department::~Department() { ; }

long Department::getdepartment_id() const { return m_Department_id; }

QString Department::getname() const { return m_name; }

Department::ListOfHeadUniversity Department::getlist_of_head_university() const { return m_list_of_head_university; }

Department::ListOfHeadUniversity & Department::list_of_head_university() { return m_list_of_head_university; }

const Department::ListOfHeadUniversity & Department::list_of_head_university() const { return m_list_of_head_university; }

void Department::setdepartment_id(const long & val) { m_Department_id = val; }

void Department::setname(const QString & val) { m_name = val; }

void Department::setlist_of_head_university(const Department::ListOfHeadUniversity & val) { m_list_of_head_university = val; }

Department::ListOfHeadUniversity Department::getlist_of_head_university(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_head_university(); }
   QString sRelation = "{Department_id} | list_of_head_university";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Department tmp;
   tmp.m_Department_id = this->m_Department_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_head_university = tmp.m_list_of_head_university; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_head_university;
}

Department::ListOfHeadUniversity & Department::list_of_head_university(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_head_university(); }
   QString sRelation = "{Department_id} | list_of_head_university";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Department tmp;
   tmp.m_Department_id = this->m_Department_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_head_university = tmp.m_list_of_head_university; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_head_university;
}
