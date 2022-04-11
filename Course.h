// project - Kirk Lopez
#ifndef COR_H
#define COR_H

#include "MyArray.h"
#include "Instructor.h"
#include "Student.h"

class Student;
class Instructor;
class Course{
public:
  Course();
  Course(std::string n,Instructor &i);
  std::string getName() const;
  void setName(std::string n);
  Instructor getInstructor();
  void setInstructor(Instructor &i);
  void display();
  void addStudent(Student &s);
  void dropStudent(Student &s);
  void dropInstructor();
  friend std::ostream& operator<<(std::ostream& out,const Student &o);
private:
  std:: string name;
  Instructor *prof;
  MyArray<Student*> peeps;
};
#endif
