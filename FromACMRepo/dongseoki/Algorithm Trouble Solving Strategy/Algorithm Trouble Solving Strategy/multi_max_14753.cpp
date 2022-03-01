#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<int> m_vec;

vector<int> candidate;
int main(void) {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int test = 0;
		cin >> test;
		vec.push_back(test);
	}
	sort(vec.begin(), vec.end());


	if (vec.size() >= 6) {
		candidate.push_back(vec[0]);
		candidate.push_back(vec[1]);
		candidate.push_back(vec[2]);
		candidate.push_back(vec[vec.size()-1]);
		candidate.push_back(vec[vec.size() - 2]);
		candidate.push_back(vec[vec.size() - 3]);
	}
	else {
		candidate = vec;
	}
	int max = numeric_limits<int>::min();

	for (int i = 0; i < candidate.size(); i++) {
		for (int j = i+1; j < candidate.size(); j++) {
			for (int k = j + 1; k < candidate.size(); k++) {
				int mul = candidate[i] * candidate[j] * candidate[k];
				//cout << mul << "\n";
				if (max < mul)
					max = mul;
			}
		}
	}
	for (int j = 0; j < candidate.size(); j++) {
		for (int k = j + 1; k < candidate.size(); k++) {
			int mul = candidate[j] * candidate[k];
			//cout << mul << "\n";
			if (max < mul)
				max = mul;
		}
	}

	cout << max << "\n";

	//cout << "\n\n";
	//for (int i = 0; i < candidate.size(); i++) {
	//	cout << candidate[i] << " ";
	//}
	//cout << "\n\n";
	//for (int i = 0; i < vec.size(); i++) {
	//	cout << vec[i] << " ";
	//}

}