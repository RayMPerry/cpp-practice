#include <iostream>
#include <vector>
#include <sstream>
#include <regex>

#include "roster.h"
#include "student.cpp"

using namespace std;
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, string age, array<int, 3> daysRemainingInCourses, Degree degreeProgram) {
  // Commenting out because this throws an error.
  // classRosterArray.emplace_back(studentId, firstName, lastName, emailAddress, age, daysRemainingInCourses);
}

vector<Student*> Roster::getRoster() {
  return classRosterArray;
}

void Roster::importRecords(vector<string> studentRecords) {
  struct StudentToImport {
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    string age;
    array<int, 3> daysRemainingInCourses;
    Degree degreeProgram;
  } studentToImport;

  vector<string> recordFields;

  for (const auto& studentData : studentRecords) {
    // Flip it later.
    string recordField;
    stringstream recordStream { studentData };
    while (getline(recordStream, recordField, ',')) {
      recordFields.push_back(recordField);
    }
  }
  
  for (int index = 0; index < recordFields.size(); index++) {
    switch (index % 7) {}
    
  }
}

int main()
{
  vector<string> mockStudentData = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Ray,Perry,rperr77@wgu.edu,26,22,33,50,SOFTWARE"
  };
  
  Roster * testRoster = new Roster();
  array<bool, 7> fieldsToDisplay = {{ true, true, true, true, true, true, true }};

  testRoster->importRecords(mockStudentData);
  
  vector<Student*> allStudents = testRoster->getRoster();
  
  cout << "Test";

  for (auto& student : allStudents) {
    student->print(fieldsToDisplay);
  }

  delete testRoster;
}
