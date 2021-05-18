
#ifndef _DEPARTMENT_TASK_H_
#define _DEPARTMENT_TASK_H_

class Employer;

class DEPARTMENT_EXPORT Task
{

   QX_REGISTER_FRIEND_CLASS(Task)

public:

   typedef qx::QxCollection<long, std::shared_ptr<Employer> > ListOfEmployer;

protected:

   long m_Task_id;
   QString m_name;
   QString m_description;
   ListOfEmployer m_list_of_employers;

public:

   Task();
   Task(const long & id);
   virtual ~Task();

   long getTask_id() const;
   QString getname() const;
   QString getdescription() const;
   ListOfEmployer getlist_of_employers() const;
   ListOfEmployer & list_of_employers();
   const ListOfEmployer & list_of_employers() const;

   void setTask_id(const long & val);
   void setname(const QString & val);
   void setdescription(const QString & val);
   void setlist_of_employers(const ListOfEmployer & val);

   ListOfEmployer getlist_of_employers(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfEmployer & list_of_employers(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_list_of_employers(bool key = false) { Q_UNUSED(key); return "list_of_employers"; }

public:

   static QString column_Task_id(bool key = false) { Q_UNUSED(key); return "Task_id"; }
   static QString column_name(bool key = false) { Q_UNUSED(key); return "name"; }
   static QString column_description(bool key = false) { Q_UNUSED(key); return "description"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Task") : QString("t_Task")); }

};

typedef std::shared_ptr<Task> Task_ptr;
typedef qx::QxCollection<long, Task_ptr> ListOfTask;
typedef std::shared_ptr<ListOfTask> ListOfTask_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Task, qx::trait::no_base_class_defined, 0, Task)

#include "../include/Employer.h"

#include "../custom/include/Task.h"

#endif // _DEPARTMENT_TASK_H_
