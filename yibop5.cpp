#include <string>
#include <fstream>
#include <cctype>
#include <iostream>

using namespace std;

struct HNode {
	int count;
	string word;
	HNode* next;
};

const unsigned TOLOWER = 32;
const int MAX = 9056;
const string FILMENAME = "1342-0.txt";

string preProcess(string word);

unsigned hashFunction(string word);

int insert(string word, HNode* hTable[]);


int search(string word, HNode* hTable[]);

void deleteList(HNode* hTable[]);
//it will delete the hTable and each linklist


int main() {

	string word;
	string inWord;
	//declares a pointer array called hTable
	HNode* hTable[MAX];
	unsigned totalWords = 0;
	int collisions = 0;
	double totalUniqueWords = 0;
	//total UniqueWords needs to be double
	double loadFactor = 0;

	//set hTable to nullptr
	for (unsigned i = 0; i < MAX; i++) {
		hTable[i] = nullptr;
	}

	//opens file
	ifstream inFile(FILMENAME);

	if (!inFile.is_open()) {
		cout << "cannot to open file";
	}


	//reads file by word
	//preProcess the word and calculate the number of collisions
	while (inFile >> word) {
		word = preProcess(word);
		int count = 0;
		if (word.length() > 4) {
			totalWords++;
			count = insert(word, hTable);
		}
		collisions += count;
		//updates the total numbere of collison
	}

	//walk through the hTable and return the number of unique words
	for (unsigned i = 0; i < MAX; i++) {
		HNode* ptr = hTable[i];
		while (ptr) {
			totalUniqueWords += 1;
			ptr = ptr->next;
		}
	}
	cout << endl;
	cout << "Number of collisions: " << collisions << endl;
	cout << "Number of words: " << totalWords << endl;
	loadFactor = totalUniqueWords / MAX;
	cout << "Load factor: " << loadFactor << endl;
	cout << "Total unique words: " << totalUniqueWords << endl;
	cout << endl;


	cout << "Enter a word (or press 'Q' to exit): ";
	cin >> inWord;
	while (inWord != "Q") {
		inWord = preProcess(inWord);
		if (inWord.length() > 4)
			cout << inWord << "  appear  " << search(inWord, hTable) << endl;
		cout << endl;
		cout << "(Enter a word again or press 'Q' to exit): ";
		cin >> inWord;
	}
	inFile.close();
	cout << endl;
	deleteList(hTable);
	return 0;
}


string preProcess(string word)
{
	string newWord;
	unsigned pos;
	if (word.length() > 4) {
		for (unsigned i = 0; i < word.length(); i++) {
			if (isdigit(word.at(i)))
				return newWord;   //  newWord is empty
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



//The hashFuction will be called by serch and insert
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


int search(string word, HNode* hTable[])
{
	int index = hashFunction(word);
	HNode* ptr = hTable[index];
	if (ptr == nullptr)
		return 0;
	else {
		HNode* ptr = hTable[index];
		while (ptr->next != nullptr && ptr->word != word) {
			ptr = ptr->next;
		}
		if (ptr->word == word)
			return ptr->count;
		else
			return 0;
	}
}



int insert(string newWord, HNode* hTable[])
{
	int index = hashFunction(newWord);
	if (hTable[index] == nullptr) {
		HNode* newNode = new HNode;
		newNode->count = 1;
		newNode->word = newWord;
		newNode->next = nullptr;
		hTable[index] = newNode;
		return 0;
	}
	else {
		HNode* ptr = hTable[index];
		while (ptr->next != nullptr && ptr->word != newWord) {
			ptr = ptr->next;
		}
		if (ptr->word == newWord) {
			ptr->count++;
			return 0;
		}
		else {
			HNode* newNode = new HNode;
			newNode->count = 1;
			newNode->word = newWord;
			newNode->next = nullptr;
			ptr->next = newNode;
			return 1;
		}
	}
	return 0;
}


void deleteList(HNode* hTable[])
{
	for (unsigned i = 0; i < MAX; i++) {
		HNode* delPtr;
		while (hTable[i] != nullptr) {
			delPtr = hTable[i];
			hTable[i] = hTable[i]->next;
			delete delPtr;
		}
	}
}
