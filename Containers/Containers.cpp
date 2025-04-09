
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

// ----- Assignment -----

void sec1() {
	array<string, 7> array1 = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	for (int i = 0; i < array1.size(); i++) {
		cout << array1[i] << endl;
	}
}

void sec2() {
	vector<int> vector1 = { 1, 2, 3, 4, 5 };
	vector1.push_back(6);
	vector1.push_back(7);
	vector1.pop_back();

	for (int i = 0; i < vector1.size(); i++) {
		cout << vector1[i] << endl;
	}
}

void sec3() {
	list<string> list1 = { "Apple", "Banana", "Orange" };
	list1.push_back("Grape");
	list1.push_front("Mango");
	list1.remove("Apple");

	for (string fruit : list1) {
		cout << fruit << endl;
	}
}

void sec4() {
	map<string, int> map1;
	map1["Bread"] = 1;
	map1["Milk"] = 2;
	map1["Eggs"] = 3;
	map1["Bread"] = 4;

	for (auto it = map1.begin(); it != map1.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
	}
}

int main2() {
	sec1();
	sec2();
	sec3();
	sec4();
	return 0;
}

// ----- Assignment End -----

unsigned int getHash(string str) {
	unsigned int hash = 0;
	for (char c : str) {
		hash = hash * 31 + (int)c;
	}
	return hash;
}

int main() {
	string partition = "----------";

	//array

	int i = 0xff;
	array<int, 5> array1 = { 1, 2, 3, 4, 5 };

	cout << &i << endl;

	//----------
	cout << partition << endl;
	//----------

	cout << (void*)(&array1[0]) << endl;
	cout << (void*)(&array1[1]) << endl;
	cout << (void*)(&array1[2]) << endl;
	cout << (void*)(&array1[3]) << endl;
	cout << (void*)(&array1[4]) << endl;

	cout << array1.size() << endl;

	for (int i = 0; i < array1.size(); i++) {
		cout << array1[i] << endl;
	}

	//----------
	cout << partition << endl;
	//----------

	//vector

	vector<int> vector1 = { 1, 2, 3, 4, 5 };
	vector1.push_back(6);

	cout << vector1.size() << endl;
	cout << vector1.capacity() << endl;

	//----------
	cout << partition << endl;
	//----------

	//stack

	stack <int> stack1;
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	cout << stack1.top() << endl;
	stack1.pop();
	cout << stack1.top() << endl;

	/*
	for (auto iter = stack1.; iter != stack1.top(); iter++) {
		cout << *iter << endl;
	}
	*/


	//----------
	cout << partition << endl;
	//----------

	//list

	list<int> list1 = { 1, 2, 3, 4, 5 };
	list1.push_back(6);
	list1.insert(list1.begin(), 0);

	for (auto iter = list1.begin(); iter != list1.end(); iter++) {
		cout << *iter << endl;
	}

	//----------
	cout << partition << endl;
	//----------

	//map (ordered)

	map<string, int> map1;

	map1["Test"] = 100;
	map1["Test2"] = 150;

	cout << map1["Test"] << endl;

	for (auto iter = map1.begin(); iter != map1.end(); iter++) {
		cout << iter->first << ": " << iter->second << endl;
	}

	//----------
	cout << partition << endl;
	//----------

	//map (unordered)

	unordered_map<string, string> map2;

	map2["Colton"] = "Clark";
	map2["Tristin"] = "Clifford";
	map2["Nick"] = "Alabre";

	cout << map2["Colton"] << endl;

	//----------
	cout << partition << endl;
	//----------

	string name = "Colton";
	int hash = getHash(name);
	cout << hash << endl;

	int data[10];
	data[hash % 10] = 83686;
	hash = getHash("Tristin");
	cout << data[hash % 10] << endl;

	//----------
	cout << partition << endl;
	//----------

	cout << "Hello World!" << endl;

	//----------
	cout << partition << endl;
	//----------

	main2();

	return 0;
}