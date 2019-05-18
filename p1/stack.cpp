//Fuyuan Geng
//P1 stcack.cpp
//Jan 25th 2019

#include "stack.h"

stack::stack(int size){
  if (size < 3)
    size = 50;
	max= size;
	arr = new int[max];
	top = 0;
}

stack::stack(const stack& s){
  max = s.max;
  arr = new int[max];
  top = s.top;
  for (int i = 0; i < top; i++){
    arr[i] = s.arr[i];
  } 
}

stack& stack::operator=(const stack& rhs){
  if (this != &rhs) {
    delete[] arr;
    max = rhs.max;
    arr = new int[max];
    top = rhs.top;
    for (int i = 0; i < top; i++) {
      arr[i] = rhs.arr[i];
    }
  }return *this;
}

stack::~stack(){
  delete[] arr;
}

void stack::push(int data){
  if(full()){
    resize();
  }
  if (prime(data)){
    arr[top] = data;
    top++;
  }
}

int stack::pop(){
  if (isEmpty()){
    throw EmptyStack();
  }
  else {
    top--;
    return arr[top];
  }
}

bool stack::isEmpty(){
  return top == 0;
}

bool stack::full(){
  return top == max;
}


void stack::resize(){
  int* tmp;                                 
  int larger = static_cast<int>(max * 1.5);  
  tmp = new int[larger];                    
  for (int i = 0; i < top; i++)             
    tmp[i] = arr[i];
  
  delete[] arr;                          
  arr = tmp;                              
  max = larger;                            
}


bool stack::prime(int num) {
  if (num <= 1)
    return false;
  if (num ==2) 
    return true;
  
  if (num == 3)
    return true;
  
  for (int i =2; i <=num/2; i++){
    if (num%i == 0) {
      return false;
    }

  }
  return true;
}

