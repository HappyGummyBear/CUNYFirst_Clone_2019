// project - Kirk Lopez
#include "Course.h"
#include "Student.h"

  Student::Student():Student("Student"){};
  Student::Student(std::string n):name(n){};
  std::string Student::getName() const{ return name; };
  void Student::setName(std::string n){ name = n; };
  void Student::addCourse(Course &c){
    Course *temp = &c;
    if(classes.getPosition(temp) != -1){
      std::cout << "Already in Course" << std::endl;
      return;
    }
      c.addStudent(*this);
      classes.push_back(temp);
  };
  void Student::dropCourse(Course &c){
    Course *temp = &c;
    if(classes.getPosition(temp) != -1){
      classes.erase(temp);
      c.dropStudent(*this);
      return;
    }
    std::cout << "Not enrolled in this course" << std::endl;
  };
  std::ostream& operator<<(std::ostream& out,const Student &o){
    out << o.name;
    return out;
  }
  void Student::display(){
    std::cout << *this << std::endl;
    std::cout << "Courses: ";
    for(int i=0;i<classes.getSize();i++){
      std::cout << classes[i]->getName() << " ";
    }
    std::cout << std::endl;
  };
