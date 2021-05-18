#include "../include/department_precompiled_header.h"

#include "../include/Person.h"
#include "../include/Student.h"
#include "../include/Head_employer.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Person, Person)

namespace qx {

template <>
void register_class(QxClass<Person> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Person");

   pData = t.id(& Person::m_Person, "Person_id", 0);

   pData = t.data(& Person::m_firstname, "fistname", 0, true, true);
   pData = t.data(& Person::m_lastname, "lastname", 0, true, true);
   pData = t.data(& Person::m_patronymic, "patronymic", 0, true, true);
   pData = t.data(& Person::m_phone_number, "phone_number", 0, true, true);
   pData = t.data(& Person::m_email, "email", 0, true, true);

   pRelation = t.relationOneToMany(& Person::m_list_of_students, "list_of_students", "person_id", 0);
   pRelation = t.relationOneToMany(& Person::m_list_of_head_employer, "list_of_head_employer", "person_id", 0);
   pRelation = t.relationOneToMany(& Person::m_list_of_head_university, "list_of_head_university", "person", 0);
   pRelation = t.relationOneToMany(& Person::m_list_of_contact_employer, "list_of_contact_employer", "person", 0);

   qx::QxValidatorX<Person> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Person::Person() : m_Person(0) { ; }

Person::Person(const long & id) : m_Person(id) { ; }

Person::~Person() { ; }

long Person::getperson_id() const { return m_Person; }

QString Person::getfirstname() const { return m_firstname; }

QString Person::getlastname() const { return m_lastname; }

QString Person::getpatronymic() const { return m_patronymic; }

QString Person::getphone_number() const { return m_phone_number; }

QString Person::getemail() const { return m_email; }

Person::ListOfStudents Person::getlist_of_students() const { return m_list_of_students; }

Person::ListOfStudents & Person::list_of_students() { return m_list_of_students; }

const Person::ListOfStudents & Person::list_of_students() const { return m_list_of_students; }

Person::ListOfHeadEmployer Person::getlist_of_head_employer() const { return m_list_of_head_employer; }

Person::ListOfHeadEmployer & Person::list_of_head_employer() { return m_list_of_head_employer; }

const Person::ListOfHeadEmployer & Person::list_of_head_employer() const { return m_list_of_head_employer; }

Person::ListOfContactEmployer Person::getlist_of_contact_employer() const { return m_list_of_contact_employer; }

Person::ListOfContactEmployer & Person::list_of_contact_employer() { return m_list_of_contact_employer; }

const Person::ListOfContactEmployer & Person::list_of_contact_employer() const { return m_list_of_contact_employer; }

Person::ListOfHeadUniversity Person::getlist_of_head_university() const { return m_list_of_head_university; }

Person::ListOfHeadUniversity & Person::list_of_head_university() { return m_list_of_head_university; }

const Person::ListOfHeadUniversity & Person::list_of_head_university() const { return m_list_of_head_university; }

void Person::setperson_id(const long & val) { m_Person = val; }

void Person::setfirstname(const QString & val) { m_firstname = val; }

void Person::setlastname(const QString & val) { m_lastname = val; }

void Person::setpatronymic(const QString & val) { m_patronymic = val; }

void Person::setphone_number(const QString & val) { m_phone_number = val; }

void Person::setemail(const QString & val) { m_email = val; }

void Person::setlist_of_students(const Person::ListOfStudents & val) { m_list_of_students = val; }

void Person::setlist_of_head_employer(const Person::ListOfHeadEmployer & val) { m_list_of_head_employer = val; }

void Person::setlist_of_contact_employer(const Person::ListOfContactEmployer & val) { m_list_of_contact_employer = val; }

void Person::setlist_of_head_university(const Person::ListOfHeadUniversity & val) { m_list_of_head_university = val; }


Person::ListOfStudents Person::getlist_of_students(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_students(); }
   QString sRelation = "{Person_id} | list_of_students";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Person tmp;
   tmp.m_Person = this->m_Person;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_students = tmp.m_list_of_students; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_students;
}

Person::ListOfStudents & Person::list_of_students(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_students(); }
   QString sRelation = "{Person_id} | list_of_students";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Person tmp;
   tmp.m_Person = this->m_Person;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_students = tmp.m_list_of_students; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_students;
}

Person::ListOfHeadEmployer Person::getlist_of_head_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_head_employer(); }
   QString sRelation = "{Person_id} | list_of_head_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Person tmp;
   tmp.m_Person = this->m_Person;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_head_employer = tmp.m_list_of_head_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_head_employer;
}

Person::ListOfHeadEmployer & Person::list_of_head_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_head_employer(); }
   QString sRelation = "{Person_id} | list_of_head_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Person tmp;
   tmp.m_Person = this->m_Person;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_head_employer = tmp.m_list_of_head_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_head_employer;
}
Person::ListOfContactEmployer Person::getlist_of_contact_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_contact_employer(); }
   QString sRelation = "{Person_id} | list_of_contact_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Person tmp;
   tmp.m_Person = this->m_Person;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_contact_employer = tmp.m_list_of_contact_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_contact_employer;
}

Person::ListOfContactEmployer & Person::list_of_contact_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_contact_employer(); }
   QString sRelation = "{Person_id} | list_of_contact_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Person tmp;
   tmp.m_Person = this->m_Person;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_contact_employer = tmp.m_list_of_contact_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_contact_employer;
}
Person::ListOfHeadUniversity Person::getlist_of_head_university(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_head_university(); }
   QString sRelation = "{Person_id} | list_of_head_university";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Person tmp;
   tmp.m_Person = this->m_Person;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_head_university = tmp.m_list_of_head_university; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_head_university;
}

Person::ListOfHeadUniversity & Person::list_of_head_university(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_head_university(); }
   QString sRelation = "{Person_id} | list_of_head_university";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Person tmp;
   tmp.m_Person = this->m_Person;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_head_university = tmp.m_list_of_head_university; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_head_university;
}
