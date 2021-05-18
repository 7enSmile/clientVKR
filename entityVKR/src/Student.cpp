#include "../include/department_precompiled_header.h"

#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Person.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Student, Student)

namespace qx {

template <>
void register_class(QxClass<Student> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Student");

   pData = t.id(& Student::m_Strudent_id, "Strudent_id", 0);

   pRelation = t.relationManyToOne(& Student::m_group, "group", 0);
   pRelation->getDataMember()->setName("group_id");
   pRelation = t.relationManyToOne(& Student::m_person, "person_id", 0);
   pRelation = t.relationOneToMany(& Student::m_list_of_passing_practice, "list_of_passing_practice", "studen", 0);
   pRelation = t.relationManyToOne(& Student::m_education_program, "Education_program", 0);
   pRelation->getDataMember()->setName("Education_program_id");
   pRelation = t.relationOneToMany(& Student::m_list_of_reports, "list_of_reports", "Student_id", 0);
   pRelation = t.relationOneToMany(& Student::m_list_of_practice_result, "list_of_practice_result", "Student_id", 0);



   qx::QxValidatorX<Student> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Student::Student() : m_Strudent_id(0) { ; }

Student::Student(const long & id) : m_Strudent_id(id) { ; }

Student::~Student() { ; }

long Student::getstudent_id() const { return m_Strudent_id; }

Student::Group_ptr Student::getgroup() const { return m_group; }

Student::Person_ptr Student::getperson() const { return m_person; }

Student::ListOfPassingPractice Student::getlist_of_passing_practice() const { return m_list_of_passing_practice; }

Student::ListOfPassingPractice & Student::list_of_passing_practice() { return m_list_of_passing_practice; }

Student::EducationProgram_ptr Student::geteducation_program() const { return m_education_program; }

const Student::ListOfPassingPractice & Student::list_of_passing_practice() const { return m_list_of_passing_practice; }

Student::ListOfReport Student::getlist_of_reports() const { return m_list_of_reports; }

Student::ListOfReport & Student::list_of_reports() { return m_list_of_reports; }

const Student::ListOfReport & Student::list_of_reports() const { return m_list_of_reports; }

Student::ListOfPracticeResult Student::getlist_of_practice_result() const { return m_list_of_practice_result; }

Student::ListOfPracticeResult & Student::list_of_practice_result() { return m_list_of_practice_result; }

const Student::ListOfPracticeResult & Student::list_of_practice_result() const { return m_list_of_practice_result; }


void Student::setstudent_id(const long & val) { m_Strudent_id = val; }

void Student::setgroup(const Student::Group_ptr & val) { m_group = val; }

void Student::setperson(const Student::Person_ptr & val) { m_person = val; }

void Student::setlist_of_passing_practice(const Student::ListOfPassingPractice & val) { m_list_of_passing_practice = val; }

void Student::seteducation_program(const Student::EducationProgram_ptr & val) { m_education_program = val; }

void Student::setlist_of_reports(const Student::ListOfReport & val) { m_list_of_reports = val; }

void Student::setlist_of_practice_result(const Student::ListOfPracticeResult & val) { m_list_of_practice_result = val; }



Student::Group_ptr Student::getgroup(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getgroup(); }
   QString sRelation = "{Strudent_id} | group";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Student tmp;
   tmp.m_Strudent_id = this->m_Strudent_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_group = tmp.m_group; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_group;
}

Student::Person_ptr Student::getperson(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getperson(); }
   QString sRelation = "{Strudent_id} | person";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Student tmp;
   tmp.m_Strudent_id = this->m_Strudent_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_person = tmp.m_person; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_person;
}

Student::ListOfPassingPractice Student::getlist_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_passing_practice(); }
   QString sRelation = "{Student_id} | list_of_passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Student tmp;
   tmp.m_Strudent_id = this->m_Strudent_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passing_practice = tmp.m_list_of_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passing_practice;
}

Student::ListOfPassingPractice & Student::list_of_passing_practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_passing_practice(); }
   QString sRelation = "{Student_id} | list_of_passing_practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Student tmp;
   tmp.m_Strudent_id = this->m_Strudent_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_passing_practice = tmp.m_list_of_passing_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_passing_practice;
}

Student::EducationProgram_ptr Student::getEducation_program(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return geteducation_program(); }
   QString sRelation = "{Student_id} | Education_program";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Student tmp;
   tmp.m_Strudent_id = this->m_Strudent_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_education_program = tmp.m_education_program; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_education_program;
}

Student::ListOfReport Student::getlist_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_reports(); }
   QString sRelation = "{Student_id} | list_of_reports";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Student tmp;
   tmp.m_Strudent_id = this->m_Strudent_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_reports = tmp.m_list_of_reports; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_reports;
}

Student::ListOfReport & Student::list_of_reports(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_reports(); }
   QString sRelation = "{Student_id} | list_of_reports";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Student tmp;
   tmp.m_Strudent_id = this->m_Strudent_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_reports = tmp.m_list_of_reports; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_reports;
}

Student::ListOfPracticeResult Student::getlist_of_practice_result(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_practice_result(); }
   QString sRelation = "{Student_id} | list_of_practice_result";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Student tmp;
   tmp.m_Strudent_id = this->m_Strudent_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_practice_result = tmp.m_list_of_practice_result; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_practice_result;
}

Student::ListOfPracticeResult & Student::list_of_practice_result(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_practice_result(); }
   QString sRelation = "{Student_id} | list_of_practice_result";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Student tmp;
   tmp.m_Strudent_id = this->m_Strudent_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_practice_result = tmp.m_list_of_practice_result; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_practice_result;
}


