#include "../include/department_precompiled_header.h"

#include "../include/Result_education.h"
#include "../include/Educational_program.h"
#include "../include/Discipline.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(ResultEducation, ResultEducation)

namespace qx {

template <>
void register_class(QxClass<ResultEducation> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Result_discipline");

   pData = t.id(& ResultEducation::m_Result_discipline_id, "Result_discipline_id", 0);

   pData = t.data(& ResultEducation::m_description, "description", 0, true, true);
   pData = t.data(& ResultEducation::m_acquired_skills, "acquired_skills", 0, true, true);

   pRelation = t.relationManyToOne(& ResultEducation::m_educational_program, "educational_program_id", 0);
   pRelation->getDataMember()->setName("Educational_program_id");
   pRelation = t.relationManyToOne(& ResultEducation::m_discipline, "Discipline_id", 0);
   pRelation->getDataMember()->setName("Discipline_id");
   pRelation = t.relationManyToMany(& ResultEducation::m_list_of_employer, "list_of_employer", "t_qxee_employer_Result_education", "Result_discipline_id", "Employer_id", 0);

   qx::QxValidatorX<ResultEducation> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

ResultEducation::ResultEducation() : m_Result_discipline_id(0) { ; }

ResultEducation::ResultEducation(const long & id) : m_Result_discipline_id(id) { ; }

ResultEducation::~ResultEducation() { ; }

long ResultEducation::getResult_discipline_id() const { return m_Result_discipline_id; }

QString ResultEducation::getdescription() const { return m_description; }

QString ResultEducation::getacquired_skills() const { return m_acquired_skills; }

ResultEducation::EducationProgram_ptr ResultEducation::geteducational_program() const { return m_educational_program; }

ResultEducation::Discipline_ptr ResultEducation::getdiscipline() const { return m_discipline; }

ResultEducation::ListOfEmployer ResultEducation::getlist_of_employer() const { return m_list_of_employer; }

ResultEducation::ListOfEmployer & ResultEducation::list_of_employer() { return m_list_of_employer; }

const ResultEducation::ListOfEmployer & ResultEducation::list_of_employer() const { return m_list_of_employer; }


void ResultEducation::setResult_discipline_id(const long & val) { m_Result_discipline_id = val; }

void ResultEducation::setdescription(const QString & val) { m_description = val; }

void ResultEducation::setacquired_skills(const QString & val) { m_acquired_skills = val; }

void ResultEducation::seteducational_program(const ResultEducation::EducationProgram_ptr & val) { m_educational_program = val; }

void ResultEducation::setdiscipline(const ResultEducation::Discipline_ptr & val) { m_discipline = val; }

void ResultEducation::setlist_of_employer(const ResultEducation::ListOfEmployer & val) { m_list_of_employer = val; }

ResultEducation::EducationProgram_ptr ResultEducation::geteducational_program(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return geteducational_program(); }
   QString sRelation = "{Result_discipline_id} | educational_program";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   ResultEducation tmp;
   tmp.m_Result_discipline_id = this->m_Result_discipline_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_educational_program = tmp.m_educational_program; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_educational_program;
}

ResultEducation::Discipline_ptr ResultEducation::getdiscipline(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getdiscipline(); }
   QString sRelation = "{Result_discipline_id} | discipline";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   ResultEducation tmp;
   tmp.m_Result_discipline_id = this->m_Result_discipline_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_discipline = tmp.m_discipline; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_discipline;
}

ResultEducation::ListOfEmployer ResultEducation::getlist_of_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_employer(); }
   QString sRelation = "{Result_discipline_id} | list_of_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   ResultEducation tmp;
   tmp.m_Result_discipline_id = this->m_Result_discipline_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_employer = tmp.m_list_of_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_employer;
}

ResultEducation::ListOfEmployer & ResultEducation::list_of_employer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_employer(); }
   QString sRelation = "{Result_discipline_id} | list_of_employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   ResultEducation tmp;
   tmp.m_Result_discipline_id = this->m_Result_discipline_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_employer = tmp.m_list_of_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_employer;
}
