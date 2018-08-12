#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <iostream>
#include "student.h"
#include "degree.h"

class NetworkStudent : public Student {
  Degree degreeType;
  
 public:
  NetworkStudent(std::string newStudentId, std::string newFirstName, std::string newLastName, std::string newEmailAddress, std::string newAge, std::array<int, 3> newDaysRemainingInCourses) : Student(newStudentId, newFirstName, newLastName, newEmailAddress, newAge, newDaysRemainingInCourses) {
    degreeType = NETWORK;
  }

  virtual Degree getDegreeProgram() override;
  virtual void print(std::string degreeProgram) override;

  virtual ~NetworkStudent();
};

#endif
