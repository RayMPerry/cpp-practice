#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <array>
#include <vector>
#include "student.h"

class Roster {
  std::vector<Student*> classRosterArray;
 public:
  std::vector<Student*> getRoster();

  void importRecords(std::vector<std::string> studentRecords);
  void add(std::vector<std::string> studentFields);
  void add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, std::string age, std::array<int, 3> daysRemainingInCourses, Degree degreeProgram);
  void remove(std::string studentId);
  void removeAllStudents();
  void printPreamble();
  void printAll();
  void printAverageDaysInCourse(std::string studentId);
  void printInvalidEmails();
  void printByDegreeProgram(Degree degreeProgram);
};

#endif
