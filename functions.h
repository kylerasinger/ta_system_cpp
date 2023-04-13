#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "functions.cpp" //<-- TERRIBLE PRACTICE, Currently during exams and don't have the time to fix the linker.
                        //This causes a "copy paste" of all code in the cpp, leading to having to load all its code when not using all functions.

void cleanFile(std::string s);

void addNewTA(std::vector<Ta>& taListPass);

#endif // FUNCTIONS_H_INCLUDED
