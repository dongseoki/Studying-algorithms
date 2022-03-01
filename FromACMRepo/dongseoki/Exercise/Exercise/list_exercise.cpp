#include <list>
#include <iostream>

using namespace std;

int main(void) {

	list<int> lt;
	lt.push_back(1);
	lt.push_front(8);
	cout <<  lt.front()<<"\n";
	cout << "hi";

}