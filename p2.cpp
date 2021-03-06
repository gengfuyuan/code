// fuyuan.geng
// p2.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>   // For rand and srand  
#include <ctime> 

using namespace std;

//srand(time(0));
const int COL = 6;
const int SMALL = 50;
const int LARGE = 80;
const int MIN_VALUE = 0;
const int MAX_VALUE = 101;


struct Node
{
  int data;
  Node* next;
};



void insertInOrder(Node*& head, int data);


// inserts d into h in numerical order
// post: h may be changed

void printList(Node* head);
// prints all data on h to the screen in a column

void delList(Node*& head);
void deletenode(Node *&head, int data);

// post: each node of h deleted
int smallest(Node* head);
int largest(Node* head);
int middle(Node* head);

//function to print values into file
void printToFile(Node* h, ofstream& fileName);





int main()
{
  Node* head = nullptr;
  int seed = time(0);
  srand(seed);
  int num;
  int max;
  int min;
  int mid;
  
  ofstream outfileA;
  ofstream outfileB;
  
  //outfileA.open("P2OutputA.txt");
  
  cout << "Question a: " << endl;
  cout << "Construct a linked list of at least size 50, but no more than 80" << endl;
  for (int i = SMALL; i < LARGE; i++) {
    num = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    
    insertInOrder(head, num);
  }
  // cout << "The size of linked list is at least size 50, but no more than 80" << endl;
  
  
  
  cout << "Question b: " << endl;
  cout << "Traverse the linked list, storing values in an output file called ��OutputA.txt��" << endl;
  printList(head);
  outfileA.open("OutputA.txt");
  outfileA << "The values are: " <<endl;
  Node* tmp = head;
  
  printToFile(tmp, outfileA);
  
  
  cout << "Question c: " << endl;
  cout << "Delete the smallest element of the linked list " << endl;
  min = smallest(head);
  deletenode(head, min);
  cout << endl;
  printList(head);
  cout << endl;
  
  
  cout << "Question d: " << endl;
  cout << "Delete the largest element of the linked list " << endl;
  max = largest(head);
  deletenode(head, max);
  printList(head);
  cout << endl;
  
  
  cout << "Question e: " << endl;
  cout << "Delete any value from the ��middle�� of the linked list (not smallest or largest" << endl;
  mid = middle(head);
  deletenode(head, mid);
    cout << endl;
  
  cout << "Question f: " << endl;
  cout << "Traverse the updated linked list, storing values in an output file called ��OutputB.txt��" << endl;
  outfileB.open("OutputB.txt");
  tmp = head;
  printToFile(tmp, outfileB);
  
  printList(head);
  cout << endl;
  cout << " " << endl;
  outfileA.close();
  outfileB.close();
  
  system("pause");
  return 0;
  
}

void insertInOrder(Node*& head, int data)
{
  // complete this function
  Node* tmp = new Node;
  tmp->data = data;
  Node* ptr;
  if (head == nullptr || head->data > tmp->data) {
    tmp->next = head;
    head = tmp;
  }
  else {
    ptr = head;
    while (ptr->next != nullptr && ptr->next->data < tmp->data) {
      ptr = ptr->next;
    }
    tmp->next = ptr->next;
    ptr->next = tmp;
  }
}

void printList(Node* head)
{
  // complete this function
  while (head != nullptr) {
    cout << head->data << endl;
    head = head->next;
  }
}

void delList(Node*& head)
{
  // complete this function
  Node* delPtr;
  while (head != nullptr) {
    delPtr = head;
    head = head->next;
    delete delPtr;
  }
}

//Delete the smallest element of the linked list
int smallest( Node* head)
{
  int min = MAX_VALUE;
  while (head != nullptr) {
    if (min > head->data)
      min = head->data;
    
    head = head->next;
  }
  return min;
}

//d.Delete the largest element of the linked list
int largest( Node* head)
{
  int max = MIN_VALUE;
  while (head != nullptr) {
    if (max < head->data)
      max = head->data;
    head = head->next;
  }
  return max;
}


int middle( Node *head)
{
  Node *slow_ptr = head;
  Node *fast_ptr = head;
  Node *prev=new Node; 
  while (fast_ptr != nullptr && fast_ptr->next != nullptr)
	{
      fast_ptr = fast_ptr->next->next;
      prev = slow_ptr;
      slow_ptr = slow_ptr->next;
	}
  prev->next = slow_ptr->next;
  delete slow_ptr;
  return prev->data;
}

void deletenode(Node*& head, int data) {
  Node *ptr=new Node;
  Node* pre=new Node;
  
  if (head == nullptr)
    return;
  
  if (head->data == data) {
    ptr = head->next;
    delete head;
    head = ptr;
  }
  else {
    ptr = head;
    
    while (ptr != nullptr && ptr->data != data) {
      pre = ptr;
      ptr = ptr->next;
    }
    
    if (ptr) {
      pre->next = ptr->next;
      delete ptr;
    }
  }
}

void printToFile(Node* h, ofstream& fileName)
{
  Node* tmp = h;
  int count = 0;
  while (tmp != nullptr) {
    if (count < COL) {
      fileName << tmp->data << "  ";
      tmp = tmp->next;
      count++;
    }
    else {
      cout << endl;
      count = 0;
    }
    
  }
  
  fileName << endl;
  
}
