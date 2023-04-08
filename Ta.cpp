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

void Ta::printInfo()
{
    std::cout << "print info: " <<dept << " " << status << " " << yearHired << " " << studentId << "\n";
}

std::string Ta::getDept(){return dept;}
std::string Ta::getStatus(){return status;}
int Ta::getYearHired(){return yearHired;}
int Ta::getStudentId(){return studentId;}

void Ta::setDept(std::string s){dept = s;}
void Ta::setStatus(std::string s){status = s;}
void Ta::setYearHired(int n){yearHired = n;}
void Ta::setStudentId(int n){studentId = n;}
