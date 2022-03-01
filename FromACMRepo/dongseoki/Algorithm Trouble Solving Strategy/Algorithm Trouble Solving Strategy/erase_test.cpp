#include <iostream>
#include <vector>

using namespace std;


int main(void) {
	vector<int> v = { 1,2,3,4,5 };
	v.erase(v.begin() + 2);
	return 0;
}