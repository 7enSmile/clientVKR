#ifndef _DEPARTMENT_GROUP_H_
#define _DEPARTMENT_GROUP_H_

class Student;

class DEPARTMENT_EXPORT Group
{

   QX_REGISTER_FRIEND_CLASS(Group)

public:

   typedef qx::QxCollection<long, std::shared_ptr<Student> > ListOfStudent;

protected:

   long m_Groups_id;
   QString m_number;
   ListOfStudent m_list_of_student;

public:

   Group();
   Group(const long & id);
   virtual ~Group();

   long getgroup_id() const;
   QString getnumber() const;
   ListOfStudent getlist_of_student() const;
   ListOfStudent & list_of_student();
   const ListOfStudent & list_of_student() const;

   void setgroup_id(const long & val);
   void setnumber(const QString & val);
   void setlist_of_student(const ListOfStudent & val);

   ListOfStudent getlist_of_student(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfStudent & list_of_student(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_list_of_student(bool key = false) { Q_UNUSED(key); return "list_of_student"; }

public:

   static QString column_Groups_id(bool key = false) { Q_UNUSED(key); return "Group_id"; }
   static QString column_number(bool key = false) { Q_UNUSED(key); return "number"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Group") : QString("t_Group")); }

};

typedef std::shared_ptr<Group> Group_ptr;
typedef qx::QxCollection<long, Group_ptr> ListOfGroup;
typedef std::shared_ptr<ListOfGroup> ListOfGroup_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Group, qx::trait::no_base_class_defined, 0, Group)

#include "../include/Student.h"



#endif // _DEPARTMENT_GROUP_H_
