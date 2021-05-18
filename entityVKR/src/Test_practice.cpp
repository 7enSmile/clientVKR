#include "../include/department_precompiled_header.h"

#include "../include/Test_practice.h"
#include "../include/Practice.h"
#include "../include/Employer.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_DEPARTMENT(TestPractice, TestPractice)

namespace qx {

template <>
void register_class(QxClass<TestPractice> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("t_test_practice");

   pData = t.id(& TestPractice::m_TestPractice_id, "test_practice_id", 0);

   pData = t.data(& TestPractice::m_name, "name", 0, true, true);
   pData = t.data(& TestPractice::m_data, "data", 0, true, true);

   pRelation = t.relationManyToOne(& TestPractice::m_practice, "practice", 0);
   pRelation->getDataMember()->setName("practice_id");
   pRelation = t.relationManyToOne(& TestPractice::m_employer, "employer", 0);
   pRelation->getDataMember()->setName("employer_id");

   qx::QxValidatorX<TestPractice> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

TestPractice::TestPractice() : m_TestPractice_id(0) { ; }

TestPractice::TestPractice(const long & id) : m_TestPractice_id(id) { ; }

TestPractice::~TestPractice() { ; }

long TestPractice::getTestPractice_id() const { return m_TestPractice_id; }

QString TestPractice::getname() const { return m_name; }

QByteArray TestPractice::getdata() const { return m_data; }

TestPractice::Practice_ptr TestPractice::getpractice() const { return m_practice; }

TestPractice::Employer_ptr TestPractice::getemployer() const { return m_employer; }

void TestPractice::setTestPractice_id(const long & val) { m_TestPractice_id = val; }

void TestPractice::setname(const QString & val) { m_name = val; }

void TestPractice::setdata(const QByteArray & val) { m_data = val; }

void TestPractice::setpractice(const TestPractice::Practice_ptr & val) { m_practice = val; }

void TestPractice::setemployer(const TestPractice::Employer_ptr & val) { m_employer = val; }

TestPractice::Practice_ptr TestPractice::getpractice(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getpractice(); }
   QString sRelation = "{TestPractice_id} | practice";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   TestPractice tmp;
   tmp.m_TestPractice_id = this->m_TestPractice_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_practice = tmp.m_practice; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_practice;
}

TestPractice::Employer_ptr TestPractice::getemployer(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getemployer(); }
   QString sRelation = "{TestPractice_id} | employer";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   TestPractice tmp;
   tmp.m_TestPractice_id = this->m_TestPractice_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_employer = tmp.m_employer; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_employer;
}
