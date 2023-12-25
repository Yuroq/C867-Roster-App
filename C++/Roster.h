#pragma once
#include "Student.h"
class Roster {
    private: 
    int lastIndex = -1;
    const static int rosterAmount = 5;
    Student* studentRosterArray[rosterAmount];

    public:
    Roster();
    void parse(string row);
    void add(string sID,
    string firstName,
    string lastName,
    string sEmailAddress,
    int sAge,
    double daysInCourse1,
    double daysInCourse2,
    double daysInCourse3,
    DegreeProgram dp
    );
    void printAll();
    void printByDegreeProgram(DegreeProgram dp);
    void printInvalidEmails();
    void printAverageDaysInCourse();
    void removeStudentById(string studentID);
    ~Roster();
    };