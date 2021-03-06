//fuyuan.geng
//lab4.cpp

#include<iostream>
//#include<fstream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

const int MIN_VALUE = 0;
const int MAX_VALUE = 101;
const int MAX_SIZE = 20;
const int COL = 4;
const int NUMBER = 2;

void insert(int h[], int& curSize, int value);
//insert value into heap

int remove(int h[], int& curSize);
//remove the min value in the heap ,and also output the value

void percolateDown(int h[], int hole, int curSize);
//find the minheap in the heap. 





int main(){
  
  int h[MAX_SIZE] = { 0 };
  int currentSize = 0;
  int val;
  int size;
  srand(time(0));
  
  for (int j = 0; j < NUMBER; j++) {
    for(int i=0;i<MAX_SIZE;i++){
      val = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
      insert(h, currentSize, val);
    }
    cout << endl << endl;
    size = currentSize;
	for (int i =0; i <size; i++) {
      cout << setw(COL)<< remove(h, currentSize)<<" ";
      if ((i + 1) % 5 == 0)
        cout << endl;
	}
	cout << endl << endl;
    
  }
  return 0;
}


void insert(int h[], int&currentSize, int value) {
  currentSize++;
  
  int hole = currentSize;
  while (hole > 1 && value < h[hole / 2]) {
    h[hole] = h[hole / 2];
    hole = hole / 2;
  }
  h[hole] = value;
}



int remove(int h[], int& curSize) {
  int min = h[1];
  h[1] = h[curSize];
  curSize--;
  percolateDown(h, 1, curSize);
  
  return min;
  
}

void percolateDown(int h[], int hole, int curSize) {
  int temp = h[hole];
  while ((hole * 2 <= curSize &&  temp > h[hole * 2])||(hole * 2 + 1 <= curSize && temp > h[hole * 2 + 1])) {
    if (hole * 2 + 1 <= curSize && h[hole * 2 + 1] < h[hole * 2]) {
      h[hole] = h[hole * 2 + 1];
      hole = hole * 2 + 1;
    }
    else {
      h[hole] = h[hole * 2];
      hole = hole * 2;
    }
  }
  h[hole] = temp;
}
