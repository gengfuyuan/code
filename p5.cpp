//Fuyuan Geng
//p5.cpp

#include <cctype>
#include <iostream>
#include <fstream>
#include<string>

using namespace std;

struct Node {
  string word;
  Node * next;
  int count;
};


unsigned hashFunction(string word);
//pre-condition: before transfer, it is a string
//post-condition: it returns string's hash value


int store(string word,Node* hashTable[]);
//pre-conditon: this function take string and store it in hashtable 
//post-conditon: use store function, insert word into hashtable
//and return collisions inside


int checkCount(string word, Node* hashTable[]);
//pre-condition: find the word's occurences in hashtable
//post-condition: return the number of occurences of the word


string preprocess(string word);
//pre-condition: take word as parameter
//post-condition: return strings greater than 4, and no
//punctuations inside


void deleteFunction(Node* hashTable[]);
//pre-condition: hashtable stores data
//post-condition:delete memory in hashtable, release space

const unsigned MIN_WORD = 4;
const unsigned MAX = 9127;
const string FILENAME = "1342-0.txt";


int main() {
  
  string word;
  string keyWord;
  unsigned totalWords = 0;
  unsigned numOfCollisions = 0;
  double   numOfUniqueWords = 0;
  double   loadFactor = 0;
   
  Node* hashTable[MAX];
  
  //set the hashtable with null
  for (unsigned i = 0; i < MAX; i++) {
    hashTable[i] = nullptr;   
    
  }
  
  //opens  file
  ifstream infile(FILENAME);
  
  if (!infile.is_open()) {
    
    cout << "Can't  open file";
    
  }
  
  
  //reads file 
  //calculates  collisions
  while (infile >> word) {
    
    word = preprocess(word);
    int count = 0;
    
    if (word.length() > 4) {
      
      totalWords++;
      count = store(word, hashTable);
    }
    
    numOfCollisions += count;  
  }
  
  
  
  
  cout << "Number of Collisions: " << numOfCollisions << endl;
  cout << "Number of words: " << totalWords << endl;
  cout << endl << endl;
  
  
  
  //unique words
  for (unsigned i = 0; i < MAX; i++) {
    
    Node* ptr = hashTable[i];
    while (ptr) {
      numOfUniqueWords += 1;
      ptr = ptr->next;
      
    }
  }
  
  
  
  
  
  //load factor
  loadFactor = numOfUniqueWords /MAX;
  cout << "Num of  unique words : " << numOfUniqueWords << endl;
  cout << "Load factor: " << loadFactor << endl;
  cout << endl << endl;
  
  //input word
  cout<<"Input one word: "<<endl;
  cin >> keyWord;
  
  
  while (keyWord != "done") {
    
    keyWord = preprocess(keyWord);
    if (keyWord.length() > 4)
      cout << "The word occurance " << keyWord;
    
    cout<<" is " << checkCount(keyWord, hashTable) << endl;
    
    cout << endl;
    cout << "Continue input or enter done to stop): ";
    cin >> keyWord;
  }
  
  
  
  infile.close();
  cout << endl;
  deleteFunction(hashTable);
  
  return 0;
}



//hash function
//laod factor for the hash table
//hash function
unsigned hashFunction(string word)
{
  unsigned int seed = 13131313; 
  unsigned int hash = 0;
  
  
  
  for (unsigned i = 0; i < word.length(); i++)
	{
      hash = (hash* seed) + word[i];
      
      hash %= MAX;
      
      if (hash < 0)
        hash += MAX;
	}
  
  
  return hash;
}


int store(string newWord, Node* hashTable[])
{
  int index = hashFunction(newWord);
  if (hashTable[index] == nullptr) {
    Node* temp = new Node;   //creates a new hashNode
    temp->count = 1;
    temp->word = newWord;
    temp->next = nullptr;
    hashTable[index] = temp;
    
    return 0;
  }
  else {
    Node* ptr = hashTable[index];
    
    while (ptr->next != nullptr && ptr->word != newWord) {
      ptr = ptr->next;
    }
    if (ptr->word == newWord) {
      ptr->count++;
      return 0;
      
    }
    else {
      Node* temp = new Node;
      temp->count = 1;
      temp->word = newWord;
      temp->next = nullptr;
      ptr->next = temp;
      return 1;
      
    }
    
  }
  
  return 0;
  
  
}

//use count to find the number of same word in the file
int checkCount(string word, Node* hashTable[]) {
  int index = hashFunction(word);  
  Node* temp = hashTable[index];
  if (temp == nullptr)
    return 0;
  
  else {
    Node* temp = hashTable[index];
    
    while (temp->next != nullptr && temp->word != word) {
      temp = temp->next;
    }
    if (temp->word == word)
      return temp->count;
    else
      
      return 0;
  }
  
}


string preprocess(string word)
{
  string newWord;           
  unsigned pos;
  
	if (word.length() > 4) {
      for (unsigned i = 0; i < word.length(); i++) {               
        if (isdigit(word.at(i)))
          return newWord;   
        
        word[i] = tolower(word[i]);
      }
      
      pos = 0;
      
      while (word.length() > 4 && !isalpha(word.at(pos))) {               
        word.erase(pos, 1);
      }
      
      
      while (word.length() > 4 && !isalpha(word.at(word.length() - 1))) { 
        word.erase(word.length() - 1, 1);
      }
      
      return  newWord + word;
      
	}
    
	return newWord;
}


void deleteFunction(Node* hashTable[])
{
  for (unsigned i = 0; i < MAX; i++) {
    Node* del;
    while (hashTable[i] != nullptr) {
      del = hashTable[i];
      hashTable[i] = hashTable[i]->next;
      delete del;
    }
  }
}



