#ifndef _DEPARTMENT_DISCIPLINE_H_
#define _DEPARTMENT_DISCIPLINE_H_

class EducationalProgram;
class ResultEducation;

class DEPARTMENT_EXPORT Discipline
{

   QX_REGISTER_FRIEND_CLASS(Discipline)

public:

   typedef std::shared_ptr<EducationalProgram> EducationProgram_ptr;
   typedef qx::QxCollection<long, std::shared_ptr<ResultEducation> > ListOfResultEducational;

protected:

   long m_Discipline_id;
   int m_semester;
   QString m_name;
   QString m_description;
   EducationProgram_ptr m_educational_program;
   ListOfResultEducational m_list_of_result_educational;

public:

   Discipline();
   Discipline(const long & id);
   virtual ~Discipline();

   long getdiscipline_id() const;
   int getsemester() const;
   QString getname() const;
   QString getdescription() const;
   EducationProgram_ptr geteducational_program() const;
   ListOfResultEducational getlist_of_result_educational() const;
   ListOfResultEducational & list_of_result_educational();
   const ListOfResultEducational & list_of_result_educational() const;

   void setdiscipline_id(const long & val);
   void setsemester(const int & val);
   void setname(const QString & val);
   void setdescription(const QString & val);
   void seteducational_program(const EducationProgram_ptr & val);
   void setlist_of_result_educational(const ListOfResultEducational & val);

   EducationProgram_ptr geteducational_program(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfResultEducational getlist_of_result_educational(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   ListOfResultEducational & list_of_result_educational(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_educational_program(bool key = false) { return (key ? QString("educational_program") : QString("Educational_program_id")); }
   static QString relation_list_of_result_educational(bool key = false) { Q_UNUSED(key); return "list_of_result_educational"; }

public:

   static QString column_Discipline_id(bool key = false) { Q_UNUSED(key); return "Discipline_id"; }
   static QString column_semester(bool key = false) { Q_UNUSED(key); return "semester"; }
   static QString column_name(bool key = false) { Q_UNUSED(key); return "name"; }
   static QString column_description(bool key = false) { Q_UNUSED(key); return "description"; }

public:

   static QString table_name(bool key = false) { return (key ? QString("Discipline") : QString("t_Discipline")); }

};

typedef std::shared_ptr<Discipline> Discipline_ptr;
typedef qx::QxCollection<long, Discipline_ptr> ListOfDiscipline;
typedef std::shared_ptr<ListOfDiscipline> ListOfDiscipline_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_DEPARTMENT(Discipline, qx::trait::no_base_class_defined, 0, Discipline)

#include "../include/Educational_program.h"
#include "../include/Result_education.h"



#endif // _DEPARTMENT_DISCIPLINE_H_
