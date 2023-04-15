#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <climits>
#include "Ta.h"

void addNewTA(std::vector<Ta>& taList){
    char input;
    std::cout << "\nWould you like to add a new TA? (y/n): ";
    std::cin >> input;
    if(input == 'y'){
        std::string inputDept, inputStatus;
        int inputYearHired, inputStudentId;

        std::cout << "Enter TA info (dept, status, yearHired, studentId): ";

        try{
            std::cin >> inputDept >> inputStatus >> inputYearHired >> inputStudentId;
            if(std::cin.fail()){
                throw std::runtime_error("Wrong input, enter an integer.");
            }
        }catch(std::runtime_error& error){
            std::cout << error.what();
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            addNewTA(taList);
            return;
        }

        for(int i = 0; i < taList.size(); i++){
            if(taList[i].getStudentId() == inputStudentId){
                std::cout << "Invalid student id: already in file.\n";
                addNewTA(taList);
                return;
            }
        }

        Ta newTa(inputDept, inputStatus, inputYearHired, inputStudentId);
        std::cout << "New TA Added: ";
        newTa.printInfo();

        taList.push_back(newTa);

        addNewTA(taList);
    }
}

void orderList(std::vector<Ta>& taList){
    std::string choice;
    std::cout << "\nWould you like to reorder the list? (y/n): ";
    std::cin >> choice;
    if(choice == "y"){
        int orderChoice, orderDir;

        std::cout << "\nParameters to order by: \n";
        std::cout << "\t1. Department\n\t2. Status\n\t3. Year Hired\n\t4. Student Id\n";
        std::cout << "Enter Selection: ";
        try{
            std::cin >> orderChoice;
            if(std::cin.fail()){
                throw std::runtime_error("Wrong input, enter an integer. ");
            }
        }catch(std::runtime_error& error){
            std::cout << error.what();
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            orderList(taList);
            return;
        }

        std::cout << "\nOrder options: \n";
        std::cout << "\t1. Ascending\n\t2. Descending\n";
        std::cout << "Enter Selection: ";
        try{
            std::cin >> orderDir;
            if(std::cin.fail()){
                throw std::runtime_error("Wrong input, enter an integer. ");
            }
        }catch(std::runtime_error& error){
            std::cout << error.what();
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            orderList(taList);
            return;
        }

        switch(orderChoice){ //switch tree for options listed above
            case 1:{
                switch(orderDir){
                    case 1:
                        sort(taList.begin(), taList.end(), [](Ta& a, Ta& b){
                            return a.getDept() < b.getDept();
                        });
                        break;
                    case 2:
                        sort(taList.begin(), taList.end(), [](Ta& a, Ta& b){
                             return a.getDept() > b.getDept();
                        });
                        break;
                break;
                }
            }
            case 2:{
                switch(orderDir){
                    case 1:
                        sort(taList.begin(), taList.end(), [](Ta& a, Ta& b){
                             return a.getStatus() < b.getStatus();
                        });
                        break;
                    case 2:
                        sort(taList.begin(), taList.end(), [](Ta& a, Ta& b){
                             return a.getStatus() > b.getStatus();
                        });
                        break;
                break;
                }
            }
            case 3:{
                switch(orderDir){
                    case 1:
                        sort(taList.begin(), taList.end(), [](Ta& a, Ta& b){
                             return a.getYearHired() < b.getYearHired();
                        });
                        break;
                    case 2:
                        sort(taList.begin(), taList.end(), [](Ta& a, Ta& b){
                             return a.getYearHired() > b.getYearHired();
                        });
                        break;
                break;
                }
            }
            case 4:{
                switch(orderDir){
                    case 1:
                        sort(taList.begin(), taList.end(), [](Ta& a, Ta& b){
                             return a.getStudentId() < b.getStudentId();
                        });
                        break;
                    case 2:
                        sort(taList.begin(), taList.end(), [](Ta& a, Ta& b){
                             return a.getStudentId() > b.getStudentId();
                        });
                        break;
                break;
                }
            }
        }
    }else{return;};
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

    std::cout << "taListClean.size(): " << taListClean.size();

    orderList(taListClean);

    for(int i = 0; i < taListClean.size(); i++){
        taListClean[i].printInfo();
    }

    ofstream taListFileOW("ta_list.txt");
    ostringstream outputss;

    outputss << taListClean.size();

    for(int i = 0; i < taListClean.size(); i++){
        outputss << taListClean[i].getInfoString();
    }

    taListFileOW << outputss.str();

    taListFileOW.close();

}


