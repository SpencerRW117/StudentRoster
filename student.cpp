#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


//This is both the default and custom constructor 
Student::Student(string new_ID = "", 
                 string new_first_name = "", 
                 string new_last_name = "",
                 string new_email_address = "",
                 int new_age = 0,
                 vector<int> new_num_days = {}, 
                 DegreeProgram new_degree = INVALID){

    
    student_ID = new_ID;
    first_name = new_first_name;
    last_name = new_last_name;
    email_address = new_email_address;
    age = new_age;
    num_days = new_num_days;
    degree = new_degree;

}

//Print function helpers
void print_days(vector<int> days){
    int size = days.size();
    for (int i = 0; i < size; i++){
        if(i == days.size()-1){
            cout << days.at(i);
            break;
        }
        else    
            cout << days.at(i) << ", ";
    } 
}
string degree_to_string(DegreeProgram deg){
    if(deg == SECURITY){
        return "SECURITY";
    }
    else if (deg == NETWORK){
        return "NETWORK";
    }
    else if (deg == SOFTWARE){
        return "SOFTWARE";
    }
    else{ 
        return "INVALID";
    }

}

//Single Student print function
void Student::print_student(){
    cout << student_ID << " \t First Name: " << first_name
                       << " \t Last Name: "  << last_name
                       << " \t Age: " << age
                       << " \t daysInCourse: {";
                       print_days(num_days);
                       cout << "}"
                       << " \t Degree Program: " << degree_to_string(get_degree())
                       << endl;

}

//Getter Definitions 
string Student::get_student_ID(){
    return student_ID;
}
string Student::get_first_name(){
    return first_name;
}
string Student::get_last_name(){
    return last_name;
}
string Student::get_email_address(){
    return email_address;
}
int Student::get_age(){
    return age;
}
vector<int> Student::get_num_days(){
    return num_days;
}
DegreeProgram Student::get_degree(){
    return degree;
}

//Setter Definitions 
void Student::set_student_ID(string set_ID){
    student_ID = set_ID; 
}
void Student::set_first_name(string set_first){
    first_name = set_first;
}
void Student::set_last_name(string set_last){
    last_name = set_last;
}
void Student::set_email_address(string set_email){
    email_address = set_email;
}
void Student::set_age(int age_set){
    age = age_set;
}
void Student::set_num_days(vector<int> set_days){
    num_days = set_days;
}
void Student::set_degree_program(DegreeProgram set_degree){
    degree = set_degree;
}
