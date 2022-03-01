#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int n;


using namespace std;
bool compare_a(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second > b.second;
	else
	{
		return a.first < b.first;
	}
}
bool compare_b(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first > b.first;
	else
	{
		return a.second < b.second;
	}
}
int main(void) {
	cin >> n;
	vector<pair<int, int>> vec(n, make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		int num1;
		int num2;
		cin >> num1;
		cin >> num2;
		vec[i].first = num1;
		vec[i].second = num2;
	}

	sort(vec.begin(), vec.end(),compare_a);

	for (int i = 0; i < n; i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
	for(int j=0;j)
}