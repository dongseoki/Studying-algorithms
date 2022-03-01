#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//i, new_v, w_size,weak,dist
bool is_OKcheck_weak_point(int inputnum, vector<int> & new_v,int w_size , vector<int>& dist) {
	int count = 0;
	
	int idx = 0;
	while(true){
		if (idx >= w_size)
			return true;
		// 모든 취약점을 방문했는가?

		if (count == inputnum)
			return false;
		// 투입할 사람수가 더 없다...

		int endpoint = new_v[idx] + dist[count];
		count++;
		while (true) {
			if (idx < w_size && new_v[idx] <= endpoint)
				idx++;
			else
				break;
		}
		// 여기서 new_v[idx] > endpoint 를 기대할수 있음.

	}
}
vector<int> make_new_vector(int start, int w_size, int n, vector<int>& weak) {
	vector <int> new_v;
	for (int i = 0; i < w_size; i++) {
		int num;
		if (((i + start) % w_size) < start)
			num = weak[(i + start) % w_size] + n;
		else
			num = weak[(i + start) % w_size];
		new_v.push_back(num);
	}
	return new_v;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 99;
	

	int d_size = dist.size();
	int w_size = weak.size();

	//test
	/*vector<int> new_v = make_new_vector(3, w_size, n, weak);
	dist = { 4,2,3,1 };
	cout <<is_OKcheck_weak_point(2, new_v, w_size, dist)<<"\n";*/
	

	for (int start = 0; start < w_size; start++) {
		vector<int> new_v = make_new_vector(start, w_size,n, weak);
		/*for (auto item : new_v)
			cout << item << " ";
		cout << "\n";*/

		sort(dist.begin(), dist.end());
		do {
	// 출력
	/*for (int i = 0; i < dist.size(); i++) {
		if (dist[i] == 1) {
			printf("%d ", n[i]);
		}
	}*/
			for (int i = 1; i <= d_size; i++) {
				// is_OKcheck weak point
				if (is_OKcheck_weak_point(i, new_v, w_size,dist) == true) {
					if (answer > i)
						answer = i;
				}
		

			}
		} while (next_permutation(dist.begin(), dist.end()));
	}
	if (answer == 99)
		return -1;
	else
	    return answer;
}

int main(void) {
    vector<int> week = { 1, 5, 6, 10 };
    vector<int> dist = { 1, 2, 3, 4 };
    int n = 12;
    cout << solution(n, week, dist);
}