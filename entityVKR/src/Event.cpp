#include "../include/department_precompiled_header.h"

#include "../include/Event.h"
#include "../include/Employer.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(Events, Events)

namespace qx {

template <>
void register_class(QxClass<Events> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_Event");

   pData = t.id(& Events::m_events_id, "Event_id", 0);

   pData = t.data(& Events::m_name, "name", 0, true, true);
   pData = t.data(& Events::m_description, "description", 0, true, true);
   pData = t.data(& Events::m_begin, "begin", 0, true, true);
   pData = t.data(& Events::m_ending, "ending", 0, true, true);

   pRelation = t.relationManyToOne(& Events::m_employer, "employer", 0);

   qx::QxValidatorX<Events> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

Events::Events() : m_events_id(0) { ; }

Events::Events(const long & id) : m_events_id(id) { ; }

Events::~Events() { ; }

long Events::getevents_id() const { return m_events_id; }

QString Events::getname() const { return m_name; }

QString Events::getdescription() const { return m_description; }

QDate Events::getbegin() const { return m_begin; }

QDate Events::getending() const { return m_ending; }

Events::Employer_ptr Events::getemployer() const { return m_employer; }

void Events::setevents_id(const long & val) { m_events_id = val; }

void Events::setname(const QString & val) { m_name = val; }

void Events::setdescription(const QString & val) { m_description = val; }

void Events::setbegin(const QDate & val) { m_begin = val; }

void Events::setending(const QDate & val) { m_ending = val; }

void Events::setemployer(const Events::Employer_ptr & val) { m_employer = val; }

Events::Employer_ptr Events::getemployer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getemployer(); }
   QString sRelation = "{Events_id} | employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   Events tmp;
   tmp.m_events_id = this->m_events_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_employer = tmp.m_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_employer;
}
