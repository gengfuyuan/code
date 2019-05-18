#include<iostream>
#include<string>
#include<cctype>
#include<iomanip>

using namespace std;


const int SIZE = 12;
const int SMALL = 10;
const int LARGE = 99;
const char YES = 'y';
const int INDEX_COL = 5;
const int VALUE_COL = 6;
int maximum(const int arr[], int arrsize);//return the maximum value in the array
       
int main()
{
  int num;
  int count = 0;
  char answer = YES;
  int arr[SIZE];



  cout << endl << endl;
  cout << "Welcome message"<<endl;
  while (tolower(answer) == YES) {
	  count = 0;
		while (count < SIZE) {
			cout << "PLease input odd numbers: ";
			cin >> num;
			if (num >= SMALL && num <= LARGE && num % 2 == 1) {
				arr[count] = num;
				count++;
			}
		}

		cout << "value   index "<<endl;
		for (int j = 0; j < SIZE; j++) {
			cout << setw(INDEX_COL) << arr[j] << setw(VALUE_COL) << j << endl;
		}

		//int num = 0;
		//cout << getNum() << endl;
		num = maximum(arr, SIZE);
		cout << "Maximm value in the array:" << arr[num] << " And index is  " << maximum(arr, SIZE) << endl;
		cout << "If user want to continue ,input yes:  ";
	    cin >> answer;
	}
	cout << endl << "End the lab 1" << endl << endl;
	return 0;

   }


int maximum(const int arr[], int arrsize) {
  int index=0;
	int temp = arr[0];
	for (int i = 0; i < arrsize; i++) {
		if (temp < arr[i]) {
			temp = arr[i];
			index = i;
		}
	}
	return index;
}












