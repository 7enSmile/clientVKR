#ifndef _DEPARTMENT_TASK_PRACTICE_H_
#define _DEPARTMENT_TASK_PRACTICE_H_

class PassingPractice;

class DEPARTMENT_EXPORT TaskPractice
{

   QX_REGISTER_FRIEND_CLASS(TaskPractice)

public:

   typedef qx::QxCollection<long, std::shared_ptr<PassingPractice> > ListOfPassingPractice;

protected:

   long m_Task_id;
   QString m_description;
   QString m_name;
   ListOfPassingPractice m_list_of_passeing_practice;

public:

   TaskPractice();
   TaskPractice(const long & id);
   virtual ~TaskPractice();

   long getTask_id() const;
   QString getdescription() const;
   QString getname() const;
   ListOfPassingPractice getlist_of_passeing_practice() const;
   ListOfPassingPractice & list_of_passeing_practice();
   const ListOfPassingPractice & list_of_passeing_practice() const;

   void setTask_id(const long & val);
   void setdescription(const QString & val);
   void setname(const QString & val);
   void setlist_of_passeing_practice(const ListOfPassingPractice & val);

   ListOfPassingPractice getlist_of_passeing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPassingPractice & list_of_passeing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_list_of_passeing_practice(bool key = false) { Q_UNUSED(key); return "list_of_passeing_practice"; }

public:

   static QString column_Task_id(bool key = false) { Q_UNUSED(key); return "Task_id"; }
   static QString column_description(bool key = false) { Q_UNUSED(key); return "description"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Task_practice") : QString("t_Task_practice")); }

};

typedef std::shared_ptr<TaskPractice> TaskPractice_ptr;
typedef qx::QxCollection<long, TaskPractice_ptr> ListOfTaskPractice;
typedef std::shared_ptr<ListOfTaskPractice> ListOfTaskPractice_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(TaskPractice, qx::trait::no_base_class_defined, 0, TaskPractice)

#include "../include/Passing_practice.h"


#endif // _DEPARTMENT_TASK_PRACTICE_H_
