#include "../include/department_precompiled_header.h"

#include "../include/Group.h"
#include "../include/Student.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Group, Group)

namespace qx {

template <>
void register_class(QxClass<Group> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Group");

   pData = t.id(& Group::m_Groups_id, "Group_id", 0);

   pData = t.data(& Group::m_number, "number", 0, true, true);

   pRelation = t.relationOneToMany(& Group::m_list_of_student, "list_of_student", "group", 0);

   qx::QxValidatorX<Group> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Group::Group() : m_Groups_id(0) { ; }

Group::Group(const long & id) : m_Groups_id(id) { ; }

Group::~Group() { ; }

long Group::getgroup_id() const { return m_Groups_id; }

QString Group::getnumber() const { return m_number; }

Group::ListOfStudent Group::getlist_of_student() const { return m_list_of_student; }

Group::ListOfStudent & Group::list_of_student() { return m_list_of_student; }

const Group::ListOfStudent & Group::list_of_student() const { return m_list_of_student; }

void Group::setgroup_id(const long & val) { m_Groups_id = val; }

void Group::setnumber(const QString & val) { m_number = val; }

void Group::setlist_of_student(const Group::ListOfStudent & val) { m_list_of_student = val; }

Group::ListOfStudent Group::getlist_of_student(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_student(); }
   QString sRelation = "{Groups_id} | list_of_student";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Group tmp;
   tmp.m_Groups_id = this->m_Groups_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_student = tmp.m_list_of_student; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_student;
}

Group::ListOfStudent & Group::list_of_student(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_student(); }
   QString sRelation = "{Groups_id} | list_of_student";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Group tmp;
   tmp.m_Groups_id = this->m_Groups_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_student = tmp.m_list_of_student; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_student;
}
