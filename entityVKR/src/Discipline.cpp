#include "../include/department_precompiled_header.h"

#include "../include/Discipline.h"
#include "../include/Educational_program.h"
#include "../include/Result_education.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Discipline, Discipline)

namespace qx {

template <>
void register_class(QxClass<Discipline> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Discipline");

   pData = t.id(& Discipline::m_Discipline_id, "Discipline_id", 0);

   pData = t.data(& Discipline::m_semester, "semester", 0, true, true);
   pData = t.data(& Discipline::m_name, "name", 0, true, true);
   pData = t.data(& Discipline::m_description, "description", 0, true, true);

   pRelation = t.relationManyToOne(& Discipline::m_educational_program, "educational_program_id", 0);
   pRelation->getDataMember()->setName("Educational_program_id");
   pRelation = t.relationOneToMany(& Discipline::m_list_of_result_educational, "list_of_result_educational", "Discipline_id", 0);

   qx::QxValidatorX<Discipline> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Discipline::Discipline() : m_Discipline_id(0), m_semester(0) { ; }

Discipline::Discipline(const long & id) : m_Discipline_id(id), m_semester(0) { ; }

Discipline::~Discipline() { ; }

long Discipline::getdiscipline_id() const { return m_Discipline_id; }

int Discipline::getsemester() const { return m_semester; }

QString Discipline::getname() const { return m_name; }

QString Discipline::getdescription() const { return m_description; }

Discipline::EducationProgram_ptr Discipline::geteducational_program() const { return m_educational_program; }

Discipline::ListOfResultEducational Discipline::getlist_of_result_educational() const { return m_list_of_result_educational; }

Discipline::ListOfResultEducational & Discipline::list_of_result_educational() { return m_list_of_result_educational; }

const Discipline::ListOfResultEducational & Discipline::list_of_result_educational() const { return m_list_of_result_educational; }

void Discipline::setdiscipline_id(const long & val) { m_Discipline_id = val; }

void Discipline::setsemester(const int & val) { m_semester = val; }

void Discipline::setname(const QString & val) { m_name = val; }

void Discipline::setdescription(const QString & val) { m_description = val; }

void Discipline::seteducational_program(const Discipline::EducationProgram_ptr & val) { m_educational_program = val; }

void Discipline::setlist_of_result_educational(const Discipline::ListOfResultEducational & val) { m_list_of_result_educational = val; }

Discipline::EducationProgram_ptr Discipline::geteducational_program(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return geteducational_program(); }
   QString sRelation = "{Discipline_id} | educational_program";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Discipline tmp;
   tmp.m_Discipline_id = this->m_Discipline_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_educational_program = tmp.m_educational_program; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_educational_program;
}

Discipline::ListOfResultEducational Discipline::getlist_of_result_educational(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_result_educational(); }
   QString sRelation = "{Discipline_id} | list_of_result_educational";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Discipline tmp;
   tmp.m_Discipline_id = this->m_Discipline_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_result_educational = tmp.m_list_of_result_educational; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_result_educational;
}

Discipline::ListOfResultEducational & Discipline::list_of_result_educational(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_result_educational(); }
   QString sRelation = "{Discipline_id} | list_of_result_educational";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Discipline tmp;
   tmp.m_Discipline_id = this->m_Discipline_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_result_educational = tmp.m_list_of_result_educational; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_result_educational;
}
