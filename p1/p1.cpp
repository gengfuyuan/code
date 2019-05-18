//Fuyuan Geng
//P1	p1.cpp
//Jan 25th 2019


#include <iostream>
#include "stack.h"

using namespace std;

void testStack();
// tests all stack package methods

int main()
{
  cout << endl << endl;
  cout << "testing Stack operations...." << endl;
  testStack();
  cout << endl;
  cout << "Tests done" << endl << endl;
  system("pause");
  return 0;
}

void testStack()
{
  int val;
  // constructor
  stack s1;
  // constructor with size
  stack s2(3);
  
  // push
  cout << "pushing 4 values onto stack (s1) of default size" << endl;
  val = 10;
  for (int i = 0; i < 4; i++) {
    cout << "Now pushing " << val << endl;
    s1.push(val);
    val++;
  }

  // copy constructor
  cout << "making a copy of stack into new instance (s3)" << endl;
  stack s3(s1);
  // pop & isEmpty
  cout << "now popping all values from original stack (s1)" << endl;
  while (!s1.isEmpty())
    cout << s1.pop() << ' ';
  
  cout << endl;
  
  cout << "now popping all values from copied stack (s3)" << endl;
  cout << "should be same values as above" << endl;
  while (!s3.isEmpty())
    cout << s3.pop() << ' ';
  
  cout << endl;

  // resize
  cout << "pushing 5 values onto stack (s2) of size 3" << endl;
  val = 0;
  for (int i = 0; i < 5; i++) {
    cout << "Now pushing " << val << endl;
    s2.push(val);
    val++;
  }

  // assignment operator
  cout << "copying s2 into s1" << endl;
  s1 = s2;
  cout << "now popping all of s2" << endl;
  while (!s2.isEmpty())
    cout << s2.pop() << ' ';
  cout << endl;
  
  cout << "now popping all of s1..should be same as above" << endl;
  while (!s1.isEmpty())
    cout << s1.pop() << ' ';
  cout << endl;
  
  cout << "trying to catch the EmptyStack exception" << endl;
  try {
    cout << s1.pop();
  }
  catch (stack::EmptyStack) {
    cout << "ERROR: Cannot pop from empty stack" << endl;
  }
  cout << endl;
  
  
}

