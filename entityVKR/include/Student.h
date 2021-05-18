#ifndef _DEPARTMENT_STUDENT_H_
#define _DEPARTMENT_STUDENT_H_

class Group;
class Person;
class PassingPractice;
class EducationalProgram;
class Report;
class PracticeResult;

class DEPARTMENT_EXPORT Student
{

   QX_REGISTER_FRIEND_CLASS(Student)

public:

   typedef std::shared_ptr<Group> Group_ptr;
   typedef std::shared_ptr<Person> Person_ptr;
   typedef qx::QxCollection<long, std::shared_ptr<PassingPractice> > ListOfPassingPractice;
   typedef std::shared_ptr<EducationalProgram> EducationProgram_ptr;
   typedef qx::QxCollection<long, std::shared_ptr<Report> > ListOfReport;
   typedef qx::QxCollection<long, std::shared_ptr<PracticeResult> > ListOfPracticeResult;




protected:

   long m_Strudent_id;
   Group_ptr m_group;
   Person_ptr m_person;
   ListOfPassingPractice m_list_of_passing_practice;
   EducationProgram_ptr m_education_program;
   ListOfReport m_list_of_reports;
   ListOfPracticeResult m_list_of_practice_result;



public:

   Student();
   Student(const long & id);
   virtual ~Student();

   long getstudent_id() const;
   Group_ptr getgroup() const;
   Person_ptr getperson() const;
   ListOfPassingPractice getlist_of_passing_practice() const;
   ListOfPassingPractice & list_of_passing_practice();
   const ListOfPassingPractice & list_of_passing_practice() const;
   EducationProgram_ptr geteducation_program() const;
   ListOfReport getlist_of_reports() const;
   ListOfReport & list_of_reports();
   const ListOfReport & list_of_reports() const;
   ListOfPracticeResult getlist_of_practice_result() const;
   ListOfPracticeResult & list_of_practice_result();
   const ListOfPracticeResult & list_of_practice_result() const;


   void setstudent_id(const long & val);
   void setgroup(const Group_ptr & val);
   void setperson(const Person_ptr & val);
   void setlist_of_passing_practice(const ListOfPassingPractice & val);
   void seteducation_program(const EducationProgram_ptr & val);
   void setlist_of_reports(const ListOfReport & val);
   void setlist_of_practice_result(const ListOfPracticeResult & val);


   ListOfPassingPractice getlist_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPassingPractice & list_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Group_ptr getgroup(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Person_ptr getperson(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   EducationProgram_ptr getEducation_program(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfReport getlist_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfReport & list_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPracticeResult getlist_of_practice_result(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPracticeResult & list_of_practice_result(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);



public:

   static QString relation_group(bool key = false) { return (key ? QString("group") : QString("group_id")); }
   static QString relation_person(bool key = false) { Q_UNUSED(key); return "person"; }
   static QString relation_list_of_passing_practice(bool key = false) { Q_UNUSED(key); return "list_of_passing_practice"; }
   static QString relation_education_program(bool key = false) { Q_UNUSED(key); return "Education_program"; }
   static QString relation_list_of_reports(bool key = false) { Q_UNUSED(key); return "list_of_reports"; }
   static QString relation_list_of_practice_result(bool key = false) { Q_UNUSED(key); return "list_of_practice_result"; }



public:

   static QString column_Strudent_id(bool key = false) { Q_UNUSED(key); return "Strudent_id"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Student") : QString("t_Student")); }

};

typedef std::shared_ptr<Student> Student_ptr;
typedef qx::QxCollection<long, Student_ptr> ListOfStudent;
typedef std::shared_ptr<ListOfStudent> ListOfStudent_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Student, qx::trait::no_base_class_defined, 0, Student)
#include "../include/Report.h"
#include "../include/Practice_result.h"
#include "../include/Educational_program.h"
#include "../include/Passing_practice.h"
#include "../include/Group.h"
#include "../include/Person.h"



#endif // _DEPARTMENT_STUDENT_H_
