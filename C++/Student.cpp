#include "Student.h"
Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName  = "";
        this->emailAddress = "";
    this->age  = 0;
    for (int i = 0; i < numberDaysArraySize; i++) this->numberDays[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double numberDays[], DegreeProgram degreeProgram) {
this->studentID  = studentID;
this->firstName = firstName;
this->lastName = lastName;
this->emailAddress = emailAddress;
this->age = age;
for(int i = 0; i < numberDaysArraySize; i++) this->numberDays[i] = numberDays[i];
this->degreeProgram = degreeProgram;

}

Student::~Student() {}

string Student::getStudentID() {return this->studentID; }
string Student::getFirstName() {return this->firstName; }
string Student::getLastName() {return this->lastName; }
string Student::getStudentEmail() {return this->emailAddress; }
int Student::getAge() {return this->age; }
double* Student::getCourseLength() {return this->numberDays; }
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram; }

void Student::setStudentID(string studentID) {this->studentID = studentID; }
void Student::setFirstName(string firstName) {this->firstName = firstName; }
void Student::setLastName(string studentLastName) {this->lastName = lastName; }
void Student::setStudentEmail(string emailAddress) {this->emailAddress = emailAddress; }
void Student::setAge(int age) {this->age = age; }
void Student::setCourseLength(double numberDays[])
{
    for (int i = 0; i < numberDaysArraySize; i++) this->numberDays[i] = numberDays[i];
}
void Student::setDegreeProgram(DegreeProgram dt) { this->degreeProgram = dt; }

void Student::printHeader()

{
    cout << "StudentID|FirstName|LastName|Email|Age|Course lengths|Program\n";
}

void Student::print() {
    cout << this->getStudentID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getStudentEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << "{" << this->getCourseLength()[0] << "," << this->getCourseLength()[1] << "," << this->getCourseLength()[2]  << "} ";
    cout << studentStrings[this->getDegreeProgram()] << '\n';
}