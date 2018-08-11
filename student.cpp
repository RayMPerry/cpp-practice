#include <iostream>
#include <iomanip>
#include <array>
#include "student.h"

Student::Student(std::string newStudentId, std::string newFirstName, std::string newLastName, std::string newEmailAddress, std::string newAge, std::array<int, 3> newDaysRemainingInCourses) {
  studentId = newStudentId;
  firstName = newFirstName;
  lastName = newLastName;
  emailAddress = newEmailAddress;
  age = newAge;
  daysRemainingInCourses = newDaysRemainingInCourses;
};

std::string Student::getStudentId() {
  return studentId;
};

std::string Student::getFirstName() {
  return firstName;
};

std::string Student::getLastName() {
  return lastName;
};

std::string Student::getEmailAddress() {
  return emailAddress;
};

std::string Student::getAge() {
  return age;
};

int Student::getDaysRemainingInCourse(int courseIndex) {
  return daysRemainingInCourses[courseIndex];
};

std::array<int, 3> Student::getAllDaysRemainingInCourses() {
  return daysRemainingInCourses;
};

// These are `void` for now. I would highly prefer to have them return the value in question.
// But that's coming from someone who likes Lisp.
void Student::setStudentId(std::string newStudentId) {
  studentId = newStudentId;
};

void Student::setFirstName(std::string newFirstName) {
  firstName = newFirstName;
};

void Student::setLastName(std::string newLastName) {
  lastName = newLastName;
};

void Student::setEmailAddress(std::string newEmailAddress) {
  emailAddress = newEmailAddress;
};

void Student::setAge(std::string newAge) {
  age = newAge;
};

void Student::setDaysRemainingInCourse(int courseIndex, int daysRemaining) {
  daysRemainingInCourses[courseIndex] = daysRemaining;
};

void Student::setAllDaysRemainingInCourses(std::array<int, 3> newDaysRemainingInCourses) {
  daysRemainingInCourses = newDaysRemainingInCourses;
};

void Student::print(std::array<bool, 7> fieldsToDisplay) {
  /* 
   * Originally, there was  an std::array of strings here  that allowed you
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
    std::array<std::string, 5> personalInfo;
    std::array<int, 3> daysRemainingInCourses;
    Degree degreeType;
  } studentRecord;

  studentRecord.personalInfo = (std::array<std::string, 5>){{ studentId, firstName, lastName, emailAddress, age }};
  studentRecord.daysRemainingInCourses = daysRemainingInCourses;

  int fieldWidth = 5;

  std::cout << std::setw(fieldWidth) << std::left;
  
  for (int index = 0; index < 7; index++) {
    std::cout << fieldsToDisplay[index];
    if (fieldsToDisplay[index] == false) continue;
    // Personal Info fields.
    if (index < 5) std::cout << studentRecord.personalInfo[index];

    // Days remaining fields.
    if (index == 5) {
      for (int innerIndex = 0; innerIndex < 3; innerIndex++) {
          std::cout << studentRecord.daysRemainingInCourses[innerIndex] << "\t";
      };
      continue;
    }

    // Degree Type field.
    // if (index == 6)   std::cout << formatDegreeType(studentRecord.degreeType);

    if (index < 6) {
        std::cout << "\t";
    } else {
      std::cout << std::endl;
    }
  };

    std::cout.flush(); 
};

void Student::getDegreeProgram() {};
  
Student::~Student() {};
