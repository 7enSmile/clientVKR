#include "../include/department_precompiled_header.h"

#include "../include/Contact_employer.h"
#include "../include/Employer.h"
#include "../include/Person.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(ContactEmployer, ContactEmployer)

namespace qx {

template <>
void register_class(QxClass<ContactEmployer> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Contact_employer");

   pData = t.id(& ContactEmployer::m_Contact_employer_id, "Contact_employer_id", 0);

   pRelation = t.relationManyToOne(& ContactEmployer::m_employer, "employer", 0);
   pRelation->getDataMember()->setName("employer_id");
   pRelation = t.relationManyToOne(& ContactEmployer::m_person, "person", 0);
   pRelation->getDataMember()->setName("person_id");

   qx::QxValidatorX<ContactEmployer> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

ContactEmployer::ContactEmployer() : m_Contact_employer_id(0) { ; }

ContactEmployer::ContactEmployer(const long & id) : m_Contact_employer_id(id) { ; }

ContactEmployer::~ContactEmployer() { ; }

long ContactEmployer::getcontact_employer_id() const { return m_Contact_employer_id; }

ContactEmployer::Employer_ptr ContactEmployer::getemployer() const { return m_employer; }

ContactEmployer::Personr_ptr ContactEmployer::getperson() const { return m_person; }

void ContactEmployer::setcontact_employer_id(const long & val) { m_Contact_employer_id = val; }

void ContactEmployer::setemployer(const ContactEmployer::Employer_ptr & val) { m_employer = val; }

void ContactEmployer::setperson(const ContactEmployer::Personr_ptr & val) { m_person = val; }

ContactEmployer::Employer_ptr ContactEmployer::getemployer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getemployer(); }
   QString sRelation = "{ContactEmployer_id} | employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   ContactEmployer tmp;
   tmp.m_Contact_employer_id = this->m_Contact_employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_employer = tmp.m_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_employer;
}

ContactEmployer::Personr_ptr ContactEmployer::getperson(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getperson(); }
   QString sRelation = "{ContactEmployer_id} | person";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   ContactEmployer tmp;
   tmp.m_Contact_employer_id = this->m_Contact_employer_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_person = tmp.m_person; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_person;
}
