#include <iostream>
#include "student.cpp"
#include "roster.cpp"

using namespace std;

int main()
{
  Roster * testRoster = new Roster();
  testRoster->add("A5", "Ray", "Perry", "rperr77@wgu.edu", "26", {22, 33, 50}, SOFTWARE);
  
  array<bool, 7> fieldsToDisplay = {true, true, true, true, true, true, true};

  for (const auto& student : testRoster) {
    student->print(fieldsToDisplay);
  }

  delete testRoster;
}  
