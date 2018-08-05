#include <iostream>
#include "student.cpp"

using namespace std;

int main()
{
  Student * testStudent = new Student("A5", "Ray", "Perry", "rperr77@wgu.edu", "26", {22, 33, 50}, SOFTWARE);

  array<Student*, 5> students = {testStudent, testStudent, testStudent, testStudent, testStudent};
  
  array<bool, 7> fieldsToDisplay = {true, true, true, true, true, true, true};

  for (const auto& student : students) {
    student->print(fieldsToDisplay);
  }

  delete testStudent;
}  
