#include <iostream>
#include <iomanip>
#include <array>
#include "student.h"

using namespace std;

Student::Student(string newStudentId, string newFirstName, string newLastName, string newEmailAddress, string newAge, array<int, 3> newDaysRemainingInCourses) {
  studentId = newStudentId;
  firstName = newFirstName;
  lastName = newLastName;
  emailAddress = newEmailAddress;
  age = newAge;
  daysRemainingInCourses = newDaysRemainingInCourses;
};

string Student::getStudentId() {
  return studentId;
};

string Student::getFirstName() {
  return firstName;
};

string Student::getLastName() {
  return lastName;
};

string Student::getEmailAddress() {
  return emailAddress;
};

string Student::getAge() {
  return age;
};

int Student::getDaysRemainingInCourse(int courseIndex) {
  return daysRemainingInCourses[courseIndex];
};

array<int, 3> Student::getAllDaysRemainingInCourses() {
  return daysRemainingInCourses;
};

// These are `void` for now. I would highly prefer to have them return the value in question.
// But that's coming from someone who likes Lisp.
void Student::setStudentId(string newStudentId) {
  studentId = newStudentId;
};

void Student::setFirstName(string newFirstName) {
  firstName = newFirstName;
};

void Student::setLastName(string newLastName) {
  lastName = newLastName;
};

void Student::setEmailAddress(string newEmailAddress) {
  emailAddress = newEmailAddress;
};

void Student::setAge(string newAge) {
  age = newAge;
};

void Student::setDaysRemainingInCourse(int courseIndex, int daysRemaining) {
  daysRemainingInCourses[courseIndex] = daysRemaining;
};

void Student::setAllDaysRemainingInCourses(array<int, 3> newDaysRemainingInCourses) {
  daysRemainingInCourses = newDaysRemainingInCourses;
};

void Student::print(array<bool, 7> fieldsToDisplay) {
  /* 
   * Originally, there was  an array of strings here  that allowed you
   * to change  the order  of what was  printed. However,  C++ doesn't
   * have reflection built in. An interesting gotcha for people coming
   * from JavaScript. 
   */

  /* 
   * Okay, so this next  part is a bit gross but I  thought I could do
   * it in  a simpler fashion than  this. I wanted to  filter what was
   * printed easier  but C++ doesn't make  assumptions about anything,
   * it seems.  A lot  of niceties  and things I  took for  granted in
   * JavaScript  simply  aren't  here.  This is  my  attempt  at  said
   * structure: group  as much  as possible by  type and  display that
   * way.
   */
   
  struct StudentRecord {
    array<string, 5> personalInfo;
    array<int, 3> daysRemainingInCourses;
    Degree degreeType;
  } studentRecord;

  studentRecord.personalInfo = (array<string, 5>){{ studentId, firstName, lastName, emailAddress, age }};
  studentRecord.daysRemainingInCourses = daysRemainingInCourses;

  int fieldWidth = 5;

  cout << setw(fieldWidth) << left;
  
  for (int index = 0; index < 7; index++) {
    cout << fieldsToDisplay[index];
    if (fieldsToDisplay[index] == false) continue;
    // Personal Info fields.
    if (index < 5) cout << studentRecord.personalInfo[index];

    // Days remaining fields.
    if (index == 5) {
      for (int innerIndex = 0; innerIndex < 3; innerIndex++) {
        cout << studentRecord.daysRemainingInCourses[innerIndex] << "\t";
      };
      continue;
    }

    // Degree Type field.
    // if (index == 6) cout << formatDegreeType(studentRecord.degreeType);

    if (index < 6) {
      cout << "\t";
    } else {
      cout << endl;
    }
  };

  cout.flush(); 
};

void Student::getDegreeProgram() {};
  
Student::~Student() {};
