//fuyuan.geng
//tree.h


#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class tree {
  
 private:
  struct Node{
    int data;
    Node* left;
    Node* right;
    int count;
    Node(int k = int()) {
      data=k;
      left = 0;
      right=0;
    }
	
  };
  
  
  Node* root;
  
  Node * makecopy(Node* root);
  
  int height(Node* root);
  void preorder(Node* root);
  void deleteAll(Node*& root);
  bool insert(Node*& root, int k);
  bool key(Node* root, int k);
  int max(Node* root, int& max);
  
 public:
  tree();//constuctor
  ~tree();//destructor
  tree(const tree& rhs);//copy constructor
  tree& operator=(const tree& rhs);//overload  assignment operator
  
  
  bool insertP(int k);
  void nonRecurInorder();
  int findMax();
  bool findKey(int k);
  int findheight();
  void preorderPub();
  
  
  
  //find key
  //find max key
  //find height 
  //pre-order(recursively)
  //In-order(iteratively)
  
  
};

