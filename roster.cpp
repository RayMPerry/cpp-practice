#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <regex>
#include <string>
#include <map>

#include "degree.h"
#include "roster.h"
#include "student.cpp"
#include "softwareStudent.cpp"
#include "networkStudent.cpp"
#include "securityStudent.cpp"

void Roster::add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, std::string age, std::array<int, 3> daysRemainingInCourses, Degree degreeProgram) {
    switch (degreeProgram) {
      case SECURITY:
        classRosterArray.emplace_back(new SecurityStudent(
            studentId,
            firstName,
            lastName,
            emailAddress,
            age,
            daysRemainingInCourses));
        break;
      case NETWORK:
        classRosterArray.emplace_back(new NetworkStudent(
            studentId,
            firstName,
            lastName,
            emailAddress,
            age,
            daysRemainingInCourses));
        break;
      case SOFTWARE:
        classRosterArray.emplace_back(new SoftwareStudent(
            studentId,
            firstName,
            lastName,
            emailAddress,
            age,
            daysRemainingInCourses));
        break;
    }
}

void Roster::remove(std::string studentId) {
  int indexToRemove = 0;
  bool foundStudent = false;
  for (const auto& student : classRosterArray) {
    std::string currentStudentId = student->getStudentId();

    if (currentStudentId == studentId) {
      foundStudent = true;
      std::vector<Student *>& cra = classRosterArray;
      cra.erase(std::remove(cra.begin(), cra.end(), student), cra.end());
    }

    indexToRemove++;
  }

  if (!foundStudent) {
    std::cout << "ERROR: Didn't find student with ID " << studentId << std::endl;
  }
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

    add(studentToImport.studentId, studentToImport.firstName, studentToImport.lastName, studentToImport.emailAddress, studentToImport.age, studentToImport.daysRemainingInCourses, studentToImport.degreeProgram);
  }
}

void Roster::printPreamble() {
  std::cout << std::left
            << std::setw(15) << "Student ID"
            << std::setw(15) << "First Name"
            << std::setw(15) << "Last Name"
            << std::setw(25) << "Email"
            << std::setw(15) << "Age"
            << std::setw(25) << "Days Left In Courses"
            << std::setw(15) << "Degree Program"
            << std::endl;
}

void Roster::printAll() {
  printPreamble();
  
  for (auto& student : classRosterArray) {
    student->print();
  }
}

void Roster::printAverageDaysInCourse(std::string studentId) {
  bool foundStudent = false;
  
  for (auto& student : classRosterArray) {
    std::string currentStudentId = student->getStudentId();

    if (currentStudentId == studentId) {
      foundStudent = true;
      std::cout << "Student " << studentId << " average days left: ";
      float averageDaysLeft = 0;
      std::array<int, 3> currentStudentDaysRemaining = student->getAllDaysRemainingInCourses();
      
      for (auto& daysLeft : currentStudentDaysRemaining) {
        averageDaysLeft = averageDaysLeft + daysLeft;
      }
      std::cout << (averageDaysLeft / 3) << std::endl;
    }
  }
  
  if (!foundStudent) {
    std::cout << "ERROR: Didn't find student with ID " << studentId << std::endl;
  }
}

void Roster::printInvalidEmails() {
  std::regex validEmailAddresses ("^[a-zA-Z0-9_.\\-]+@[[:alpha:]]+\\.[[:alpha:]]+");
  
  for (auto& student : classRosterArray) {
    std::string currentEmailAddress = student->getEmailAddress();
    
    if (!std::regex_match(currentEmailAddress, validEmailAddresses)) {
      std::cout << "Invalid email address: " << currentEmailAddress << std::endl;
    }
  }
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
  printPreamble();
  for (auto& student : classRosterArray) {
    Degree currentStudentDegree = student->getDegreeProgram();

    if (currentStudentDegree == degreeProgram) {
      student->print();
    }
  }
}

void Roster::removeAllStudents() {
  while (!classRosterArray.empty()) delete classRosterArray.back(), classRosterArray.pop_back();
}

int main()
{
  std::cout << std::endl << "Program Name: Student Roster" << std::endl
            << "Course Title: Scripting and Programming - Applications – C867" << std::endl
            << "Programming Language: C++" << std::endl
            << "Student ID: 000981059" << std::endl
            << "Student Name: Ray Perry" << std::endl << std::endl;
  
  std::vector<std::string> mockStudentData = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Ray,Perry,rperr77@wgu.edu,26,22,33,50,SOFTWARE"
  };
  
  Roster * roster = new Roster();

  roster->importRecords(mockStudentData);
  roster->printAll();
  roster->printInvalidEmails();

  for (auto& student : roster->getRoster()) {
    roster->printAverageDaysInCourse(student->getStudentId());
  }

  // Print by degree program.
  roster->printByDegreeProgram(SOFTWARE);
  
  roster->remove("A3");
  roster->remove("A3");
  roster->removeAllStudents();
  
  delete roster;
}
