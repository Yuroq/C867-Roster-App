#include "Roster.h"


void
Roster::parse (string classRoster)
{
  DegreeProgram dp = SECURITY;

  int rhs = classRoster.find (",");
  string sID = classRoster.substr (0, rhs);

  int lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);
  string fn = classRoster.substr (lhs, rhs - lhs);

  lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);
  string ln = classRoster.substr (lhs, rhs - lhs);

  lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);
  string ea = classRoster.substr (lhs, rhs - lhs);

  lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);
  int ag = stod (classRoster.substr (lhs, rhs - lhs));

  lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);
  double course1 = stod (classRoster.substr (lhs, rhs - lhs));

  lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);
  double course2 = stod (classRoster.substr (lhs, rhs - lhs));

  lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);
  double course3 = stod (classRoster.substr (lhs, rhs - lhs));

  lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);
  string test3 = classRoster.substr (lhs, rhs - lhs);

  if (test3.at (0) == 'S' && test3.at (1) == 'E')
    dp = SECURITY;
  else if (test3.at (0) == 'N')
    dp = NETWORK;
  else if (test3.at (0) == 'S' && test3.at (1) == 'O')
    dp = SOFTWARE;



  lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);

  lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);
  double p2 = 3.0;
  lhs = rhs + 1;
  rhs = classRoster.find (",", lhs);


  add (sID, fn, ln, ea, ag, course1, course2, course3, dp);

}
Roster::Roster() {
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Christopher,Niles,cniles7@wgu.edu,38,30,35,40,SOFTWARE" 
	};
}
void
Roster::add (string studentID, string firstName,
	     string lastName, string emailAddress, int age,
	     double courseLength1, double courseLength2, double courseLength3,
	     DegreeProgram dp)
{
  double parr[3] = { courseLength1, courseLength2, courseLength3 };

  studentRosterArray[++lastIndex] =
    new Student (studentID, firstName, lastName, emailAddress,
		 age, parr, dp);
}

void
Roster::printAll ()
{
  Student::printHeader ();
  for (int i = 0; i <= Roster::lastIndex; i++)
    {
      cout << studentRosterArray[i]->getStudentID ();
      cout << '\t';
      cout << studentRosterArray[i]->getFirstName ();
      cout << '\t';
      cout << studentRosterArray[i]->getLastName ();
      cout << '\t';
      cout << studentRosterArray[i]->getStudentEmail ();
      cout << '\t';
      cout << studentRosterArray[i]->getAge ();
      cout << '\t';
      cout << "{" << studentRosterArray[i]->getCourseLength ()[0] << "," << studentRosterArray[i]->getCourseLength ()[1] << "," << studentRosterArray[i]->getCourseLength ()[2] << "}";
      cout << '\t';
      cout << studentStrings[studentRosterArray[i]->
			     getDegreeProgram ()] << std::endl;
    }
}

void
Roster::printByDegreeProgram (DegreeProgram dp)
{
  Student::printHeader ();
  for (int i = 0; i <= Roster::lastIndex; i++)
    {
      if (Roster::studentRosterArray[i]->getDegreeProgram () == dp)
	studentRosterArray[i]->print ();
    }
  cout << std::endl;
}

void
Roster::printInvalidEmails ()
{
  for (int i = 0; i <= Roster::lastIndex; i++)
    {
      string sEmailAddress = studentRosterArray[i]->getStudentEmail ();

      if (sEmailAddress.find ("@") == string::npos
	  || sEmailAddress.find (".") == string::npos
	  || sEmailAddress.find (" ") != string::npos)
	{

	  cout << sEmailAddress << std::endl;
	}
    }
}

void
Roster::printAverageDaysInCourse ()
{
  for (int i = 0; i <= Roster::lastIndex; i++)
    {
      cout << studentRosterArray[i]->getStudentID () << ": ";
      cout << (studentRosterArray[i]->getCourseLength ()[0]
	       + studentRosterArray[i]->getCourseLength ()[1]
	       +
	       studentRosterArray[i]->getCourseLength ()[2]) /
	3.0 << std::endl;

    }
  cout << std::endl;

}

void
Roster::removeStudentById (string studentID)
{
  bool success = false;
  for (int i = 0; i <= Roster::lastIndex; i++)
    {
      if (studentRosterArray[i]->getStudentID () == studentID)
	{
	  success = true;
	  if (i < rosterAmount - 1)
	    {
	      Student *temp = studentRosterArray[i];
	      studentRosterArray[i] = studentRosterArray[rosterAmount - 1];
	      studentRosterArray[rosterAmount - 1] = temp;
	    }
	  Roster::lastIndex--;
	}
    }
  if (success)
    {
      cout << studentID << " removed from roster." << std::endl << std::endl;
      for (int i = 0; i <= Roster::lastIndex; i++)
	{
	  cout << studentRosterArray[i]->getStudentID ();
	  cout << '\t';
	  cout << studentRosterArray[i]->getFirstName ();
	  cout << '\t';
	  cout << studentRosterArray[i]->getLastName ();
	  cout << '\t';
	  cout << studentRosterArray[i]->getStudentEmail ();
	  cout << '\t';
	  cout << studentRosterArray[i]->getAge ();
	  cout << '\t';
    cout << "{" << studentRosterArray[i]->getCourseLength ()[0] << "," << studentRosterArray[i]->getCourseLength ()[1] << "," << studentRosterArray[i]->getCourseLength ()[2] << "}";
	  cout << '\t';
	  cout << studentStrings[studentRosterArray[i]->
				 getDegreeProgram ()] << std::endl;
	}

    }
  else
    cout << studentID << " not found." << std::endl << std::endl;
   
}


 Roster::~Roster () {

  cout << "DONE" << std::endl << std::endl;
 
}
