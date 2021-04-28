#include "model/abstactsubclassmodel.h"

AbstactSubClassModel::AbstactSubClassModel()
{

}

void AbstactSubClassModel::deleteTestPractice(TestPractice_ptr testpractice)
{
    qx::dao::delete_by_id(testpractice);

}

void AbstactSubClassModel::deleteReport(Report_ptr report)
{
    qx::dao::delete_by_id(report);

}
