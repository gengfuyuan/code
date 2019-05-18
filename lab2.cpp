
// fuyuan.geng
// lab2.cpp

#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

const string FILENAME = "/home/fac/sreeder/class/cs2430/lab2.dat";

void insertInOrder(Node*& head, int dat);
    

// inserts d into h in numerical order
// post: h may be changed

void printList(Node* head);

// prints all data on h to the screen in a column

void delList(Node*& head);

// post: each node of h deleted

int main()
{
  Node* head = nullptr;
  ifstream inFile;
  int num;

  inFile.open(FILENAME);
  if (inFile.fail()){
	cout << "file problem...exiting program...press enter...";
	cin.get();
  }

  while (inFile >> num)
	insertInOrder(head, num);

  inFile.close();

  cout << endl;
  printList(head);

  cout << endl << endl;
  
  delList(head);
	
  return 0;
}

void insertInOrder(Node*& head, int data)
{
  // complete this function
  Node* tmp=new Node;
  tmp->data=data;
  Node* ptr;
  if(head==nullptr || head->data >tmp->data){
    tmp->next=head;
    head=tmp;
  }else{
    ptr=head;
    while(ptr->next!=nullptr && ptr->next->data <tmp->data){
      ptr=ptr->next;
    }
      tmp->next=ptr->next;
      ptr->next=tmp;
    }
  }

void printList(Node* head)
{
  // complete this function
  while(head!=nullptr){
    cout<<head->data<<endl;
    head=head->next;
  }
}

void delList(Node*& head)
{
  // complete this function
  Node* delPtr;
  while(head!=nullptr){
    delPtr=head;
    head=head->next;
    delete delPtr;
  }
}
