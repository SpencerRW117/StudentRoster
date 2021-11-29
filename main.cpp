/*
    Spencer Watkins, C867 final project
    A simple class roster managing tool
    Please compile using : g++ -std=c++17 -O3 main.cpp student.cpp roster.cpp
        or simply "make" 
    Please run using : ./a.out
    Vectors and Smart pointers used in place of arrays for added memory safety
    All objectives are completed and commented
*/

#include <vector> //Used in place of normal arrays for memory management and bounds-checking
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;

int main(){
    
    //This is the studentData table with my own credentials added. (Objective A)
    const vector<string> studentData{
         "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
         "A5,Spencer,Watkins,swat304@wgu.edu,26,13,37,42,SOFTWARE"
        };

    //Course title, language, ID, and name (Obejctive F1.) 
    cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
    cout << "|WGU - C867 - Scripting and programming applications|" << endl;
    cout << "|Language used: C++17                               |" << endl;
    cout << "|Student ID: 005887959                              |" << endl;
    cout << "|Name: Spencer Watkins                              |" << endl;
    cout << "|+++++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
    
    //Instance of Roster() called classRoster (Objective F2.)
    Roster classRoster;

    //Adding each student to the roster by parsing the raw csv and adding it (Objective F3.)
    for(auto s: studentData){
        classRoster.parse_and_add(s);
    }

    //Calls to demonstrate program functionality (Objective F4.)
    classRoster.printAll();
    classRoster.printInvalidEmails();
    for(auto c : classRoster.classRosterArray){
        classRoster.printAverageDaysInCourse(c->get_student_ID());
    }
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    //No destructor is necessary because vectors and smart pointers were used throughout (Objective F5.)

    
}