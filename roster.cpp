#include "roster.h"
#include "student.h"
#include "degree.h"

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>

using namespace std;

DegreeProgram string_to_degree(string deg){
    if(deg == "SECURITY"){
        return SECURITY;
    }
    else if (deg == "NETWORK"){
        return NETWORK;
    }
    else if (deg == "SOFTWARE"){
        return SOFTWARE;
    }
    else{ 
        return INVALID;
    }

}


Roster::Roster(){
    vector<shared_ptr<Student>> classRosterArray = {};
}

void Roster::parse_and_add(const string raw){
    vector<string> inputs;
    stringstream iss(raw);
    while(iss.good()){
        string temp;
        getline(iss, temp, ',');
        inputs.push_back(temp);
    }
    add(
        inputs.at(0),
        inputs.at(1),
        inputs.at(2),
        inputs.at(3),
        stoi(inputs.at(4)),
        stoi(inputs.at(5)),
        stoi(inputs.at(6)),
        stoi(inputs.at(7)),
        string_to_degree(inputs.at(8))
    );
}

void Roster::add(string rosterID, string rosterFirst, string rosterLast, string rosterEmail,
        int rosterAge, int daysInCourse1, int daysInCourse2, 
        int daysInCourse3, DegreeProgram rosterDegree){
            vector<int> days = {daysInCourse1, daysInCourse2, daysInCourse3};
            Student S = {rosterID, rosterFirst, rosterLast, rosterEmail, rosterAge,
                         days, rosterDegree};
            auto S_ptr = make_shared<Student>(S); 
            classRosterArray.push_back(S_ptr);
        }

void Roster::remove(string rosterID){
    for(int i = 0; i < classRosterArray.size(); i++){
        if(classRosterArray.at(i)->get_student_ID() == rosterID){
            classRosterArray.erase(classRosterArray.begin() + i);
            return;
        }
    }
    cout << "ERROR: STUDENT ID " << rosterID << " NOT FOUND." << endl;  
}

void Roster::printAverageDaysInCourse(string rosterID){
    for(int i = 0; i < classRosterArray.size(); i++){
        if(classRosterArray.at(i)->get_student_ID() == rosterID){
            vector<int> days = classRosterArray.at(i)->get_num_days();
            int sum = 0;
            int n = days.size();
            for(auto x : days){
                sum += x;
            }
            cout << "AVERAGE DAYS IN COURSE FOR STUDENT " << rosterID << ": " << (sum/n) << endl;
            return;
        }
    }
    cout << "ERROR: STUDENT ID " << rosterID << " NOT FOUND." << endl;
}

void Roster::printInvalidEmails(){
    vector<string> emails_to_print;
    for(auto S : classRosterArray){
        string email = S-> get_email_address();
        if(email.find('@') == string::npos or email.find('.') == string::npos 
           or email.find(' ') != string::npos){
            emails_to_print.push_back(email);
        }
    }

    cout << "INVALID EMAILS: " << endl;
    for(auto e : emails_to_print){
        cout << e << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram deg){
    string s = "";
    if(deg == SECURITY) s = "SECURITY";
    else if (deg == NETWORK) s = "NETWORK";
    else if (deg == SOFTWARE) s = "SOFTWARE";
    else s = "INVALID";
    cout << "All students in the " << s << " program." << endl;
    for(auto S : classRosterArray){
        if(S->get_degree() == deg){
            S->print_student();
        }
    }
}

void Roster::printAll(){
    cout << "PRINTING ALL STUDENTS:" << endl; 
    for(auto S : classRosterArray){
        S->print_student();
    }
}