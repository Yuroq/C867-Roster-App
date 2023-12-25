#include "Roster.h"
#include "Roster.cpp"
#include "Student.cpp"
#include "Student.h"
int main() {
    cout << "C867-Scripting & Programming: Applications" << std::endl;
    cout << "Language: C++" << std::endl;
    cout << "Student ID: 011318624" << std::endl;
    cout << "Name: Jamal Kayed" << std::endl;
    
    const string classRoster[] = 
    {
         "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
         "A5,Jamal,Kayed,jkayed@wgu.edu,19, 10,7,13,SOFTWARE", 
    };

    const int rosterAmount = 5;
    Roster roster;
    for(int i = 0; i < rosterAmount; i++) roster.parse(classRoster[i]);
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;

    for(int i = 0; i < 3; i++) {
        if (studentStrings[i] == "SOFTWARE")  { cout << "Displaying by program type: " << studentStrings[i] << std::endl;
        roster.printByDegreeProgram(SOFTWARE);
        }
    }

    cout << "Displaying students with an invalid email: " << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;

    cout<<"Displaying average days to complete courses for each student: " << std::endl;
   roster.printAverageDaysInCourse();

    cout << "Remove student with id: A3" << std::endl;
   roster.removeStudentById("A3");
    cout << std::endl;
    return 0;
}


