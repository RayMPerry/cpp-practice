#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <array>

class Roster {
  ptr* classRosterArray;
 public:
  void add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, std::string age, std::array<int, 3> daysRemainingInCourses, Degree degreeType);
  void remove();
  void printAll();
  void printDaysInCourse();
  void printInvalidEmails();
  void printByDegreeProgram();
}

#endif
