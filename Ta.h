#ifndef TA_H
#define TA_H

#include <iostream>

class Ta
{
    public:
        Ta();
        virtual ~Ta();
        Ta(std::string deptS, std::string statusS, int yearN, int idN);

        void printInfo();
        bool isAlum();

        std::string getDept();
        std::string getStatus();
        int getYearHired();
        int getStudentId();
        void setDept(std::string s);
        void setStatus(std::string s);
        void setYearHired(int n);
        void setStudentId(int n);

    protected:

    private:
        std::string dept;
        std::string status;
        int yearHired;
        int studentId;
};

#endif // TA_H
