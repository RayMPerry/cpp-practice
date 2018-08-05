#include <iostream>
#include <student.h>
#include <degree.h>
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

using namespace std;
class SoftwareStudent : public Student {
  Degree degreeType;
  
 public:
  void getDegreeProgram() override;
  void print() override;
}

#endif
