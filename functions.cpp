#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Ta.h"

void addNewTA(std::vector<Ta>& taListPass){
    char input;
    std::cout << "Would you like to add a new TA? (y/n): ";
    std::cin >> input;
    if(input == 'y'){
        std::string inputDept;
        std::string inputStatus;
        int inputYearHired;
        int inputStudentId;

        std::cout << "Enter department: ";
        std::cin >> inputDept;
        std::cout << "Enter status: ";
        std::cin >> inputStatus;
        std::cout << "Enter year hired: ";
        std::cin >> inputYearHired;
        std::cout << "Enter student id: ";
        std::cin >> inputStudentId;

        Ta newTa(inputDept, inputStatus, inputYearHired, inputStudentId);
        std::cout << "New TA info: ";
        newTa.printInfo();

        taListPass.push_back(newTa);
    }
}

void cleanFile(std::string s){
    using namespace std;

    vector<Ta> taList;
    int listSize = 0;

    ifstream taListFile("ta_list.txt");
    ostringstream ss;
    string line = "";
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

        int intYearHired = 5555;
        int intStudentId = 5555;

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

            taList.push_back(tempTa);
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

    taListFile.close();


    for(int i = 0; i < taList.size(); i++){ //shows that the vector is good
        taList[i].printInfo();
    }

    cout << "\nCleaning Data... (removing alums/adding ta's)\n" << endl;

    int taListSize = taList.size();
    int alumCount = 0;
    bool alumLocations[taListSize];

    vector<Ta> taListClean;

    for(int i = 0; i < taListSize; i++){
        if(!taList[i].isAlum()){taListClean.push_back(taList[i]);}
    }

    for(int i = 0; i < taListClean.size(); i++){
        taListClean[i].printInfo();
    }

    addNewTA(taListClean);

    ofstream taListFileOW("ta_list.txt");
    ostringstream outputss;

    outputss << taListClean.size();

    for(int i = 0; i < taListClean.size(); i++){
        outputss << taListClean[i].getInfoString();
    }

    taListFileOW << outputss.str();

    taListFileOW.close();

}


