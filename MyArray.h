// project - Kirk Lopez
#ifndef MAR_H
#define MAR_H

#include <iostream>
template<class M>
class MyArray{
public:
  MyArray():capacity(10),size(0),array(new M[capacity]){};
  MyArray(int s):capacity(s),size(0){
    if(s < 1){
      std::cout << "Invalid capacity size" << std::endl;
      exit(1);
    }
    array = new M[capacity];
  };
  MyArray(const M &o){
    capacity = o.capacity;
    array = new M[o.capacity];
    size = o.size;
    for(int i=0;i<o.size;i++){
      *(array+i) = *(o.array+i);
    }
  };
  ~MyArray(){
    delete [] array;
  };
  MyArray<M>& operator=(const M &o){
    if(this != &o){
      if(capacity != o.capacity){
        capacity = o.capacity;
        delete [] array;
      }
      array = new M[o.capacity];
      size = o.size;
      for(int i=0;i<o.size;i++){
        *(array+i) = *(o.array+i);
      }
    }
    return *this;
  };
  void push_back(M &o) {
    if(size >= capacity -1) {
        grow();
    }
    *(array+size++) = o;
  }
  void erase(M &o){
    if(getPosition(o) != -1){
      for(int i=getPosition(o);i<size;i++){
        *(array+i) = *(array+i+1);
      }
      size--;
    }
    else{
      std::cout << "Element not found" << std::endl;
    }
  };
  int getCap() const{ return capacity; };
  M& operator[](int index){
    if(index < 0 || index >= size){
      std::cout << "Error! Wrong index!" << std::endl;
      exit(1);
    }
    return *(array+index);
  };
  int getSize() const{ return size; };
  int getPosition(M &element) const{
    for(int i=0;i<size;++i){
      if(element == *(array+i)){
        return i;
      }
    }
    return -1;
  };
private:
  void grow(){
    capacity = capacity*2+1;
    M *temp = new M[capacity];
    for(int i=0;i<size;i++){
      *(temp+i) = *(array+i);
    }
    delete [] array;
    array = temp;
  }
  int capacity;
  int size;
  M *array;
};
#endif
