#ifndef _DEPARTMENT_TESTPRACTICE_H_
#define _DEPARTMENT_TESTPRACTICE_H_

class Practice;
class Employer;

class DEPARTMENT_EXPORT TestPractice
{

   QX_REGISTER_FRIEND_CLASS(TestPractice)

public:

   typedef std::shared_ptr<Practice> Practice_ptr;
   typedef std::shared_ptr<Employer> Employer_ptr;

protected:

   long m_TestPractice_id;
   QString m_name;
   QByteArray m_data;
   Practice_ptr m_practice;
   Employer_ptr m_employer;

public:

   TestPractice();
   TestPractice(const long & id);
   virtual ~TestPractice();

   long getTestPractice_id() const;
   QString getname() const;
   QByteArray getdata() const;
   Practice_ptr getpractice() const;
   Employer_ptr getemployer() const;

   void setTestPractice_id(const long & val);
   void setname(const QString & val);
   void setdata(const QByteArray & val);
   void setpractice(const Practice_ptr & val);
   void setemployer(const Employer_ptr & val);

   Practice_ptr getpractice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Employer_ptr getemployer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_practice(bool key = false) { Q_UNUSED(key); return "practice"; }
   static QString relation_employer(bool key = false) { Q_UNUSED(key); return "employer"; }

public:

   static QString column_TestPractice_id(bool key = false) { Q_UNUSED(key); return "test_practice_id"; }
   static QString column_name(bool key = false) { Q_UNUSED(key); return "name"; }
   static QString column_data(bool key = false) { Q_UNUSED(key); return "data"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("TestPractice") : QString("t_test_practice")); }

};

typedef std::shared_ptr<TestPractice> TestPractice_ptr;
typedef qx::QxCollection<long, TestPractice_ptr> listOfTestPractice;
typedef std::shared_ptr<listOfTestPractice> listOfTestPractice_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(TestPractice, qx::trait::no_base_class_defined, 0, TestPractice)

#include "../include/Practice.h"
#include "../include/Employer.h"


#endif // _DEPARTMENT_TESTPRACTICE_H_
