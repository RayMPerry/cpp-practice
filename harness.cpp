#include <iostream>
#include "student.cpp"

using namespace std;

int main()
{
  Student * testStudent = new Student("A5", "Ray", "Perry", "rperr77@wgu.edu", "26", {22, 33, 50}, SOFTWARE);

  array<bool, 7> fieldsToDisplay = {true, true, true, true, true, true, true};
  
  testStudent->print(fieldsToDisplay);
}
