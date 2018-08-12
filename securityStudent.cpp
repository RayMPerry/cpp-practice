#include <iostream>
#include "degree.h"
#include "securityStudent.h"

Degree SecurityStudent::getDegreeProgram() {
  return SECURITY;
}

void SecurityStudent::print(std::string degreeProgram) {
  this->Student::print("SECURITY");
}

SecurityStudent::~SecurityStudent() {}
