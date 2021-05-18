#ifndef _DEPARTMENT_REPORT_H_
#define _DEPARTMENT_REPORT_H_

class PracticeResult;
class HeadUniversity;
class HeadEmployer;
class PassingPractice;
class Student;

class DEPARTMENT_EXPORT Report
{

   QX_REGISTER_FRIEND_CLASS(Report)

public:

   typedef std::shared_ptr<PracticeResult> PracticeResult_ptr;
   typedef std::shared_ptr<HeadUniversity> HeadUniversity_ptr;
   typedef std::shared_ptr<HeadEmployer> HeadEmployer_ptr;
   typedef std::shared_ptr<PassingPractice> PassingPractice_ptr;

   typedef std::shared_ptr<Student> Student_ptr;

protected:

   long m_Report_id;
   QByteArray m_report;
   QString m_feedback_university;
   QString m_feedback_employer;
   PracticeResult_ptr m_practice_result;
   HeadUniversity_ptr m_head_university;
   HeadEmployer_ptr m_head_employer;
   PassingPractice_ptr m_passing_practice;

   Student_ptr m_student;


public:

   Report();
   Report(const long & id);
   virtual ~Report();

   long getReport_id() const;
   QByteArray getreport() const;
   QString getfeedback_university() const;
   QString getfeedback_employer() const;
   PracticeResult_ptr getpractice_result() const;
   HeadUniversity_ptr gethead_university() const;
   HeadEmployer_ptr gethead_employer() const;
   PassingPractice_ptr getpassing_practice() const;


   Student_ptr getstudent() const;

   void setReport_id(const long & val);
   void setreport(const QByteArray & val);
   void setfeedback_university(const QString & val);
   void setfeedback_employer(const QString & val);
   void setpractice_result(const PracticeResult_ptr & val);
   void sethead_university(const HeadUniversity_ptr & val);
   void sethead_employer(const HeadEmployer_ptr & val);

   void setstudent(const Student_ptr & val);
   void setpassing_practice(const PassingPractice_ptr & val);


   PracticeResult_ptr getpractice_result(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   HeadUniversity_ptr gethead_university(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   HeadEmployer_ptr gethead_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Student_ptr getstudent(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   PassingPractice_ptr getpassing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);


public:
   static QString relation_passing_practice(bool key = false) { return (key ? QString("passing_practice") : QString("passing_practice_id")); }
   static QString relation_head_university(bool key = false) { return (key ? QString("head_university") : QString("head_university_id")); }
   static QString relation_head_employer(bool key = false) { return (key ? QString("head_employer") : QString("head_employer_id")); }
   static QString relation_list_of_passing_practice(bool key = false) { Q_UNUSED(key); return "list_of_passing_practice"; }
   static QString relation_Student(bool key = false) { Q_UNUSED(key); return "Student"; }


public:

   static QString column_Report_id(bool key = false) { Q_UNUSED(key); return "Report_id"; }
   static QString column_report(bool key = false) { Q_UNUSED(key); return "report"; }
   static QString column_feedback_university(bool key = false) { Q_UNUSED(key); return "feedback_university"; }
   static QString column_feedback_employer(bool key = false) { Q_UNUSED(key); return "feedback_employer"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Report") : QString("t_Report")); }

};

typedef std::shared_ptr<Report> Report_ptr;
typedef qx::QxCollection<long, Report_ptr> ListOfReport;
typedef std::shared_ptr<ListOfReport> ListOfReport_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Report, qx::trait::no_base_class_defined, 0, Report)
#include "../include/Passing_practice.h"
#include "../include/Student.h"
#include "../include/Practice_result.h"
#include "../include/head_university.h"
#include "../include/head_employer.h"


#endif // _DEPARTMENT_REPORT_H_
