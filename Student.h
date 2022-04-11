// project - Kirk Lopez
#ifndef STU_H
#define STU_H

#include "MyArray.h"
#include "Course.h"

class Course;
class Student{
public:
  Student();
  Student(std::string n);
  std::string getName() const;
  void setName(std::string n);
  void addCourse(Course &c);
  void dropCourse(Course &c);
  void display();
  friend std::ostream& operator<<(std::ostream& out,const Student &o);
private:
  std::string name;
  MyArray<Course*> classes;
};
#endif
