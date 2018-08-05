#include "student.h"

using namespace std;
Student::Student(string newStudentId, string newFirstName, string newLastName, string newEmailAddress, string newAge, int newDaysRemainingInCourses[3], Degree newDegreeType) {
  studentId = newStudentId;
  firstName = newFirstName;
  lastName = newLastName;
  emailAddress = newEmailAddress;
  age = newAge;
  degreeType = newDegreeType;

  for (int index = 0; index < 3; index++) {
    daysRemainingInCourses[index] = newDaysRemainingInCourses[index];
  }
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

int * Student::getAllDaysRemainingInCourses() {
  return daysRemainingInCourses;
};

Degree Student::getDegreeType() {
  return degreeType;
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

void Student::setAllDaysRemainingInCourses(int * newDaysRemainingInCourses) {
  daysRemainingInCourses = newDaysRemainingInCourses;
};

void Student::setDegreeType(Degree newDegreeType) {
  degreeType = newDegreeType;
};

void Student::print(bool fieldsToDisplay[7]) {
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
    string personalInfo[5];
    int * daysRemainingInCourses;
    Degree degreeType;
  } studentRecord;

  studentRecord.personalInfo[0] = studentId;
  studentRecord.personalInfo[1] = firstName;
  studentRecord.personalInfo[2] = lastName;
  studentRecord.personalInfo[3] = emailAddress;
  studentRecord.personalInfo[4] = age;
  
  studentRecord.daysRemainingInCourses = daysRemainingInCourses;
  studentRecord.degreeType = degreeType;
  
  for (int index = 0; index < 7; index++) {
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
    if (index == 6) cout << studentRecord.degreeType;

    if (index < 6) {
      cout << "\t";
    } else {
      cout << "\n";
    }
  }; 

};

void Student::getDegreeProgram() {};
  
Student::~Student() {};
