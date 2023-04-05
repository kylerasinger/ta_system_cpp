#include "Ta.h"

Ta::Ta()
{
    //ctor
}

Ta::~Ta()
{
    //dtor
}

Ta::Ta(std::string deptS, std::string statusS, int yearN, int idN)
{
    dept = deptS;
    status = statusS;
    yearHired = yearN;
    studentId = idN;
}

std::string Ta::getDept(){return dept;}
