#ifndef _DEPARTMENT_HEAD_UNIVERSITY_H_
#define _DEPARTMENT_HEAD_UNIVERSITY_H_

class Person;
class Department;
class PassingPractice;
class Report;

class DEPARTMENT_EXPORT HeadUniversity
{

   QX_REGISTER_FRIEND_CLASS(HeadUniversity)

public:

   typedef std::shared_ptr<Person> Person_ptr;
   typedef std::shared_ptr<Department> Department_ptr;
   typedef qx::QxCollection<long, std::shared_ptr<PassingPractice> > ListOfPassingPractice;
   typedef qx::QxCollection<long, std::shared_ptr<Report> > ListOfReport;

protected:

   long m_Head_university_id;
   Person_ptr m_person;
   Department_ptr m_department;
   ListOfPassingPractice m_list_of_passing_practice;
   ListOfReport m_list_of_Reports;

public:

   HeadUniversity();
   HeadUniversity(const long & id);
   virtual ~HeadUniversity();

   long getHeadUniversity_id() const;
   Person_ptr getperson() const;
   Department_ptr getdepartment() const;
   ListOfPassingPractice getlist_of_passing_practice() const;
   ListOfPassingPractice & list_of_passing_practice();
   const ListOfPassingPractice & list_of_passing_practice() const;
   ListOfReport getlist_of_Reports() const;
   ListOfReport & list_of_Reports();
   const ListOfReport & list_of_Reports() const;

   void setHeadUniversity_id(const long & val);
   void setperson(const Person_ptr & val);
   void setdepartment(const Department_ptr & val);
   void setlist_of_passing_practice(const ListOfPassingPractice & val);
   void setlist_of_Reports(const ListOfReport & val);

   ListOfPassingPractice getlist_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPassingPractice & list_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Person_ptr getperson(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Department_ptr getdepartment(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfReport getlist_of_Reports(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfReport & list_of_Reports(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);



public:

   static QString relation_person(bool key = false) { return (key ? QString("person") : QString("person_id")); }
   static QString relation_department(bool key = false) { return (key ? QString("department") : QString("department_id")); }
   static QString relation_list_of_passing_practice(bool key = false) { Q_UNUSED(key); return "list_of_passing_practice"; }
   static QString relation_list_of_Reports(bool key = false) { Q_UNUSED(key); return "list_of_Reports"; }


public:

   static QString column_Head_university_id(bool key = false) { Q_UNUSED(key); return "Head_university_id"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Head_university") : QString("t_Head_university")); }

};

typedef std::shared_ptr<HeadUniversity> HeadUniversity_ptr;
typedef qx::QxCollection<long, HeadUniversity_ptr> ListOfHeadUniversity;
typedef std::shared_ptr<ListOfHeadUniversity> ListOfHeadUniversity_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(HeadUniversity, qx::trait::no_base_class_defined, 0, HeadUniversity)

#include "../include/Passing_practice.h"
#include "../include/Person.h"
#include "../include/Department.h"
#include "../include/Report.h"


#endif // _DEPARTMENT_HEAD_UNIVERSITY_H_
