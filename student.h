#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "degree.h"

using namespace std;
class Student{
    private:
        string student_ID = "";
        string first_name;
        string last_name;
        string email_address;
        int age;
        vector<int> num_days;
        DegreeProgram degree;

    public:
        //Constructor
        Student(string new_ID, string new_first_name, string new_last_name, string new_email_address,
                int new_age, vector<int> new_num_days, DegreeProgram new_degree);

        //Destructor

        //Getter Stubs
        string get_student_ID();
        string get_first_name();
        string get_last_name();
        string get_email_address();
        int get_age();
        vector<int> get_num_days();
        void print_student();
        DegreeProgram get_degree();

        //Setter Stubs
        void set_student_ID(string set_ID);
        void set_first_name(string set_first);
        void set_last_name(string set_last);
        void set_email_address(string set_email);
        void set_age(int age_set);
        void set_num_days(vector<int> set_days);
        void set_degree_program(DegreeProgram set_degree);
};

#endif /* STUDENT_H */