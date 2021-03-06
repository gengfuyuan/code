#include <iostream>
#include <fstream>
#include<iomanip>
#include<string>

using namespace std;

struct population {
  int censusCount;
  string place;
  
  
};
const int MAX = 3200;
const int  PRINT_MAX = 10;
const int  COL = 6;
const string INPUTFILE= "/home/fac/sreeder/class/cs2430/countyPop.dat";
//int comp;

void mergeSort(population set[],population temp[],int first,int last );
void merge(population set[], population temp[],
           int leftPos, int rightPos,int rightEnd);
void printBegEnd(const population set[], int numRecords);



void mergeSort(population set[], population temp[],int first, int last) {
  int mid;
  if (first < last)
	{
      mid = (first + last) / 2;
      mergeSort(set,temp ,first, mid);
      mergeSort(set, temp,mid + 1, last);
      merge(set,temp, first, mid+1, last);
      
	}
}

void merge(population set[], population temp[],
           int leftPos, int rightPos, int rightEnd)
{
  int leftEnd = rightPos - 1;
  int tempPos = leftPos;
  int numElements = rightEnd - leftPos + 1;
  //int comp;
  
  
  while (leftPos<=leftEnd && rightPos<=rightEnd) {
    //comp++;
    if (set[leftPos].censusCount<=set[rightPos].censusCount)
      temp[tempPos++] = set[leftPos++];
    else
      temp[tempPos++] = set[rightPos++];
    
    // Copy rest of the first half.
    while (leftPos <= leftEnd)
      temp[tempPos++] = set[leftPos++];
    
    // Copy rest of the second half.
    while (rightPos <= rightEnd)
      temp[tempPos++] = set[rightPos++];
    
    // Copy temp array.
    for (int i = 0; i < numElements; i++, rightEnd--)
      set[rightEnd] = temp[rightEnd];
    
    //return comp;
  }//merge
  
}//MergeSort

void printBegEnd(const population set[], int numRecords) {
  cout << endl << endl;
  
  cout << "Begging of list ..." << endl;
  for (int i = 0; i < PRINT_MAX; i++)
    cout << right << setw(COL) << set[i].censusCount << left
         << set[i].place << endl;

  cout<<endl;
  cout<<" End of list..."<<endl;
  for(int i=numRecords-PRINT_MAX;i<numRecords;i++)
    cout<<right<<setw(COL)<<set[i].censusCount<<left
        <<set[i].place<<endl;
  cout<<endl<<endl;
}



int main() {
  
  ifstream inputFile;
  population list[MAX];
  population tempList[MAX];
  int count = 0;
  
  
  inputFile.open(INPUTFILE);
  
  //string temp;
  
  if (inputFile.fail()) {
    cout << "unable to open file...";
    cin.get();
    return 0;
    
  }
  
  while (inputFile >> list[count].censusCount) {
    getline(inputFile, list[count].place);
    count++;
  }
  inputFile.close();
  
  printBegEnd(list, count);
  mergeSort(list, tempList, 0, count - 1);
  printBegEnd(list, count);
  return 0;
}
