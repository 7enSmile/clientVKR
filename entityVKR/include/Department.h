#ifndef _DEPARTMENT_DEPARTMENT_H_
#define _DEPARTMENT_DEPARTMENT_H_

class HeadUniversity;

class DEPARTMENT_EXPORT Department
{

   QX_REGISTER_FRIEND_CLASS(Department)

public:

   typedef qx::QxCollection<long, std::shared_ptr<HeadUniversity> > ListOfHeadUniversity;

protected:

   long m_Department_id;
   QString m_name;
   ListOfHeadUniversity m_list_of_head_university;

public:

   Department();
   Department(const long & id);
   virtual ~Department();

   long getdepartment_id() const;
   QString getname() const;
   ListOfHeadUniversity getlist_of_head_university() const;
   ListOfHeadUniversity & list_of_head_university();
   const ListOfHeadUniversity & list_of_head_university() const;

   void setdepartment_id(const long & val);
   void setname(const QString & val);
   void setlist_of_head_university(const ListOfHeadUniversity & val);

   ListOfHeadUniversity getlist_of_head_university(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfHeadUniversity & list_of_head_university(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_list_of_head_university(bool key = false) { Q_UNUSED(key); return "list_of_head_university"; }

public:

   static QString column_Department_id(bool key = false) { Q_UNUSED(key); return "Department_id"; }
   static QString column_name(bool key = false) { Q_UNUSED(key); return "name"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Department") : QString("t_department")); }

};

typedef std::shared_ptr<Department> Department_ptr;
typedef qx::QxCollection<long, Department_ptr> ListOfDepartment;
typedef std::shared_ptr<ListOfDepartment> ListOfDepartment_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Department, qx::trait::no_base_class_defined, 0, Department)

#include "../include/Head_university.h"



#endif // _DEPARTMENT_DEPARTMENT_H_
