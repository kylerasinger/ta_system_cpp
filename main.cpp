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

    ifstream taListFile("ta_list.txt");
    ostringstream ss;
    string line;
    int currentLine = 0;

    while(!taListFile.eof())
    {
        currentLine++;
        getline(taListFile, line);
        ss << line;
        ss << "\n";
    }
    cout << ss.str();


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
