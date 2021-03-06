//fuyuan.geng
//lab3.cpp


#include<iostream>
//#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;
const int SMALL = 0;
const int LARGE = 10;
const int MIN_VALUE = 0;
const int MAX_VALUE = 101;


struct Node {
  int key;
  Node* left; 
  Node* right;
};

bool insert(Node*& root, int k);//use to remove dullplicate numbers
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
void deleteAll(Node*& root);



int main() {
  //int  arr[10];
  int randomnum;
  int seed = time(0);
  srand(seed);
  Node* root = nullptr;
  
  for (int i = SMALL; i < LARGE; i++) {
    randomnum = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    insert(root, randomnum);
  }
  
  
  cout <<"Inorder:"<< endl;
  inorder(root);
  cout << "\n preorder: "<<endl;
  preorder(root);
  cout <<"\n postorder: "<< endl;
  postorder(root);
  cout <<"\n delete all"<< endl;
  deleteAll(root);
  postorder(root);
  cout << endl;
  
  
  system("pause");
  return 0;
}

bool insert(Node*& root, int k) {
  if (root == nullptr) {
    root = new Node;
    root->key = k;
    root->left = nullptr;
    root->right = nullptr;
    return true;
  }
  else if (root->key ==k)
    return false;
  else if (root->key > k)
    insert(root->left, k);
  else
    insert(root->right, k);
  return true;
}


void inorder(Node* root) {
  if (root != nullptr) {
    inorder(root->left);
    cout << root->key<<" ";
    inorder(root->right);
  }
}

void preorder(Node* root) {
  if (root!= nullptr) {
    cout << root->key<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(Node* root) {
  if (root != nullptr) {
    preorder(root->left);
    preorder(root->right);
    cout << root->key << " ";
  }
}

//we need to use psotorder right here
void deleteAll(Node*& root) {
  if (root!= nullptr) {
    deleteAll(root->right);
    deleteAll(root->left);
    delete root;
    root = nullptr;
  }
}
