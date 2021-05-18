#ifndef _DEPARTMENT_CONTACT_EMPLOYER_H_
#define _DEPARTMENT_CONTACT_EMPLOYER_H_

class Employer;
class Person;

class DEPARTMENT_EXPORT ContactEmployer
{

   QX_REGISTER_FRIEND_CLASS(ContactEmployer)

public:

   typedef std::shared_ptr<Employer> Employer_ptr;
   typedef std::shared_ptr<Person> Personr_ptr;

protected:

   long m_Contact_employer_id;
   Employer_ptr m_employer;
   Personr_ptr m_person;

public:

   ContactEmployer();
   ContactEmployer(const long & id);
   virtual ~ContactEmployer();

   long getcontact_employer_id() const;
   Employer_ptr getemployer() const;
   Personr_ptr getperson() const;

   void setcontact_employer_id(const long & val);
   void setemployer(const Employer_ptr & val);
   void setperson(const Personr_ptr & val);

   Employer_ptr getemployer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Personr_ptr getperson(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_employer(bool key = false) { return (key ? QString("employer") : QString("employer_id")); }
   static QString relation_person(bool key = false) { return (key ? QString("person") : QString("persone_id")); }

public:

   static QString column_Contact_employer_id(bool key = false) { Q_UNUSED(key); return "Contact_employer_id"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Contact_employer") : QString("t_Contact_employer")); }

};

typedef std::shared_ptr<ContactEmployer> ContactEmployer_ptr;
typedef qx::QxCollection<long, ContactEmployer_ptr> ListOfContactEmployer;
typedef std::shared_ptr<ListOfContactEmployer> ListOfContactEmployer_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(ContactEmployer, qx::trait::no_base_class_defined, 0, ContactEmployer)

#include "../include/Employer.h"
#include "../include/Person.h"



#endif // _DEPARTMENT_CONTACT_EMPLOYER_H_
