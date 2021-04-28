#ifndef ABSTACTSUBCLASSMODEL_H
#define ABSTACTSUBCLASSMODEL_H
#include "Test_practice.h"

class AbstactSubClassModel
{
public:
    AbstactSubClassModel();
    void deleteTestPractice(TestPractice_ptr);
    void deleteReport(Report_ptr);
};

#endif // ABSTACTSUBCLASSMODEL_H
