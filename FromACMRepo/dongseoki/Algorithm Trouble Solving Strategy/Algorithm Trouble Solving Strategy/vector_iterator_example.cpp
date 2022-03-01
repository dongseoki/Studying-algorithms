using namespace std;
#include <iostream>
#include <vector>

void hi(void) {

}

int main(void) {
	vector<int> my(0);
	vector<int>::iterator itr;
	
	my.push_back(10);
	my.push_back(20);
	my.push_back(30);
	my.push_back(40);
	my.push_back(50);
	my.push_back(60);

	hi();

	for (itr = my.begin(); itr != my.end(); itr++) {
		cout << "°ª : " << *itr << "\n";
	}

}