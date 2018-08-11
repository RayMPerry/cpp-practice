#ifndef DEGREE_H
#define DEGREE_H

#include <iostream>
#include <array>

enum Degree {
  SECURITY,
  NETWORK,
  SOFTWARE
};

std::string formatDegreeType(Degree degreeType) {
  std::array<std::string, 3> degreeMapping = { { "SECURITY", "NETWORK", "SOFTWARE" } };

  return degreeMapping.at(degreeType);
}

#endif
