#ifndef _DEPARTMENT_EVENTS_H_
#define _DEPARTMENT_EVENTS_H_

class Employer;

class DEPARTMENT_EXPORT Events
{

   QX_REGISTER_FRIEND_CLASS(Events)

public:

   typedef std::shared_ptr<Employer> Employer_ptr;

protected:

   long m_events_id;
   QString m_name;
   QString m_description;
   QDate m_begin;
   QDate m_ending;
   Employer_ptr m_employer;

public:

   Events();
   Events(const long & id);
   virtual ~Events();

   long getevents_id() const;
   QString getname() const;
   QString getdescription() const;
   QDate getbegin() const;
   QDate getending() const;
   Employer_ptr getemployer() const;

   void setevents_id(const long & val);
   void setname(const QString & val);
   void setdescription(const QString & val);
   void setbegin(const QDate & val);
   void setending(const QDate & val);
   void setemployer(const Employer_ptr & val);

   Employer_ptr getemployer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_employer(bool key = false) { Q_UNUSED(key); return "employer"; }

public:

   static QString column_events_id(bool key = false) { Q_UNUSED(key); return "Event_id"; }
   static QString column_name(bool key = false) { Q_UNUSED(key); return "name"; }
   static QString column_description(bool key = false) { Q_UNUSED(key); return "description"; }
   static QString column_begin(bool key = false) { Q_UNUSED(key); return "begin"; }
   static QString column_ending(bool key = false) { Q_UNUSED(key); return "ending"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Event") : QString("t_Event")); }

};

typedef std::shared_ptr<Events> Events_ptr;
typedef qx::QxCollection<long, Events_ptr> ListOfEvent;
typedef std::shared_ptr<ListOfEvent> ListOfEvent_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Events, qx::trait::no_base_class_defined, 0, Events)

#include "../include/Employer.h"



#endif // _DEPARTMENT_EVENTS_H_
