#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <iostream>
#include "student.h"
#include "degree.h"

class SecurityStudent : public Student {
  Degree degreeType;
  
 public:
  SecurityStudent(std::string newStudentId, std::string newFirstName, std::string newLastName, std::string newEmailAddress, std::string newAge, std::array<int, 3> newDaysRemainingInCourses) : Student(newStudentId, newFirstName, newLastName, newEmailAddress, newAge, newDaysRemainingInCourses) {
    degreeType = SECURITY;
  }
 
  virtual Degree getDegreeProgram() override;
  virtual void print(std::string degreeProgram) override;
  
  virtual ~SecurityStudent();
};

#endif
