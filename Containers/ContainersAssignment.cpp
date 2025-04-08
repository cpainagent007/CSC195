
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <map>

using namespace std;

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

int main(){
	sec1();
	sec2();
	sec3();
	sec4();
	return 0;
}