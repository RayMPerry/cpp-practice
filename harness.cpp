#include <iostream>
#include "student.cpp"

using namespace std;

int main()
{
  struct StudentRecord {
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    string age;
    int daysRemainingInCourses[3];
    Degree degreeType;
  } studentRecord;

  studentRecord.studentId = string() + "A5";
  studentRecord.firstName = string() + "Ray";
  studentRecord.lastName = string() + "Perry";
  studentRecord.emailAddress = string() + "rperr77@wgu.edu";
  studentRecord.age = string() + "26";
  
  studentRecord.daysRemainingInCourses[0] = 22;
  studentRecord.daysRemainingInCourses[1] = 33;
  studentRecord.daysRemainingInCourses[2] = 50;
  
  studentRecord.degreeType = SOFTWARE;

  Student * testStudent = new Student(studentRecord.studentId, studentRecord.firstName, studentRecord.lastName, studentRecord.emailAddress, studentRecord.age, studentRecord.daysRemainingInCourses, studentRecord.degreeType);

  array<bool, 7> fieldsToDisplay = {true, true, true, true, true, true, true};
  
  testStudent->print(fieldsToDisplay);
}
