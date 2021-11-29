#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <memory>
#include <string>
#include "student.h"

using namespace std;

class Roster{

    public:
        //Using C++ Smart pointers to take care of memory deallocation automatically
        vector<shared_ptr<Student>> classRosterArray;
        Roster();
        void parse_and_add(const string raw);
        void add(string rosterID, string rosterFirst, string rosterLast, string rosterEmail,
            int rosterAge, int daysInCourse1, int daysInCourse2, 
            int daysInCourse3, DegreeProgram rosterDegree);
        void remove(string rosterID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram selectDegree);
};

#endif /* ROSTER_H */