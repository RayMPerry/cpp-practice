#include <iostream>
#include "degree.h"
#include "softwareStudent.h"

Degree SoftwareStudent::getDegreeProgram() {
  return SOFTWARE;
}

void SoftwareStudent::print(std::string degreeProgram) {
  this->Student::print("SOFTWARE");
}

SoftwareStudent::~SoftwareStudent() {}
