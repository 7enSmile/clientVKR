#ifndef _DEPARTMENT_PRACTICE_RESULT_H_
#define _DEPARTMENT_PRACTICE_RESULT_H_

class Report;
class PassingPractice;
class Student;

class DEPARTMENT_EXPORT PracticeResult
{

   QX_REGISTER_FRIEND_CLASS(PracticeResult)

public:

   typedef qx::QxCollection<long, std::shared_ptr<Report> > ListOfReport;
   typedef std::shared_ptr<PassingPractice> PassingPractice_ptr;
   typedef std::shared_ptr<Student> Student_ptr;


protected:

   long m_practice_result_id;
   QString m_estimate_employer;
   QString m_estimate_university;
   ListOfReport m_list_of_reports;
   PassingPractice_ptr m_passing_practice;

   Student_ptr m_student;

public:

   PracticeResult();
   PracticeResult(const long & id);
   virtual ~PracticeResult();

   long getpractice_result_id() const;
   QString getestimate_employer() const;
   QString getestimate_university() const;
   ListOfReport getlist_of_reports() const;
   ListOfReport & list_of_reports();
   const ListOfReport & list_of_reports() const;
   PassingPractice_ptr getpassing_practice() const;

   Student_ptr getStudent() const;

   void setpractice_result_id(const long & val);
   void setestimate_employer(const QString & val);
   void setestimate_university(const QString & val);
   void setlist_of_reports(const ListOfReport & val);

   void setStudent(const Student_ptr & val);

   void setpassing_practice(const PassingPractice_ptr & val);

   ListOfReport getlist_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfReport & list_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

   Student_ptr getStudent(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

   PassingPractice_ptr getpassing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_list_of_reports(bool key = false) { Q_UNUSED(key); return "list_of_reports"; }

   static QString relation_Student(bool key = false) { Q_UNUSED(key); return "Student"; }

   static QString relation_passing_practice(bool key = false) { return (key ? QString("passing_practice") : QString("passing_practice_id")); }

public:

   static QString column_practice_result_id(bool key = false) { Q_UNUSED(key); return "practice_result_id"; }
   static QString column_estimate_employer(bool key = false) { Q_UNUSED(key); return "estimate_employer"; }
   static QString column_estimate_university(bool key = false) { Q_UNUSED(key); return "estimate_university"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Practice_result") : QString("t_practice_result")); }

};

typedef std::shared_ptr<PracticeResult> PracticeResult_ptr;
typedef qx::QxCollection<long, PracticeResult_ptr> ListOfPracticeResult;
typedef std::shared_ptr<ListOfPracticeResult> ListOfPracticeResult_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(PracticeResult, qx::trait::no_base_class_defined, 0, PracticeResult)

#include "../include/Passing_practice.h"
#include "../include/Student.h"
#include "../include/Report.h"



#endif // _DEPARTMENT_PRACTICE_RESULT_H_
