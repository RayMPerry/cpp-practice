#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <array>
#include "degree.h"

struct FieldsToDisplay {
  bool displayId;
  bool displayFirstName;
  bool displayLastName;
  bool displayEmailAddress;
  bool displayAge;
  bool displayDaysLeftInCourses;
  bool displayDegreePlan;
};
  
class Student {
  std::string studentId;
  std::string firstName;
  std::string lastName;
  std::string emailAddress;
  std::string age;
  // Wish I could move this constant into a variable.
  std::array<int, 3> daysRemainingInCourses;

public:
  Student(std::string newStudentId, std::string newFirstName, std::string newLastName, std::string newEmailAddress, std::string newAge, std::array<int, 3> newDaysRemainingInCourses);

  std::string getStudentId();
  std::string getFirstName();
  std::string getLastName();
  std::string getEmailAddress();
  std::string getAge();
  int getDaysRemainingInCourse(int courseIndex);
  std::array<int, 3> getAllDaysRemainingInCourses();

  // These are `void` for now. I would highly prefer to have them return the value in question.
  // But that's coming from someone who likes Lisp.
  void setStudentId(std::string newStudentId);
  void setFirstName(std::string newFirstName);
  void setLastName(std::string newLastName);
  void setEmailAddress(std::string newEmailAddress);
  void setAge(std::string newAge);
  void setDaysRemainingInCourse(int courseIndex, int daysRemaining);
  void setAllDaysRemainingInCourses(std::array<int, 3> newDaysRemainingInCourses);

  virtual void print();
  virtual void getDegreeProgram();
 
  virtual ~Student();
};

#endif
