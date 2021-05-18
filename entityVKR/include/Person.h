#ifndef _DEPARTMENT_PERSON_H_
#define _DEPARTMENT_PERSON_H_

class Student;
class HeadEmployer;
class ContactEmployer;
class HeadUniversity;


class DEPARTMENT_EXPORT Person
{

   QX_REGISTER_FRIEND_CLASS(Person)

public:

   typedef qx::QxCollection<long, std::shared_ptr<Student> > ListOfStudents;
   typedef qx::QxCollection<long, std::shared_ptr<HeadEmployer> > ListOfHeadEmployer;
   typedef qx::QxCollection<long, std::shared_ptr<ContactEmployer> > ListOfContactEmployer;
   typedef qx::QxCollection<long, std::shared_ptr<HeadUniversity> > ListOfHeadUniversity;


protected:

   long m_Person;
   QString m_firstname;
   QString m_lastname;
   QString m_patronymic;
   QString m_phone_number;
   QString m_email;
   ListOfStudents m_list_of_students;
   ListOfHeadEmployer m_list_of_head_employer;
   ListOfContactEmployer m_list_of_contact_employer;
   ListOfHeadUniversity m_list_of_head_university;


public:

   Person();
   Person(const long & id);
   virtual ~Person();

   long getperson_id() const;
   QString getfirstname() const;
   QString getlastname() const;
   QString getpatronymic() const;
   QString getphone_number() const;
   QString getemail() const;
   ListOfStudents getlist_of_students() const;
   ListOfStudents & list_of_students();
   const ListOfStudents & list_of_students() const;
   ListOfHeadEmployer getlist_of_head_employer() const;
   ListOfHeadEmployer & list_of_head_employer();
   const ListOfHeadEmployer & list_of_head_employer() const;
   ListOfContactEmployer getlist_of_contact_employer() const;
   ListOfContactEmployer & list_of_contact_employer();
   const ListOfContactEmployer & list_of_contact_employer() const;
   ListOfHeadUniversity getlist_of_head_university() const;
   ListOfHeadUniversity & list_of_head_university();
   const ListOfHeadUniversity & list_of_head_university() const;


   void setperson_id(const long & val);
   void setfirstname(const QString & val);
   void setlastname(const QString & val);
   void setpatronymic(const QString & val);
   void setphone_number(const QString & val);
   void setemail(const QString & val);
   void setlist_of_students(const ListOfStudents & val);
   void setlist_of_head_employer(const ListOfHeadEmployer & val);
   void setlist_of_contact_employer(const ListOfContactEmployer & val);
   void setlist_of_head_university(const ListOfHeadUniversity & val);

   ListOfStudents getlist_of_students(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfStudents & list_of_students(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfHeadEmployer getlist_of_head_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfHeadEmployer & list_of_head_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfContactEmployer getlist_of_contact_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfContactEmployer & list_of_contact_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfHeadUniversity getlist_of_head_university(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfHeadUniversity & list_of_head_university(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);



public:

   static QString relation_list_of_students(bool key = false) { Q_UNUSED(key); return "list_of_students"; }
   static QString relation_list_of_head_employer(bool key = false) { Q_UNUSED(key); return "list_of_head_employer"; }
   static QString relation_list_of_contact_employer(bool key = false) { Q_UNUSED(key); return "list_of_contact_employer"; }
   static QString relation_list_of_head_university(bool key = false) { Q_UNUSED(key); return "list_of_head_university"; }


public:

   static QString column_Person(bool key = false) { Q_UNUSED(key); return "Person_id"; }
   static QString column_fistname(bool key = false) { Q_UNUSED(key); return "fistname"; }
   static QString column_lastname(bool key = false) { Q_UNUSED(key); return "lastname"; }
   static QString column_patronymic(bool key = false) { Q_UNUSED(key); return "patronymic"; }
   static QString column_phone_number(bool key = false) { Q_UNUSED(key); return "phone_number"; }
   static QString column_email(bool key = false) { Q_UNUSED(key); return "email"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Person") : QString("t_Person")); }

};

typedef std::shared_ptr<Person> Person_ptr;
typedef qx::QxCollection<long, Person_ptr> ListOfPerson;
typedef std::shared_ptr<ListOfPerson> ListOfPerson_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Person, qx::trait::no_base_class_defined, 0, Person)
#include "../include/Head_university.h"
#include "../include/Contact_employer.h"
#include "../include/Student.h"
#include "../include/Head_employer.h"
#endif // _DEPARTMENT_PERSON_H_


