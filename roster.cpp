#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <regex>
#include <map>

#include "roster.h"
#include "softwareStudent.cpp"
#include "networkStudent.cpp"
#include "securityStudent.cpp"

void Roster::add(std::vector<std::string>) {
}

void Roster::add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, std::string age, std::array<int, 3> daysRemainingInCourses, Degree degreeProgram) {
  // Commenting out because this throws an error.
  // classRosterArray.emplace_back(studentId, firstName, lastName, emailAddress, age, daysRemainingInCourses);
}

std::vector<Student*> Roster::getRoster() {
  return classRosterArray;
}

void Roster::importRecords(std::vector<std::string> studentRecords) {
  struct StudentToImport {
    std::string studentId;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    std::string age;
    std::array<int, 3> daysRemainingInCourses;
    Degree degreeProgram;
  } studentToImport;

  for (const auto& studentData : studentRecords) {
    int studentFieldIndex = 0;
    // Flip it later.
    std::string recordField;
    std::stringstream recordStream { studentData };
    std::map<std::string, Degree> degreeMapping;
    
    degreeMapping.emplace("SECURITY", SECURITY);
    degreeMapping.emplace("NETWORK", NETWORK);
    degreeMapping.emplace("SOFTWARE", SOFTWARE);
    
    while (getline(recordStream, recordField, ',')) {
      switch (studentFieldIndex) {
        case 0:
          studentToImport.studentId = recordField;
          break;
        case 1:
          studentToImport.firstName = recordField;
          break;
        case 2:
          studentToImport.lastName = recordField;
          break;
        case 3:
          studentToImport.emailAddress = recordField;
          break;
        case 4:
          studentToImport.age = recordField;
          break;
        case 5:
        case 6:
        case 7:
          studentToImport.daysRemainingInCourses[studentFieldIndex - 5] = std::stoi(recordField);
          break;
        case 8:
          studentToImport.degreeProgram = degreeMapping[recordField];
          break;
      }

      studentFieldIndex++;
      studentFieldIndex = studentFieldIndex % 9;
    }

    switch (studentToImport.degreeProgram) {
      case SECURITY:
        classRosterArray.emplace_back(new SoftwareStudent(
            studentToImport.studentId,
            studentToImport.firstName,
            studentToImport.lastName,
            studentToImport.emailAddress,
            studentToImport.age,
            studentToImport.daysRemainingInCourses));
        break;
      case NETWORK:
        classRosterArray.emplace_back(new SoftwareStudent(
            studentToImport.studentId,
            studentToImport.firstName,
            studentToImport.lastName,
            studentToImport.emailAddress,
            studentToImport.age,
            studentToImport.daysRemainingInCourses));
        break;
      case SOFTWARE:
        classRosterArray.emplace_back(new SoftwareStudent(
            studentToImport.studentId,
            studentToImport.firstName,
            studentToImport.lastName,
            studentToImport.emailAddress,
            studentToImport.age,
            studentToImport.daysRemainingInCourses));
        break;
    }
    
    std::cout << std::endl;
  }
}

void Roster::printAll() {
  std::cout << std::left
            << std::setw(15) << "Student ID"
            << std::setw(15) << "First Name"
            << std::setw(15) << "Last Name"
            << std::setw(25) << "Email"
            << std::setw(15) << "Age"
            << std::setw(25) << "Days Left In Courses"
            << std::setw(15) << "Degree Program"
            << std::endl;

  for (auto& student : classRosterArray) {
    student->print();
  }
}

void Roster::removeAllStudents() {
  while (!classRosterArray.empty()) delete classRosterArray.back(), classRosterArray.pop_back();
}

int main()
{
  std::vector<std::string> mockStudentData = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Ray,Perry,rperr77@wgu.edu,26,22,33,50,SOFTWARE"
  };
  
  Roster * testRoster = new Roster();

  testRoster->importRecords(mockStudentData);
  testRoster->printAll();
  testRoster->removeAllStudents();
  
  delete testRoster;
}
