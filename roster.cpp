#include "roster.h"

const string studentData[] = {
  "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
  "A5,Ray,Perry,rperr77@wgu.edu,26,22,33,50,SOFTWARE"
};

using namespace std;
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, string age, array<int, 3> daysRemainingInCourses, Degree degreeType) {
  classRosterArray[classRosterArray.size()] = new Student(studentId, firstName, lastName, emailAddress, age, daysRemainingInCourses, degreeType);
}
