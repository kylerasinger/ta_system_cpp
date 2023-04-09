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
    //vector<Ta>* taList = new vector<Ta>;
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

    cout << "\nCleaning Data... (removing alums)\n" << endl;

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




    /*
    int alumCount = 0;
    int alumLocations[] = {};
    for(int i = 0; i < taList.size(); i++){
        if(taList[i].isAlum() == true){
            taList.erase(taList.begin()+i-alumCount);
            alumCount++;
        }
    }

    for(int i = 0; i < taList.size(); i++){ //shows that the vector is good
        taList[i].printInfo();
    }

    /*

    int alumCount = 0;

    /*
    for(int i = 0; i < (*taList).size()-1; i++){
        //cout << i << '\n';
        (*taList)[i].printInfo();
        /*
        if((*taList)[i].isAlum() == true){
            cout << "Alum found at " << i << "\n";
            (*taList).erase((*taList).begin()+i);
            alumCount++;
        }
    }

    cout << "\n Alum Count: " << alumCount << "\n";

    cout << "AFTER:\n";
    cout << taList.size();
    for(int i = 0; i < taList.size(); i++){
        cout << "[" << i << "] ";
        taList[i].printInfo();
    }

    //cout << "\noutputs:\n";
    //cout << listSize;
    */
    return 0;
}
