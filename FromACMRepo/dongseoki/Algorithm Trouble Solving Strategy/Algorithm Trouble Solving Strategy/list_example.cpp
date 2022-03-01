#include <iostream>
#include <list>
using namespace std;

int main(void) {
	list<int> l;
	l.push_back(5);
	l.push_back(5);
	l.push_front(3);
	l.push_front(3);
	l.pop_back();
	l.pop_front();

	cout << l.front() << " " << l.back() << endl;
	l.sort();
	l.reverse();

}