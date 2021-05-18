#ifndef _DEPARTMENT_RESULT_EDUCATION_H_
#define _DEPARTMENT_RESULT_EDUCATION_H_

class EducationalProgram;
class Discipline;
class Employer;

class DEPARTMENT_EXPORT ResultEducation
{

   QX_REGISTER_FRIEND_CLASS(ResultEducation)

public:

   typedef std::shared_ptr<EducationalProgram> EducationProgram_ptr;
   typedef std::shared_ptr<Discipline> Discipline_ptr;
   typedef qx::QxCollection<long, std::shared_ptr<Employer> > ListOfEmployer;

protected:

   long m_Result_discipline_id;
   QString m_description;
   QString m_acquired_skills;
   EducationProgram_ptr m_educational_program;
   Discipline_ptr m_discipline;
   ListOfEmployer m_list_of_employer;

public:

   ResultEducation();
   ResultEducation(const long & id);
   virtual ~ResultEducation();

   long getResult_discipline_id() const;
   QString getdescription() const;
   QString getacquired_skills() const;
   EducationProgram_ptr geteducational_program() const;
   Discipline_ptr getdiscipline() const;
   ListOfEmployer getlist_of_employer() const;
   ListOfEmployer & list_of_employer();
   const ListOfEmployer & list_of_employer() const;

   void setResult_discipline_id(const long & val);
   void setdescription(const QString & val);
   void setacquired_skills(const QString & val);
   void seteducational_program(const EducationProgram_ptr & val);
   void setdiscipline(const Discipline_ptr & val);
   void setlist_of_employer(const ListOfEmployer & val);

   EducationProgram_ptr geteducational_program(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   Discipline_ptr getdiscipline(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfEmployer getlist_of_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfEmployer & list_of_employer(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);


public:

   static QString relation_educational_program(bool key = false) { return (key ? QString("educational_program") : QString("Educational_program_id")); }
   static QString relation_discipline(bool key = false) { return (key ? QString("discipline") : QString("Discipline_id")); }
   static QString relation_list_of_employer(bool key = false) { Q_UNUSED(key); return "list_of_employer"; }


public:

   static QString column_Result_discipline_id(bool key = false) { Q_UNUSED(key); return "Result_discipline_id"; }
   static QString column_description(bool key = false) { Q_UNUSED(key); return "description"; }
   static QString column_acquired_skills(bool key = false) { Q_UNUSED(key); return "acquired_skills"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Result_education") : QString("t_Result_discipline")); }

};

typedef std::shared_ptr<ResultEducation> ResultEducation_ptr;
typedef qx::QxCollection<long, ResultEducation_ptr> ListOfResultEducation;
typedef std::shared_ptr<ListOfResultEducation> ListOfResultEducation_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(ResultEducation, qx::trait::no_base_class_defined, 0, ResultEducation)
#include "../include/Employer.h"
#include "../include/Educational_program.h"
#include "../include/Discipline.h"



#endif // _DEPARTMENT_RESULT_EDUCATION_H_
