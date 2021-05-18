#include "../include/department_precompiled_header.h"

#include "../include/Head_university.h"
#include "../include/Person.h"
#include "../include/Department.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(HeadUniversity, HeadUniversity)

namespace qx {

template <>
void register_class(QxClass<HeadUniversity> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Head_university");

   pData = t.id(& HeadUniversity::m_Head_university_id, "Head_university_id", 0);

   pRelation = t.relationManyToOne(& HeadUniversity::m_person, "person", 0);
   pRelation->getDataMember()->setName("person_id");
   pRelation = t.relationManyToOne(& HeadUniversity::m_department, "department_id", 0);
   pRelation->getDataMember()->setName("department_id");
   pRelation = t.relationOneToMany(& HeadUniversity::m_list_of_passing_practice, "list_of_passing_practice", "head_university_id", 0);
   pRelation = t.relationOneToMany(& HeadUniversity::m_list_of_Reports, "list_of_Reports", "Head_university_id", 0);

   qx::QxValidatorX<HeadUniversity> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

HeadUniversity::HeadUniversity() : m_Head_university_id(0) { ; }

HeadUniversity::HeadUniversity(const long & id) : m_Head_university_id(id) { ; }

HeadUniversity::~HeadUniversity() { ; }

long HeadUniversity::getHeadUniversity_id() const { return m_Head_university_id; }

HeadUniversity::Person_ptr HeadUniversity::getperson() const { return m_person; }

HeadUniversity::Department_ptr HeadUniversity::getdepartment() const { return m_department; }

HeadUniversity::ListOfPassingPractice HeadUniversity::getlist_of_passing_practice() const { return m_list_of_passing_practice; }

HeadUniversity::ListOfPassingPractice & HeadUniversity::list_of_passing_practice() { return m_list_of_passing_practice; }

const HeadUniversity::ListOfPassingPractice & HeadUniversity::list_of_passing_practice() const { return m_list_of_passing_practice; }

HeadUniversity::ListOfReport HeadUniversity::getlist_of_Reports() const { return m_list_of_Reports; }

HeadUniversity::ListOfReport & HeadUniversity::list_of_Reports() { return m_list_of_Reports; }

const HeadUniversity::ListOfReport & HeadUniversity::list_of_Reports() const { return m_list_of_Reports; }


void HeadUniversity::setHeadUniversity_id(const long & val) { m_Head_university_id = val; }

void HeadUniversity::setperson(const HeadUniversity::Person_ptr & val) { m_person = val; }

void HeadUniversity::setdepartment(const HeadUniversity::Department_ptr & val) { m_department = val; }

void HeadUniversity::setlist_of_passing_practice(const HeadUniversity::ListOfPassingPractice & val) { m_list_of_passing_practice = val; }

void HeadUniversity::setlist_of_Reports(const HeadUniversity::ListOfReport & val) { m_list_of_Reports = val; }

HeadUniversity::Person_ptr HeadUniversity::getperson(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getperson(); }
   QString sRelation = "{HeadUniversity_id} | person";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadUniversity tmp;
   tmp.m_Head_university_id = this->m_Head_university_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_person = tmp.m_person; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_person;
}

HeadUniversity::Department_ptr HeadUniversity::getdepartment(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getdepartment(); }
   QString sRelation = "{HeadUniversity_id} | department";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadUniversity tmp;
   tmp.m_Head_university_id = this->m_Head_university_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_department = tmp.m_department; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_department;
}
HeadUniversity::ListOfPassingPractice HeadUniversity::getlist_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_passing_practice(); }
   QString sRelation = "{HeadUniversity_id} | list_of_passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadUniversity tmp;
   tmp.m_Head_university_id = this->m_Head_university_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passing_practice = tmp.m_list_of_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passing_practice;
}

HeadUniversity::ListOfPassingPractice & HeadUniversity::list_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_passing_practice(); }
   QString sRelation = "{HeadUniversity_id} | list_of_passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadUniversity tmp;
   tmp.m_Head_university_id = this->m_Head_university_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passing_practice = tmp.m_list_of_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passing_practice;
}

HeadUniversity::ListOfReport HeadUniversity::getlist_of_Reports(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_Reports(); }
   QString sRelation = "{HeadUniversity_id} | list_of_Reports";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadUniversity tmp;
   tmp.m_Head_university_id = this->m_Head_university_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_Reports = tmp.m_list_of_Reports; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_Reports;
}

HeadUniversity::ListOfReport & HeadUniversity::list_of_Reports(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_Reports(); }
   QString sRelation = "{HeadUniversity_id} | list_of_Reports";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   HeadUniversity tmp;
   tmp.m_Head_university_id = this->m_Head_university_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_Reports = tmp.m_list_of_Reports; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_Reports;
}
