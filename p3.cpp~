//fuyuan.geng
//p3.cpp

#include <iostream>
#include <sstream>
#include <fstream>
#include <ostream>
#include "tree.h"
#include <cstdlib>
#include<ctime>

using namespace std;


const int NUMBER = 20;
const int val_1 = 99;  //used to find if the value in the tree node
const int val_2 = 9;  


using namespace std;

int main() {

	tree t1; //text 1=tree 1
	
	//create a array with 20 numbers , you can make the size over 20
	int arr[NUMBER] = { 27,28,55,55,99,110,23,46,88,66,33,44,77,77,21,91,90,96,63,21 };
	cout << endl;

	//inserts numbers in the array, it will also insert in the binary search tree

	cout << "1.Insert function text :  "<<endl;
	cout << "Inserting " << NUMBER << " numbers: ";
	for (int i = 0; i < NUMBER; i++) {
		cout << arr[i] << " ";  //prints the values from array
		t1.insertP(arr[i]);    //use insert function to find dulplicate number
	}
	cout << endl << endl;


	//test nonRecurInorder function
	cout << "2. nonRecurInorder function(t1)  text : ";
	t1.nonRecurInorder();
	cout << endl << endl;

	//test preorderPub function
	cout << "3. preorderPub fucntion(t1)  text : ";
	t1.preorderPub();
	cout << endl << endl;

	// text copy constructor
	cout << "4. copy constructor text : "<<endl<<endl;
	tree t2(t1); //copy of t1 into t2
	cout << "Display the tree(t1) in-order: ";
	t1.nonRecurInorder();  
	cout << endl <<endl;
	cout << "Display the tree(t2) in-order: ";
	t2.nonRecurInorder();
	cout << endl << endl;
	cout << "because t1=t2, so copy constructor is work"<< endl << endl;


//text findKey function
	cout << "5. findKey function text: ";
	cout << "Example 1: " << val_1 << "     "<< "Example 2: " << val_2 << endl<<endl;
if (t1.findKey(val_1))
		cout << val_1 << "was found."<<endl;
	else {
		cout << val_1 << " was not found." << endl;
	}
if (t1.findKey(val_2))
		cout << val_2 << " was found."<<endl;
	else {
		cout << val_2 << " was not found,"<<endl;
	}
cout << endl << endl;

	


//text findMax function
	cout << "6. findMax function text: "<<endl;
	cout << "Maximum value is : ";
	cout << t1.findMax() << endl<< endl;



	//text find height. 
	cout << "7.findheight function text:  "<<endl;
	cout << "Height of tree is : ";
	cout << t1.findheight()<<endl<<endl;



	//text overloaded assigment operator

	cout << "8. overloaded assigment operator text : " << endl;
	tree t3;
	t3.insertP(15);
	t3.insertP(30);
	//tree t3(t1);//if t1 and t3 not the same,then we can text operator
	cout << "original t3 output : ";
	t3.nonRecurInorder();
	cout<< endl << endl;

	cout << "make t3 copy from t1,then output the data in t3" << endl;
	t3 = t1;

	cout << "output new t3 data : ";
	t3.nonRecurInorder();
	cout << endl << endl;
	cout << "output t1 data : ";
	t1.nonRecurInorder();
	cout << endl;
	cout << "Because t3 output is equal to t1, so operator is work" << endl << endl;

	return 0;
}

