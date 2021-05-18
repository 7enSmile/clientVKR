

#ifndef _DEPARTMENT_ACTIVITY_H_
#define _DEPARTMENT_ACTIVITY_H_

class Employer;

class DEPARTMENT_EXPORT Activity
{

   QX_REGISTER_FRIEND_CLASS(Activity)

public:

   typedef qx::QxCollection<long, std::shared_ptr<Employer> > ListOfEmployers;

protected:

   long m_Activity_id;
   QString m_name;
   QString m_description;
   ListOfEmployers m_list_of_employers;

public:

   Activity();
   Activity(const long & id);
   virtual ~Activity();

   long getactivity_id() const;
   QString getname() const;
   QString getdescription() const;
   ListOfEmployers getlist_of_employers() const;
   ListOfEmployers & list_of_employers();
   const ListOfEmployers & list_of_employers() const;

   void setactivity_id(const long & val);
   void setname(const QString & val);
   void setdescription(const QString & val);
   void setlist_of_employers(const ListOfEmployers & val);

   ListOfEmployers getlist_of_employers(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfEmployers & list_of_employers(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_list_of_employers(bool key = false) { Q_UNUSED(key); return "list_of_employers"; }

public:

   static QString column_Activity_id(bool key = false) { Q_UNUSED(key); return "Activity_id"; }
   static QString column_name(bool key = false) { Q_UNUSED(key); return "name"; }
   static QString column_description(bool key = false) { Q_UNUSED(key); return "description"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Activity") : QString("t_Activity")); }

};

typedef std::shared_ptr<Activity> Activity_ptr;
typedef qx::QxCollection<long, Activity_ptr> ListOfActivity;
typedef std::shared_ptr<ListOfActivity> ListOfActivity_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Activity, qx::trait::no_base_class_defined, 0, Activity)

#include "../include/Employer.h"

#include "../custom/include/Activity.h"

#endif // _DEPARTMENT_ACTIVITY_H_
