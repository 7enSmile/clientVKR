/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/03/24 12:12) : please, do NOT modify this file ! **
************************************************************************************************/

#include "../include/department_precompiled_header.h"

#include "../include/Collaboration.h"
#include "../include/Employer.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Collaboration, Collaboration)

namespace qx {

template <>
void register_class(QxClass<Collaboration> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Collaboration");

   pData = t.id(& Collaboration::m_Collaboration_id, "Collaboration_id", 0);

   pData = t.data(& Collaboration::m_name, "name", 0, true, true);
   pData = t.data(& Collaboration::m_description, "description", 0, true, true);

   pRelation = t.relationManyToMany(& Collaboration::m_list_of_employers, "list_of_employers", "t_qxee_Collaboration_Employer", "Collaboration_id", "Employer_id", 0);

   qx::QxValidatorX<Collaboration> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Collaboration::Collaboration() : m_Collaboration_id(0) { ; }

Collaboration::Collaboration(const long & id) : m_Collaboration_id(id) { ; }

Collaboration::~Collaboration() { ; }

long Collaboration::getcollaboration_id() const { return m_Collaboration_id; }

QString Collaboration::getname() const { return m_name; }

QString Collaboration::getdescription() const { return m_description; }

Collaboration::ListOfEmployers Collaboration::getlist_of_employers() const { return m_list_of_employers; }

Collaboration::ListOfEmployers & Collaboration::list_of_employers() { return m_list_of_employers; }

const Collaboration::ListOfEmployers & Collaboration::list_of_employers() const { return m_list_of_employers; }

void Collaboration::setcollaboration_id(const long & val) { m_Collaboration_id = val; }

void Collaboration::setname(const QString & val) { m_name = val; }

void Collaboration::setdescription(const QString & val) { m_description = val; }

void Collaboration::setlist_of_employers(const Collaboration::ListOfEmployers & val) { m_list_of_employers = val; }

Collaboration::ListOfEmployers Collaboration::getlist_of_employers(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_employers(); }
   QString sRelation = "{Collaboration_id} | list_of_employers";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Collaboration tmp;
   tmp.m_Collaboration_id = this->m_Collaboration_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_employers = tmp.m_list_of_employers; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_employers;
}

Collaboration::ListOfEmployers & Collaboration::list_of_employers(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_employers(); }
   QString sRelation = "{Collaboration_id} | list_of_employers";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Collaboration tmp;
   tmp.m_Collaboration_id = this->m_Collaboration_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_employers = tmp.m_list_of_employers; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_employers;
}

