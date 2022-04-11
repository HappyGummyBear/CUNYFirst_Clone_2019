// project - Kirk Lopez
#ifndef INS_H
#define INS_H

#include "MyArray.h"
#include "Course.h"

class Course;
class Instructor{
public:
  Instructor();
  Instructor(std::string n);
  Instructor(std::string n,std::string d);
  std::string getInstName() const;
  void setName(std::string n);
  std::string getDepartment() const;
  void setDepartment(std::string d);
  void addCourse(Course* c);
  void dropCourse(Course &c);
  void display();
  void testArray();
private:
  std::string name;
  std::string department;
  MyArray<Course*> classroom{};
};
#endif
