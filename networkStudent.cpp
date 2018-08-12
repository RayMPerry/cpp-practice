#include <iostream>
#include "degree.h"
#include "networkStudent.h"

Degree NetworkStudent::getDegreeProgram() {
  return NETWORK;
}

void NetworkStudent::print(std::string degreeProgram) {
  this->Student::print("NETWORK");
}

NetworkStudent::~ NetworkStudent() {}
