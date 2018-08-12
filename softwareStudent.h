#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <iostream>
#include "student.h"
#include "degree.h"

class SoftwareStudent : public Student {
  Degree degreeType;
  
 public:
  SoftwareStudent(std::string newStudentId, std::string newFirstName, std::string newLastName, std::string newEmailAddress, std::string newAge, std::array<int, 3> newDaysRemainingInCourses) : Student(newStudentId, newFirstName, newLastName, newEmailAddress, newAge, newDaysRemainingInCourses) {
    degreeType = SOFTWARE;
  }
  
  virtual Degree getDegreeProgram() override;
  virtual void print(std::string degreeProgram) override;

  virtual ~SoftwareStudent();
};

#endif
