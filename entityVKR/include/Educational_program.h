#ifndef _DEPARTMENT_EDUCATIONAL_PROGRAM_H_
#define _DEPARTMENT_EDUCATIONAL_PROGRAM_H_

class ResultEducation;
class Discipline;
class Practice;
class Student;

class DEPARTMENT_EXPORT EducationalProgram
{

   QX_REGISTER_FRIEND_CLASS(EducationalProgram)

public:

   typedef qx::QxCollection<long, std::shared_ptr<ResultEducation> > ListOfResultEducation;
   typedef qx::QxCollection<long, std::shared_ptr<Discipline> > ListOfDiscipline;
   typedef qx::QxCollection<long, std::shared_ptr<Practice> > ListOfPractice;
   typedef qx::QxCollection<long, std::shared_ptr<Student> > ListOfStudent;


protected:

   long m_educational_program_id;
   QString m_name;
   QString m_description;
   QString m_field;
   QString m_focus;
   ListOfResultEducation m_list_of_result_education;
   ListOfDiscipline m_list_of_discipline;
   ListOfPractice m_list_of_practice;
   ListOfStudent m_list_of_student;


public:

   EducationalProgram();
   EducationalProgram(const long & id);
   virtual ~EducationalProgram();

   long geteducational_program_id() const;
   QString getname() const;
   QString getdescription() const;
   QString getfield() const;
   QString getfocus() const;
   ListOfResultEducation getlist_of_result_education() const;
   ListOfResultEducation & list_of_result_education();
   const ListOfResultEducation & list_of_result_education() const;
   ListOfDiscipline getlist_of_discipline() const;
   ListOfDiscipline & list_of_discipline();
   const ListOfDiscipline & list_of_discipline() const;
   ListOfPractice getlist_of_Practice() const;
   ListOfPractice & list_of_Practice();
   const ListOfPractice & list_of_Practice() const;
   ListOfStudent getlist_of_Student() const;
   ListOfStudent & list_of_Student();
   const ListOfStudent & list_of_Student() const;

   void seteducational_program_id(const long & val);
   void setname(const QString & val);
   void setdescription(const QString & val);
   void setfield(const QString & val);
   void setfocus(const QString & val);
   void setlist_of_result_education(const ListOfResultEducation & val);
   void setlist_of_discipline(const ListOfDiscipline & val);
   void setlist_of_Practice(const ListOfPractice & val);
   void setlist_of_Student(const ListOfStudent & val);

   ListOfResultEducation getlist_of_result_education(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfResultEducation & list_of_result_education(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfDiscipline getlist_of_discipline(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfDiscipline & list_of_discipline(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPractice getlist_of_Practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfPractice & list_of_Practice(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfStudent getlist_of_Student(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfStudent & list_of_Student(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_list_of_result_education(bool key = false) { Q_UNUSED(key); return "list_of_result_education"; }
   static QString relation_list_of_discipline(bool key = false) { Q_UNUSED(key); return "list_of_discipline"; }
   static QString relation_list_of_Student(bool key = false) { Q_UNUSED(key); return "list_of_Student"; }


public:

   static QString column_educational_program_id(bool key = false) { Q_UNUSED(key); return "educational_program_id"; }
   static QString column_name(bool key = false) { Q_UNUSED(key); return "name"; }
   static QString column_description(bool key = false) { Q_UNUSED(key); return "description"; }
   static QString column_field(bool key = false) { Q_UNUSED(key); return "field"; }
   static QString column_focus(bool key = false) { Q_UNUSED(key); return "focus"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Educational_program") : QString("t_educational_program")); }

};

typedef std::shared_ptr<EducationalProgram> EducationalProgram_ptr;
typedef qx::QxCollection<long, EducationalProgram_ptr> ListOfEducationalProgram;
typedef std::shared_ptr<ListOfEducationalProgram> ListOfEducationalProgram_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(EducationalProgram, qx::trait::no_base_class_defined, 0, EducationalProgram)
#include "../include/Practice.h"
#include "../include/Result_education.h"
#include "../include/Discipline.h"
#include "../include/Student.h"


#endif // _DEPARTMENT_EDUCATIONAL_PROGRAM_H_
