#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<string> s_vec(n, "");
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s_vec[i] = str;
	}

	sort(s_vec.begin(), s_vec.end());
	vector<pair<string, int>> cards;
	string comp_s = "----";
	int count = 0;
	for (int i = 0; i < n; i++) {
		
		if (comp_s.compare(s_vec[i]) != 0) {
			cards.push_back(make_pair(s_vec[i],1));
			comp_s = s_vec[i];
		}
		else {
			int s = cards.size();
			cards[s - 1].second += 1;
		}
	}

	for (int i = 0; i < cards.size(); i++) {
		cout<<cards[i].first << " " << cards[i].second << "\n";
	}

	return 0;
}