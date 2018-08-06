#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <array>
#include <vector>

class Roster {
  std::vector<Student*> classRosterArray;
 public:
  std::vector<Student*> getRoster();

  void importRecords(std::vector<std::string> studentRecords);
  void add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, std::string age, std::array<int, 3> daysRemainingInCourses, Degree degreeType);
  void remove(std::string studentId);
  void printAll();
  void printDaysInCourse(std::string studentId);
  void printInvalidEmails();
  void printByDegreeProgram(int degreeType);
};

#endif
