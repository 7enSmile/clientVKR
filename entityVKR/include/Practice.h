
#ifndef _DEPARTMENT_PRACTICE_H_
#define _DEPARTMENT_PRACTICE_H_

class Employer;
class PassingPractice;
class EducationalProgram;
class TestPractice;

class DEPARTMENT_EXPORT Practice
{

   QX_REGISTER_FRIEND_CLASS(Practice)

public:


   typedef qx::QxCollection<long, std::shared_ptr<PassingPractice> > ListOfPassingPractice;
   typedef std::shared_ptr<EducationalProgram> EducationProgram_ptr;
   typedef std::shared_ptr<Employer>Employer_ptr;
   typedef qx::QxCollection<long, std::shared_ptr<TestPractice> > ListOfTestPractice;

protected:

   long m_Practice_id;
   int m_semester;
   ListOfPassingPractice m_list_of_passing_practice;
   EducationProgram_ptr m_education_program;
   QDate m_beginning;
   QDate m_ending;
   QString m_customid;
   Employer_ptr m_employer;
   ListOfTestPractice m_list_of_TestPractice;


public:

   Practice();
   Practice(const long & id);
   virtual ~Practice();

   long getPractice_id() const;
   QString getcustomid() const;


   ListOfPassingPractice getlist_of_passing_practice() const;
   ListOfPassingPractice & list_of_passing_practice();
   const ListOfPassingPractice & list_of_passing_practice() const;
   EducationProgram_ptr geteducation_program() const;
   QDate getbeginning() const;
   QDate getending() const;
   Employer_ptr getemployer() const;
   int getsemester() const;
   ListOfTestPractice getlist_of_TestPractice() const;
   ListOfTestPractice & list_of_TestPractice();
   const ListOfTestPractice & list_of_TestPractice() const;



   void setpractice_id(const long & val);

   void setcustomid(const QString & val);



   void setlist_of_passing_practice(const ListOfPassingPractice & val);

   void seteducation_program(const EducationProgram_ptr & val);

   void setbeginning(const QDate & val);

   void setending(const QDate & val);

   void setemployer(const Employer_ptr & val);

   void setsemester(const int & val);

   void setlist_of_TestPractice(const ListOfTestPractice & val);


   ListOfPassingPractice getlist_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPassingPractice & list_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   EducationProgram_ptr geteducation_program(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Employer_ptr getemployer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfTestPractice getlist_of_TestPractice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfTestPractice & list_of_TestPractice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);


public:
   static QString relation_list_of_passing_practice(bool key = false) { Q_UNUSED(key); return "list_of_passing_practice"; }

   static QString relation_education_program(bool key = false) { return (key ? QString("education_program") : QString("Education_program_id")); }

   static QString relation_employer(bool key = false) { return (key ? QString("employer") : QString("employer_id")); }

   static QString relation_list_of_TestPractice(bool key = false) { Q_UNUSED(key); return "list_of_TestPractice"; }

public:

   static QString column_Practice_id(bool key = false) { Q_UNUSED(key); return "Practice_id"; }

   static QString column_customid(bool key = false) { Q_UNUSED(key); return "customid"; }

   static QString column_begin(bool key = false) { Q_UNUSED(key); return "begin"; }
   static QString column_end(bool key = false) { Q_UNUSED(key); return "end"; }

public:


   static QString table_name(bool key = false) { return (key ? QString("Practice") : QString("t_Practice")); }

};

typedef std::shared_ptr<Practice> Practice_ptr;
typedef qx::QxCollection<long, Practice_ptr> ListOfPractice;
typedef std::shared_ptr<ListOfPractice> ListOfPractice_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Practice, qx::trait::no_base_class_defined, 0, Practice)

#include "../include/Passing_practice.h"

#include "../include/Employer.h"

#include "../include/Educational_program.h"

#include "../custom/include/Practice.h"

#include "../include/Test_practice.h"

#endif // _DEPARTMENT_PRACTICE_H_
