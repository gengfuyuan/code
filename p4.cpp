//Fuyuan Geng
//p4.cpp



#include<iostream>
#include<ctime>
#include<cstdlib> 
#include<cstdio>
#include<iomanip>
//#include<chrono>
#include<cmath>
#include"heap.h"
//#include"heap.cpp""
using namespace std;


const int TOTAL_RANDOM_NUM = 5;

const int MIN_VALUE = 0;
const int MAX_VALUE = 101;
const int MAX_SIZE = 5;
const int MAX_SIZE_SED = 8;
const int COL = 4;
const int NUMBER = 2;

int main()
{
  heap  t1(TOTAL_RANDOM_NUM);
  
  srand(time(0));
  //int size = 5;
  //int capacity = 0;
  int randomNum;
  //int curSize = 5;
  cout << "1.Insert function test :  " << endl;
  cout << "Inserting " << MAX_SIZE << " numbers: ";
  for (int i = 0; i < MAX_SIZE; i++) {
    randomNum = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    cout << randomNum << " ";
    t1.insert(randomNum);
  }
  cout << endl << endl;
  cout << "2. Remove and IsEmpty function test : " << endl;
  while (!t1.isEmpty()) {
    cout << t1.remove() << " ";
  }
  cout << endl << endl;
  cout << "Compare two output, for the second one in order " << endl;
  cout << "And all the values been ouput " << endl;
  cout << "So Remove and IsEmpty function has been tested" << endl;
  
  cout << endl << endl;
  
  
  // text copy constructor
  cout << "3. copy constructor text : " << endl << endl;
  cout << "Insert  value in(t1) : ";
  for (int i = 0; i < MAX_SIZE; i++) {
    randomNum = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    //cout << randomNum << " ";
    t1.insert(randomNum);
  }
  
  cout << "Display the heap(t2) in-order: ";
  heap t2(t1);//copy of t1 into t2
  cout << endl << endl;
  while (!t2.isEmpty()) {
    cout << t2.remove() << " ";
  }
  cout << endl << endl;
  
  cout << "Display the heap(t1) in-order: ";
  while (!t1.isEmpty()) {
    cout << t1.remove() << " ";
  }
  cout << endl << endl;
  cout << "Beacause t2 is same to t1 so copy constructor is texted" << endl;
  
  cout << endl << endl;
  
  cout << "4. overloaded assigment operator text : " << endl;
  
  for (int i = 0; i < MAX_SIZE; i++) {
    randomNum = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    //cout << randomNum << " ";
    t1.insert(randomNum);
  }
  
  for (int i = 0; i < MAX_SIZE_SED; i++) {
    randomNum = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    //cout << randomNum << " ";
    t2.insert(randomNum);
  }
  
  t2 = t1;
  cout << "Display the heap(t2) in-order: ";
  while (!t2.isEmpty()) {
    cout << t2.remove() << " ";
  }
  cout << endl << endl;
  
  cout << "Display the heap(t1) in-order: ";
  while (!t1.isEmpty()) {
    cout << t1.remove() << " ";
  }
  cout << endl << endl;
  cout << "Because original t2 has different size with t1" << endl;
  cout << "The final output is same,";
  cout<<" so overload assignment operator is texted" << endl;
  
  cout << endl << endl;
  
  cout << "5. Resize function text : " << endl;
  
  for (int i = 0; i < MAX_SIZE_SED; i++) {
    randomNum = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    //cout << randomNum << " ";
    t1.insert(randomNum);
  }
  cout << "Display the heap(t1) in-order: ";
  while (!t1.isEmpty()) {
    cout << t1.remove() << " ";
  }
  cout << endl << endl;
  cout << "From the output: insert value is more";
  cout<<" than t1's original capacity" << endl;
  cout << "So it has been resized ";
  cout<<"it means resize funtion has been texted " << endl;
  cout << endl << endl;
  
  cout << "5. Flush function text : " << endl;
  t1.insert(9);
  t1.insert(11);
  t1.insert(9);
  t1.insert(20);
  t1.insert(34);
  t1.insert(13);
  t1.insert(8);
  t2 = t1;
  cout << "Use copy constructor to display t1 :" << endl;
  while (!t2.isEmpty()) {
    cout << t2.remove() << " ";
  }
  cout << endl << endl;
  t1.flush(9);
  cout << "Display t1 after using flush function :" << endl;
  while (!t1.isEmpty()) {
    cout << t1.remove() << " ";
  }
  cout << endl << endl;
  cout << "All the target 9 has been flushed";
  cout<<" so flush funtion has been texted" << endl;
  
}
