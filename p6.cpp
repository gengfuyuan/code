// p6.cpp
// Fuyuan Geng
//Due:3.14 11:59pm


# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <ctime>
# include <vector>


using namespace std;

bool multipleFive(int data);
// Point: determine if data is multiple of five
// Precondition: some data store in vector
/* Postcondition: use multiple Five function to 
   determin if data is multiple of five then
   remove  it from text vector
*/


bool prime(int data);
// Pint: determine if the data inside vector is prime number

// Precondition: some data store in vector

// Postcondition: use prime function to 
//determin if data is prime number then
//remove  it from text vector

const int SMALL = 1;
const int LARGE = 999; //range is three digits
const int TOTALNUMBERS = 1000; // insert 1000 random integer
const int COLS = 20;       // print 20 integers per line

int main()
{   
  // first create text vector
  std::vector<int> test;
  
  //use random generator to insert random numbers inside vector 
  int randomNum;
  srand(time(0));
  
  for (int i = 0; i < TOTALNUMBERS; i++) {
    randomNum = rand() % (LARGE-SMALL) + SMALL;
    test.push_back(randomNum);
  }
  
  cout << endl << "** Project--p6 **" << endl << endl;;
  
  //question one insert 1000 random numbers inside vector
  cout << endl << "1(a):  Insert 1000 random integer into the vector." << endl;
  cout << endl << "1(b):  List all the number : " << endl << endl;
  
  //use while loop to print all data inside text vector
  int count = 1;
  while (count <= TOTALNUMBERS) {
    int index = count - 1;
    cout << test.at(index) << "  ";
		if (count % COLS == 0)
          cout << endl;
		count++;
  }
  
  cout << endl << endl;
  
  
  //Question two :remove all the multiple of five
  cout << "2(a):  Remove the multiple of 5." << endl << endl;
  
  int size = TOTALNUMBERS;//used to be count 
  int pos = 0;
  while (pos < size) {
    if (multipleFive(test.at(pos))) {
      test.erase(test.begin() + pos);
      //test.erase( pos);
      size--;
    }
    else {
      pos++;
    }
  }
  
  //use size to be range 
  //size=total numbers-number of multiple five
	//print all the data when remove multiple five 
  cout << "2(b):  List all the number in the vector: " << endl << endl;
  count = 1;
  while (count <= size) {
    int index = count - 1;
    cout << test.at(index) << "  ";
    if (count % COLS == 0)
      cout << endl;
    count++;
  }
  
  cout << endl << endl;
  
  //question three: remove prime number in the vector
  cout << "3(a):  Remove all prime numbers between 2 numbers of mixed parity.";
  cout << endl << endl;
  
  //need to compare sum % 2
  pos = 1;
  while (pos < size -1) {
    if (prime(test.at(pos)) &&
        (test.at(pos - 1) + test.at(pos + 1)) % 2 != 0) {
      test.erase(test.begin() + pos);
      size--;
      pos = 1;
    }
    else {
      pos++;
    }
  }
  
  cout << "3(b):  List all the elements in the vector: " << endl << endl;
  count = 1;
  while (count <= size) {
    int i = count - 1;
    cout << test.at(i) << "  ";
    if (count % COLS == 0)
      cout << endl;
    count++;
  }
  
  
  test.clear();
  
  if (test.empty())
    cout << endl << endl;
  cout << "Now vector is empty and work is done." << endl << endl;
  
  return 0;
}


bool multipleFive(int data)
{    
  if (data % 5 == 0)
    return true;
  else
    return false;
}


bool prime(int data)
{
  if (data <= 0) {
    return false;
  }
  else if (data==1 ) {
    return true;
  }
  else if (data == 2) {
    return true;
    
  }
  else if (data == 3) {
    return true;
  }
  else{
    for (int i = 2; i < data; i++) {
      if (data % i == 0) {
        return false;
      }
    }
    return true;
  }
} 

