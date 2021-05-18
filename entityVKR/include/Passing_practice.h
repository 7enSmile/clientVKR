#ifndef _DEPARTMENT_PASSING_PRACTICE_H_
#define _DEPARTMENT_PASSING_PRACTICE_H_

class Practice;
class Student;
class HeadEmployer;
class HeadUniversity;
class TaskPractice;
class Employer;
class Report;
class PracticeResult;

class DEPARTMENT_EXPORT PassingPractice
{

   QX_REGISTER_FRIEND_CLASS(PassingPractice)

public:

   typedef std::shared_ptr<Practice> type_practice;
   typedef std::shared_ptr<HeadEmployer> HeadEmployer_ptr;
   typedef std::shared_ptr<HeadUniversity> HeadUniversity_ptr;
   typedef std::shared_ptr<TaskPractice> Task_ptr;
   typedef std::shared_ptr<Employer> Employer_ptr;
   typedef std::shared_ptr<Student> Student_ptr;
   typedef qx::QxCollection<long, std::shared_ptr<Report> > ListOfReport;
   typedef qx::QxCollection<long, std::shared_ptr<PracticeResult> > ListOfPracticeResult;




protected:

   long m_Passing_practice_id;

   type_practice m_practice;

   HeadEmployer_ptr m_head_employer_id;
   HeadUniversity_ptr m_head_university_id;
   Task_ptr m_task;
   Employer_ptr m_employer;
   Student_ptr m_studen;
   ListOfReport m_list_of_reports;
   ListOfPracticeResult m_list_of_practice_result;




public:

   PassingPractice();
   PassingPractice(const long & id);
   virtual ~PassingPractice();

   long getPassingPractice_id() const;

   type_practice getpractice() const;
   Student_ptr getstuden() const;
   HeadEmployer_ptr gethead_employer() const;
   HeadUniversity_ptr gethead_university() const;
   Task_ptr gettask() const;
   Employer_ptr getemployer() const;


   ListOfReport getlist_of_reports() const;
   ListOfReport & list_of_reports();
   const ListOfReport & list_of_reports() const;

   ListOfPracticeResult getlist_of_practice_result() const;
   ListOfPracticeResult & list_of_practice_result();
   const ListOfPracticeResult & list_of_practice_result() const;



   void setpassing_practice(const long & val);

   void setpractice(const type_practice & val);

   void sethead_employer(const HeadEmployer_ptr & val);
   void sethead_university(const HeadUniversity_ptr & val);
   void settask(const Task_ptr & val);
   void setemployer(const Employer_ptr & val);
   void setstuden(const Student_ptr & val);



   void setlist_of_reports(const ListOfReport & val);
   void setlist_of_practice_result(const ListOfPracticeResult & val);

   Task_ptr gettask(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   type_practice getpractice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   HeadEmployer_ptr gethead_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   HeadUniversity_ptr gethead_university(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Employer_ptr getemployer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Student_ptr getstuden(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

   ListOfReport getlist_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfReport & list_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

   ListOfPracticeResult getlist_of_practice_result(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPracticeResult & list_of_practice_result(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_practice(bool key = false) { return (key ? QString("practice") : QString("practice_id")); }
   static QString relation_list_of_reports(bool key = false) { Q_UNUSED(key); return "list_of_reports"; }
   static QString relation_head_employer_id(bool key = false) { Q_UNUSED(key); return "head_employer_id"; }
   static QString relation_head_university_id(bool key = false) { Q_UNUSED(key); return "head_university_id"; }
   static QString relation_task(bool key = false) { return (key ? QString("task") : QString("task_id")); }
   static QString relation_employer(bool key = false) { return (key ? QString("employer") : QString("employer_id")); }
   static QString relation_studen(bool key = false) { return (key ? QString("studen") : QString("Student_id")); }
   static QString relation_report(bool key = false) { Q_UNUSED(key); return "Report"; }
   static QString relation_list_of_practice_result(bool key = false) { Q_UNUSED(key); return "list_of_practice_result"; }





public:

   static QString column_Passing_practice_id(bool key = false) { Q_UNUSED(key); return "Passing_practice_id"; }
   static QString column_beginning(bool key = false) { Q_UNUSED(key); return "beginning"; }
   static QString column_ending(bool key = false) { Q_UNUSED(key); return "ending"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Passing_practice") : QString("t_Passing_practice")); }

};

typedef std::shared_ptr<PassingPractice> PassingPractice_ptr;
typedef qx::QxCollection<long, PassingPractice_ptr>  ListOfPassingPractice;
typedef std::shared_ptr<ListOfPassingPractice> ListOfPassingPractice_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(PassingPractice, qx::trait::no_base_class_defined, 0, PassingPractice)

#include "../include/Report.h"
#include "../include/Employer.h"
#include "../include/Practice.h"
#include "../include/Student.h"
#include "../include/Head_employer.h"
#include "../include/Head_university.h"
#include "../include/Task_practice.h"



#endif // _DEPARTMENT_PASSING_PRACTICE_H_
