//fuyuan.geng
//tree.cpp

#include"tree.h"
#include <iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<stack>

using namespace std;

//constructor
tree::tree()
{
	root = 0;
}

//copyconstructor
tree::tree(const tree & aTree) {
	if (aTree.root == nullptr)
		root = nullptr;
	else
		root = makecopy(aTree.root);
}

//This function is used to help copy constroustor
tree::Node* tree::makecopy(Node* root) {
	if (root == nullptr)
		return nullptr;
	else {
		Node* temp = new Node;
		temp->data = root->data;
		temp->left = makecopy(root->left);
		temp->right = makecopy(root->right);
		return temp;
	}
}




//destructor
tree::~tree() {
	deleteAll(root);
}

//used to help destructor
void tree::deleteAll(Node*& root) {
	if (root != nullptr) {
		deleteAll(root->left);
		deleteAll(root->right);
		delete root;
		root = nullptr;//because the condition before is root!=nullptr
	}
}

//operator
tree& tree::operator=(const tree& rhs) {
	if (this != &rhs) {
		deleteAll(root);
		root = makecopy(rhs.root);
	}
	return *this;
}

//max function use recusion, so we need to 
//make a help funtion which should be public
int tree::findMax() {
	int num= 0;
	return max (root, num);
}


//find the max key inside
int tree::max(Node* root, int& max) {
	Node* current = root;
	if (current == nullptr)
		//return false;
		return 0;
	while (current->right != nullptr)
		current = current->right;
	return max = current->data;
	//return true;
}





//insert function use recusion, so we need to 
//make a help funtion which should be public
bool tree:: insertP(int k) {
	 return insert(root, k);
}



//insert data, with no duplicate numbers inside
bool tree::insert(Node*& root, int k) {
	if (root == nullptr) {
		root = new Node;
		root->data = k;
		root->left = nullptr;
		root->right = nullptr;
		return true;
	}
	else if (root->data == k)
		return false;
	else if (root->data > k)
		insert(root->left, k);
	else
		insert(root->right, k);
	return true;
}


//key function use recusion, so we need to 
//make a help funtion which should be public
bool tree::findKey(int k) {
	return key(root, k);
}


//find the key inside
bool tree::key(Node* root, int k) {
	if (root == nullptr) {
		return false;
	}
	else if (root->data == k)
		return true;
	else if (root->data > k)
	return	key(root->left, k);
	else 
	return	key(root->right, k);

}


//Find the height of the node
int tree:: height(Node* root) {
	if (root == nullptr) {
		return 0;
	}

	else {
		int lheight = height(root->left);
		int rheight = height(root->right);
		if (lheight > rheight)
			return 1 + lheight;
		else
			return 1 + rheight;
	}
}

//height function use recusion, so we need to 
//make a help funtion which should be public
int tree::findheight() {
	return  height(root);
}


//inorder function: L N R
void tree::nonRecurInorder() {
	stack<Node*> stack;
	Node* current = root;

	while (current != nullptr || !stack.empty()) {
		if (current != nullptr) {
			stack.push(current);
			current = current->left;
		}
		else {
			current = stack.top();
			stack.pop();
			cout << current->data<<" ";
			current = current->right;
		}
	}
}

//preorder function: N L R
void tree::preorder(Node* root) {
	if (root != nullptr) {
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}


//preorder function use recusion, so we need to 
//make a help funtion which should be public
void tree::preorderPub() {
	return preorder(root);
}



