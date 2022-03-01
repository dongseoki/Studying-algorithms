#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main(void) {
	vector<int> v = { 1,2,3,4 };
	//for (auto iter = v.begin(); iter != v[2]; iter++) {
	//	cout << *iter << " ";
	//}
	cout << *max_element(v.begin()+2, v.end());



	return 0;
}