//Fuyuan Geng
//heap.cpp

#include"heap.h"
#include<iostream>
using namespace std;
//const int CAPACITY = 5;
//const double FACTOR = 2;
const int capacity = 5;

//constructor
//used to define original value
heap::heap(int size)
{
  if (size <= capacity)
    size = capacity;
  curSize = 0;
  capacity = size;
  arr = new int[capacity];
  size = 0;
  
}

//copy constructor
heap::heap(const heap &other)
{
  //int* arr2;
  capacity = other.capacity;
  curSize = other.curSize;
  arr = new int[other.capacity];
  for (int i = 0; i <= curSize; i++)
	{
      arr[i] = other.arr[i];
	}
}


//destructor
//pre:memory didnt release
//post;memory has been release
//data in arr has been delete
heap::~heap() {
  delete[] arr;
}

//overload assignment 
//pre ;different objects
//use operator ex: t2=t1
heap& heap::operator=(const heap& rhs)
{
  if (this != &rhs)
	{
      delete[] arr;
      capacity = rhs.capacity;
      curSize = rhs.curSize;
      arr = new int[capacity];
      for (int i = 1; i <= curSize; i++)
		{
          arr[i] = rhs.arr[i];
		}
	}
  return *this;
}

void heap::swap(int & x, int & y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
  
}


//insert function 
//pre ;no value in heap
//post;insert value in heap
void heap::insert(int value) {
  curSize++;
  if (curSize == capacity)
	{
      resize();
	}
  
  int hole = curSize;
  while (hole > 1 && value < arr[hole/ 2]) {
    arr[hole] = arr[hole/ 2];
    hole = hole/ 2;
  }
  arr[hole] = value;
}
//remove function
//pre value in heap
//post the value has been remove and return
//the left value is percolatedown
int heap::remove() {
  int min = arr[1];
  arr[1] = arr[curSize];
  //swap(arr[1],arr[size]);
  curSize--;
  percolateDown(1);
  return min;
}

//pre::value unorder
//post:inorder value
void heap::percolateDown(int hole) {
  int temp = arr[hole];
  
  while ((hole * 2 <= curSize && temp > arr[hole * 2]) ||
         (hole * 2 + 1 <= curSize && temp > arr[hole * 2 + 1])) {
    if (hole * 2 + 1 <= curSize && arr[hole * 2 + 1] < arr[hole * 2]) {
      arr[hole] = arr[hole * 2 + 1];
      hole = hole * 2 + 1;
    }
    else {
      arr[hole] = arr[hole * 2];
      hole = hole * 2;
    }
  }
  arr[hole] = temp;
}




//resize function, used to when the array over capacity
//pre size between capacity
//post:when pver capacity it will resize
void heap::resize()
{
  capacity = capacity *2;
  int* temp = new int[capacity];
  for (int i = 0; i < curSize; i++)
	{
      temp[i] = arr[i];
	}
  delete[] arr;
  arr = temp;
}

//flush function:flush the value we want
void heap::flush(int value)
{
  
  for (int i = 1; i <= curSize; i++)
	{
      if (arr[i]==value)
		{
          swap(arr[i], arr[curSize]);
          curSize--;
          //i++;
          percolateDown(i);
          i--;
          //i = 1;
		}
	}
}


//check if the array is empty;
bool heap::isEmpty() 
{
  return curSize == 0;
}

//get the size of the array
int heap::getSize()
{
  return curSize;
}


//void heap::display() {
//	for (int i = 0; i <= size; i++) {
//		cout << arr[1] <<" "<< endl;
//		remove();
//	}
//}

