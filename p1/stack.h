//Fuyuan Geng
//P1 stcack.h
//Jan 25th 2019
#ifndef stack_H
#define stack_H


class stack
{
 public:
  class EmptyStack {};
  explicit stack(int size = 50);
  ~stack();
  void push(int data);
  int pop();
  bool isEmpty();

  stack(const stack& s);
  stack& operator=(const stack& rhs);

 private:
  int max;
  int top;
  int* arr;
  void resize();
  bool full();
  bool prime(int num);
};

#endif 
