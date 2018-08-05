#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "degree.h"

using namespace std;
class Student {
  string studentId;
  string firstName;
  string lastName;
  string emailAddress;
  string age;
  // Wish I could move this constant into a variable.
  array<int, 3> daysRemainingInCourses;
  Degree degreeType;

public:
  Student(string newStudentId, string newFirstName, string newLastName, string newEmailAddress, string newAge, int newDaysRemainingInCourses[3], Degree newDegreeType);

  string getStudentId();
  string getFirstName();
  string getLastName();
  string getEmailAddress();
  string getAge();
  int getDaysRemainingInCourse(int courseIndex);
  int * getAllDaysRemainingInCourses();
  Degree getDegreeType();

  // These are `void` for now. I would highly prefer to have them return the value in question.
  // But that's coming from someone who likes Lisp.
  void setStudentId(string newStudentId);
  void setFirstName(string newFirstName);
  void setLastName(string newLastName);
  void setEmailAddress(string newEmailAddress);
  void setAge(string newAge);
  void setDaysRemainingInCourse(int courseIndex, int daysRemaining);
  void setAllDaysRemainingInCourses(int newDaysRemainingInCourses[3]);
  void setDegreeType(Degree newDegreeType);

  virtual void print(bool fieldsToDisplay[7]);
  virtual void getDegreeProgram();
  
  ~Student();
};

#endif
