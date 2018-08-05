#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <iostream>
#include <student.h>
#include <degree.h>

class SoftwareStudent : public Student {
  Degree degreeType;
  
 public:
  void getDegreeProgram() override;
  void print() override;
}

#endif
