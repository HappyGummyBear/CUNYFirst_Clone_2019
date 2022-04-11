// project - Kirk Lopez
#include "Course.h"
#include "Instructor.h"

  Instructor::Instructor():Instructor("Staff"){};
  Instructor::Instructor(std::string n):name(n){};
  Instructor::Instructor(std::string n,std::string d):name(n),department(d){};
  std::string Instructor::getInstName() const{ return name; };
  void Instructor::setName(std::string n){ name = n; };
  std::string Instructor::getDepartment() const{ return department; };
  void Instructor::setDepartment(std::string d){ department = d; };
  void Instructor::addCourse(Course* c){
    if(classroom.getPosition(c) == -1){
      classroom.push_back(c);
    }else{
      std::cout << "Already in Course" << std::endl;
      return;
    }
  };
  void Instructor::dropCourse(Course &c){
    Course *temp = &c;
    if(classroom.getPosition(temp) != -1){
      classroom.erase(temp);
      exit(1);
    }
  };
  void Instructor::display(){
    std::cout << name << " " << department << std::endl;
    std::cout << "Courses: ";
    for(int i=0;i<classroom.getSize();i++){
      std::cout << classroom[i]->getName() << " ";
    }
  };
