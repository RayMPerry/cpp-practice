#include <regex>
#include "roster.h"

using namespace std;
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, string age, array<int, 3> daysRemainingInCourses, Degree degreeType) {
  Student * newStudent = new Student(studentId, firstName, lastName, emailAddress, age, daysRemainingInCourses, degreeType);
  classRosterArray.push_back(newStudent);
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
    Degree degreeType;
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
