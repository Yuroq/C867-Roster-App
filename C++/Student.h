#pragma once
#include <iostream>
#include <iomanip>
#include "Degree.h"


using std::string;
using std::cout;

class Student
{
public:
  const static int
    numberDaysArraySize = 3;
private:
  string studentID;
  string firstName;
  string lastName;
  string emailAddress;
  int
    age;
  double
    numberDays[numberDaysArraySize];
  DegreeProgram degreeProgram;

public:
  Student ();
  Student (string studentID, string firstName, string lastName,
	   string emailAddress, int age, double numberDays[],
	   DegreeProgram degreeProgram);
  ~Student ();

  string getStudentID ();
  string getFirstName ();
  string getLastName ();
  string getStudentEmail ();
  int getAge ();
  double *
  getCourseLength ();
  DegreeProgram getDegreeProgram ();

  void
  setStudentID (string studentID);
  void
  setFirstName (string firstName);
  void
  setLastName (string lastName);
  void
  setStudentEmail (string emailAddress);
  void
  setAge (int age);
  void
  setCourseLength (double numberDays[]);
  void
  setDegreeProgram (DegreeProgram dp);

  static void
  printHeader ();

  void
  print ();
};
