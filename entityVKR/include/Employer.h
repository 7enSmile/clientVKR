/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/03/24 12:12) : please, do NOT modify this file ! **
************************************************************************************************/

#ifndef _DEPARTMENT_EMPLOYER_H_
#define _DEPARTMENT_EMPLOYER_H_

class Activity;
class Collaboration;
class Task;
class Practice;
class Events;
class HeadEmployer;
class ContactEmployer;
class PassingPractice;
class ResultEducation;
class TestPractice;

class DEPARTMENT_EXPORT Employer
{

   QX_REGISTER_FRIEND_CLASS(Employer)

public:

   typedef qx::QxCollection<long, std::shared_ptr<Activity> > ListOfActivity;
   typedef qx::QxCollection<long, std::shared_ptr<Collaboration> > ListOfCollaboration;
   typedef qx::QxCollection<long, std::shared_ptr<Task> > ListOfTask;
   typedef qx::QxCollection<long, std::shared_ptr<Practice> > ListOfPractice;
   typedef qx::QxCollection<long, std::shared_ptr<Events> > ListOfEvents;
   typedef qx::QxCollection<long, std::shared_ptr<HeadEmployer> > ListOfHeadEmployer;
   typedef qx::QxCollection<long, std::shared_ptr<ContactEmployer> > ListOfContactEmployer;
   typedef qx::QxCollection<long, std::shared_ptr<PassingPractice> > ListOfPassingPractice;
   typedef qx::QxCollection<long, std::shared_ptr<ResultEducation> > ListOfResultEducation;
   typedef qx::QxCollection<long, std::shared_ptr<TestPractice> > ListOfTestPractice;


protected:

   long m_Employer_id;
   QString m_name;
   ListOfActivity m_list_of_activity;
   ListOfCollaboration m_list_of_collaboration;
   ListOfTask m_list_of_task;
   ListOfPractice m_list_of_practice;
   ListOfEvents m_list_of_events;
   ListOfHeadEmployer m_list_of_head_employer;
   ListOfContactEmployer m_list_of_contact_employer;
   ListOfPassingPractice m_list_of_passing_practice;
   ListOfResultEducation m_list_of_result_education;
   ListOfTestPractice  m_list_of_TestPractice;


public:

   Employer();
   Employer(const long & id);
   virtual ~Employer();

   long getemployer_id() const;
   QString getname() const;
   ListOfActivity getlist_of_activity() const;
   ListOfActivity & list_of_activity();
   const ListOfActivity & list_of_activity() const;
   ListOfCollaboration getlist_of_collaboration() const;
   ListOfCollaboration & list_of_collaboration();
   const ListOfCollaboration & list_of_collaboration() const;
   ListOfTask getlist_of_task() const;
   ListOfTask & list_of_task();
   const ListOfTask & list_of_task() const;
   ListOfPractice getlist_of_practice() const;
   ListOfPractice & list_of_practice();
   const ListOfPractice & list_of_practice() const;
   ListOfEvents getlist_of_events() const;
   ListOfEvents & list_of_events();
   const ListOfEvents & list_of_events() const;
   ListOfHeadEmployer getlist_of_head_employer() const;
   ListOfHeadEmployer & list_of_head_employer();
   const ListOfHeadEmployer & list_of_head_employer() const;
   ListOfContactEmployer getlist_of_contact_employer() const;
   ListOfContactEmployer & list_of_contact_employer();
   const ListOfContactEmployer & list_of_contact_employer() const;
   ListOfPassingPractice getlist_of_passing_practice() const;
   ListOfPassingPractice & list_of_passing_practice();
   const ListOfPassingPractice & list_of_passing_practice() const;
   ListOfResultEducation getlist_of_result_education() const;
   ListOfResultEducation & list_of_result_education();
   const ListOfResultEducation & list_of_result_education() const;
   ListOfTestPractice getlist_of_TestPractice() const;
   ListOfTestPractice & list_of_TestPractice();
   const ListOfTestPractice & list_of_TestPractice() const;

   void setEmployer_id(const long & val);
   void setname(const QString & val);
   void setlist_of_activity(const ListOfActivity & val);
   void setlist_of_collaboration(const ListOfCollaboration & val);
   void setlist_of_task(const ListOfTask & val);
   void setlist_of_practice(const ListOfPractice & val);
   void setlist_of_events(const ListOfEvents & val);
   void setlist_of_head_employer(const ListOfHeadEmployer & val);
   void setlist_of_contact_employer(const ListOfContactEmployer & val);
   void setlist_of_passing_practice(const ListOfPassingPractice & val);
   void setlist_of_result_education(const ListOfResultEducation & val);
   void setlist_of_TestPractice(const ListOfTestPractice & val);


   ListOfActivity getlist_of_activity(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfActivity & list_of_activity(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfCollaboration getlist_of_collaboration(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfCollaboration & list_of_collaboration(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfTask getlist_of_task(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfTask & list_of_task(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPractice getlist_of_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPractice & list_of_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfEvents getlist_of_events(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfEvents & list_of_events(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfHeadEmployer getlist_of_head_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfHeadEmployer & list_of_head_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfContactEmployer getlist_of_contact_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfContactEmployer & list_of_contact_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPassingPractice getlist_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPassingPractice & list_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfResultEducation getlist_of_result_education(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfResultEducation & list_of_result_education(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfTestPractice getlist_of_TestPractice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfTestPractice & list_of_TestPractice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);




public:

   static QString relation_list_of_activity(bool key = false) { Q_UNUSED(key); return "list_of_activity"; }
   static QString relation_list_of_collaboration(bool key = false) { Q_UNUSED(key); return "list_of_collaboration"; }
   static QString relation_list_of_task(bool key = false) { Q_UNUSED(key); return "list_of_task"; }
   static QString relation_list_of_practice(bool key = false) { Q_UNUSED(key); return "list_of_practice"; }
   static QString relation_list_of_events(bool key = false) { Q_UNUSED(key); return "list_of_events"; }
   static QString relation_list_of_head_employer(bool key = false) { Q_UNUSED(key); return "list_of_head_employer"; }
   static QString relation_list_of_contact_employer(bool key = false) { Q_UNUSED(key); return "list_of_contact_employer"; }
   static QString relation_list_of_passing_practice(bool key = false) { Q_UNUSED(key); return "list_of_passing_practice"; }
   static QString relation_list_of_result_education(bool key = false) { Q_UNUSED(key); return "list_of_result_education"; }
   static QString relation_list_of_TestPractice(bool key = false) { Q_UNUSED(key); return "list_of_TestPractice"; }



public:

   static QString column_Employer_id(bool key = false) { Q_UNUSED(key); return "Employer_id"; }
   static QString column_name(bool key = false) { Q_UNUSED(key); return "name"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Employer") : QString("t_Employer")); }

};

typedef std::shared_ptr<Employer> Employer_ptr;
typedef qx::QxCollection<long, Employer_ptr> ListOfEmployer;
typedef std::shared_ptr<ListOfEmployer> ListOfEmployer_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Employer, qx::trait::no_base_class_defined, 0, Employer)

#include "../include/Activity.h"
#include "../include/Collaboration.h"
#include "../include/Task.h"
#include "../include/Practice.h"
#include "../include/Event.h"
#include "../include/Head_employer.h"
#include "../include/Contact_employer.h"
#include "../custom/include/Employer.h"
#include "../include/Passing_practice.h"
#include "../include/Result_education.h"
#include "../include/Test_practice.h"
#endif // _DEPARTMENT_EMPLOYER_H_
