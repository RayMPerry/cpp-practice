#ifndef DEGREE_H
#define DEGREE_H

#include <iostream>
#include <array>

enum Degree {
  SECURITY,
  NETWORKING,
  SOFTWARE
};

std::string formatDegreeType(Degree degreeType) {
  std::array<std::string, 3> degreeMapping = {
    "SECURITY",
    "NETWORKING",
    "SOFTWARE"
  };

  return degreeMapping.at(degreeType);
}

#endif
