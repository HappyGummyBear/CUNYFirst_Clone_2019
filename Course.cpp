// project - Kirk Lopez
#include "Instructor.h"
#include "Course.h"
#include "Student.h"

  Course::Course(){ *(prof) = Instructor(); };
  Course::Course(std::string n,Instructor &i):name(n){
    prof = &i;
    i.addCourse(this);
  };
  std::string Course::getName() const{ return name; };
  void Course::setName(std::string n){ name = n; };
  Instructor Course::getInstructor(){ return *(prof); };
  void Course::setInstructor(Instructor &i){
    prof = &i;
  };
  void Course::dropInstructor(){
    getInstructor().dropCourse(*this);
    prof = new Instructor();
  };
  void Course::display(){
    std::cout << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << name << " - " << getInstructor().getInstName() << " ";
    std::cout << std::endl;
    for(int i=0;i<peeps.getSize();i++){
      std::cout << i+1 << ": " << *(peeps[i]) << std::endl;
    }
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << std::endl;
  }
  void Course::addStudent(Student &s){
    Student *temp;
    temp = &s;
    if(peeps.getPosition(temp) != -1){
      std::cout << "Student already in this course" << std::endl;
      return;
    }
      peeps.push_back(temp);
  };
  void Course::dropStudent(Student &s){
    Student *temp = &s;
    if(peeps.getPosition(temp) != -1){
      peeps.erase(temp);
      return;
    }
    std::cout << "Student not enrolled in this course" << std::endl;
  };
