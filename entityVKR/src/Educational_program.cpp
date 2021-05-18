#include "../include/department_precompiled_header.h"

#include "../include/Educational_program.h"
#include "../include/Result_education.h"
#include "../include/Discipline.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(EducationalProgram, EducationalProgram)

namespace qx {

template <>
void register_class(QxClass<EducationalProgram> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_educational_program");

   pData = t.id(& EducationalProgram::m_educational_program_id, "educational_program_id", 0);

   pData = t.data(& EducationalProgram::m_name, "name", 0, true, true);
   pData = t.data(& EducationalProgram::m_description, "description", 0, true, true);
   pData = t.data(& EducationalProgram::m_field, "field", 0, true, true);
   pData = t.data(& EducationalProgram::m_focus, "focus", 0, true, true);

   pRelation = t.relationOneToMany(& EducationalProgram::m_list_of_result_education, "list_of_result_education", "educational_program_id", 0);
   pRelation = t.relationOneToMany(& EducationalProgram::m_list_of_discipline, "list_of_discipline", "educational_program_id", 0);
   pRelation = t.relationOneToMany(& EducationalProgram::m_list_of_practice, "list_of_Practice", "Education_program", 0);
   pRelation = t.relationOneToMany(& EducationalProgram::m_list_of_student, "list_of_Student", "Education_program", 0);

   qx::QxValidatorX<EducationalProgram> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

EducationalProgram::EducationalProgram() : m_educational_program_id(0) { ; }

EducationalProgram::EducationalProgram(const long & id) : m_educational_program_id(id) { ; }

EducationalProgram::~EducationalProgram() { ; }

long EducationalProgram::geteducational_program_id() const { return m_educational_program_id; }

QString EducationalProgram::getname() const { return m_name; }

QString EducationalProgram::getdescription() const { return m_description; }

QString EducationalProgram::getfield() const { return m_field; }

QString EducationalProgram::getfocus() const { return m_focus; }

EducationalProgram::ListOfResultEducation EducationalProgram::getlist_of_result_education() const { return m_list_of_result_education; }

EducationalProgram::ListOfResultEducation & EducationalProgram::list_of_result_education() { return m_list_of_result_education; }

const EducationalProgram::ListOfResultEducation & EducationalProgram::list_of_result_education() const { return m_list_of_result_education; }

EducationalProgram::ListOfDiscipline EducationalProgram::getlist_of_discipline() const { return m_list_of_discipline; }

EducationalProgram::ListOfDiscipline & EducationalProgram::list_of_discipline() { return m_list_of_discipline; }

const EducationalProgram::ListOfDiscipline & EducationalProgram::list_of_discipline() const { return m_list_of_discipline; }

EducationalProgram::ListOfPractice EducationalProgram::getlist_of_Practice() const { return m_list_of_practice; }

EducationalProgram::ListOfPractice & EducationalProgram::list_of_Practice() { return m_list_of_practice; }

const EducationalProgram::ListOfPractice & EducationalProgram::list_of_Practice() const { return m_list_of_practice; }

EducationalProgram::ListOfStudent EducationalProgram::getlist_of_Student() const { return m_list_of_student; }

EducationalProgram::ListOfStudent & EducationalProgram::list_of_Student() { return m_list_of_student; }

const EducationalProgram::ListOfStudent & EducationalProgram::list_of_Student() const { return m_list_of_student; }


void EducationalProgram::seteducational_program_id(const long & val) { m_educational_program_id = val; }

void EducationalProgram::setname(const QString & val) { m_name = val; }

void EducationalProgram::setdescription(const QString & val) { m_description = val; }

void EducationalProgram::setfield(const QString & val) { m_field = val; }

void EducationalProgram::setfocus(const QString & val) { m_focus = val; }

void EducationalProgram::setlist_of_result_education(const EducationalProgram::ListOfResultEducation & val) { m_list_of_result_education = val; }

void EducationalProgram::setlist_of_discipline(const EducationalProgram::ListOfDiscipline & val) { m_list_of_discipline = val; }

void EducationalProgram::setlist_of_Practice(const EducationalProgram::ListOfPractice & val) { m_list_of_practice = val; }

void EducationalProgram::setlist_of_Student(const EducationalProgram::ListOfStudent & val) { m_list_of_student = val; }


EducationalProgram::ListOfResultEducation EducationalProgram::getlist_of_result_education(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_result_education(); }
   QString sRelation = "{educational_program_id} | list_of_result_education";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   EducationalProgram tmp;
   tmp.m_educational_program_id = this->m_educational_program_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_result_education = tmp.m_list_of_result_education; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_result_education;
}

EducationalProgram::ListOfResultEducation & EducationalProgram::list_of_result_education(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_result_education(); }
   QString sRelation = "{educational_program_id} | list_of_result_education";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   EducationalProgram tmp;
   tmp.m_educational_program_id = this->m_educational_program_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_result_education = tmp.m_list_of_result_education; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_result_education;
}

EducationalProgram::ListOfDiscipline EducationalProgram::getlist_of_discipline(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_discipline(); }
   QString sRelation = "{educational_program_id} | list_of_discipline";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   EducationalProgram tmp;
   tmp.m_educational_program_id = this->m_educational_program_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_discipline = tmp.m_list_of_discipline; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_discipline;
}

EducationalProgram::ListOfDiscipline & EducationalProgram::list_of_discipline(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_discipline(); }
   QString sRelation = "{educational_program_id} | list_of_discipline";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   EducationalProgram tmp;
   tmp.m_educational_program_id = this->m_educational_program_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_discipline = tmp.m_list_of_discipline; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_discipline;
}

EducationalProgram::ListOfPractice EducationalProgram::getlist_of_Practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_Practice(); }
   QString sRelation = "{educational_program_id} | list_of_Practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   EducationalProgram tmp;
   tmp.m_educational_program_id = this->m_educational_program_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_practice = tmp.m_list_of_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_practice;
}

EducationalProgram::ListOfPractice & EducationalProgram::list_of_Practice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_Practice(); }
   QString sRelation = "{educational_program_id} | list_of_Practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   EducationalProgram tmp;
   tmp.m_educational_program_id = this->m_educational_program_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_practice = tmp.m_list_of_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_practice;
}

EducationalProgram::ListOfStudent EducationalProgram::getlist_of_Student(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_Student(); }
   QString sRelation = "{educational_program_id} | list_of_Student";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   EducationalProgram tmp;
   tmp.m_educational_program_id = this->m_educational_program_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_student = tmp.m_list_of_student; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_student;
}

EducationalProgram::ListOfStudent & EducationalProgram::list_of_Student(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_Student(); }
   QString sRelation = "{educational_program_id} | list_of_Student";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   EducationalProgram tmp;
   tmp.m_educational_program_id = this->m_educational_program_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_student = tmp.m_list_of_student; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_student;
}
