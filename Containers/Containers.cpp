
/*#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <map>

using namespace std;

int main() {
	string partition = "----------";

	//array

	int i = 0xff;
	array<int, 5> array = { 1, 2, 3, 4, 5};

	cout << &i << endl;
	
	//----------
	cout << partition << endl;
	//----------

	cout << (void*)(&array[0]) << endl;
	cout << (void*)(&array[1]) << endl;
	cout << (void*)(&array[2]) << endl;
	cout << (void*)(&array[3]) << endl;
	cout << (void*)(&array[4]) << endl;

	cout << array.size() << endl;

	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << endl;
	}

	//----------
	cout << partition << endl;
	//----------

	//vector

	vector<int> vector = { 1, 2, 3, 4, 5 };
	vector.push_back(6);

	cout << vector.size() << endl;
	cout << vector.capacity() << endl;

	//----------
	cout << partition << endl;
	//----------

	//list

	list<int> list = { 1, 2, 3, 4, 5 };
	list.push_back(6);
	list.insert(list.begin(), 0);

	//----------
	cout << partition << endl;
	//----------

	map<string, int> map;

	map["Test"] = 100;
	map["Test2"] = 150;

	cout << map["Test"] << endl;

	//----------
	cout << partition << endl;
	//----------

	cout << "Hello World!" << endl;

	return 0;
}
*/