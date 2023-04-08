#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Ta.h"

using namespace std;

int main()
{
    cout << "Program Start: \n" << endl;
    vector<Ta>* taList = new vector<Ta>;
    int listSize = 0;

    ifstream taListFile("ta_list.txt");
    ostringstream ss;
    string line;
    int currentLine = 0;

    ostringstream ssDept;
    ostringstream ssStatus;
    ostringstream ssYearHired;
    ostringstream ssStudentId;

    int seperatorCount = 0;

    while(!taListFile.eof()) //iterates through file line by line
    {
        currentLine++;
        getline(taListFile, line);
        ss << line;
        ss << "\n";

        int intYearHired;
        int intStudentId;

        if(currentLine > 1)
        {
            for(int i = 0; i < ss.str().length(); i++){
                if(ss.str()[i] != '\t'){
                    if(seperatorCount == 0){ssDept << ss.str()[i];}
                    if(seperatorCount == 1){ssStatus << ss.str()[i];}
                    if(seperatorCount == 2){ssYearHired << ss.str()[i];}
                    if(seperatorCount == 3){ssStudentId << ss.str()[i];}
                }
                if(ss.str()[i] == '\t'){seperatorCount++;}
            }
            stringstream convert;

            convert << ssYearHired.str();
            convert >> intYearHired;

            convert.str("");
            convert.clear();

            convert << ssStudentId.str();
            convert >> intStudentId;

            Ta tempTa(ssDept.str(), ssStatus.str(), intYearHired, intStudentId);

            taList->push_back(tempTa);
        }
        else if(currentLine == 1) //gets list size
        {
            listSize = stoi(ss.str());
        }
        //cout << ss.str(); //put this as first line in new file

        seperatorCount = 0;


        ss.str("");
        ssDept.str("");
        ssStatus.str("");
        ssYearHired.str("");
        ssStudentId.str("");

    }

    for(int i = 0; i < (*taList).size() ; i++){
        taList+i;
        taList->printInfo();
    }
    //cout << "\noutputs:\n";
    //cout << listSize;

    /*
    Ta firstTa("BCEE", "Alum", 2016, 9886150);
    Ta secondTa("MIAE", "Grad", 2017, 8829755);

    taList->push_back(firstTa);
    taList->push_back(secondTa);

    cout << "vector1 dept: " << (*taList)[0].getDept() << "\n";
    cout << "vector2 dept: " << (*taList)[1].getDept() << "\n";
    */
    return 0;
}
