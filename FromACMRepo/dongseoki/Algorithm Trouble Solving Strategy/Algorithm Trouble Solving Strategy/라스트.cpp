#include <iostream>
#include <vector>
#include <algorithm>
#define F(p,q,r) for(int p=q; p<r; p++)
using namespace std;


int calculate_cost(vector<int> & shieldarr, vector<int>& numbers) {
	
	int start = 0;
	int result = 0;
	F(s_idx, 0, shieldarr.size()) {
		if (shieldarr[s_idx] == 1) {
			result += numbers[s_idx] - numbers[start];
			start = s_idx + 1;
		}
	}

	return result;
}

int solution(int N, int K, vector<int> numbers) {
	int answer = 99999999;

	vector<int> shieldarr;

	F(idx, 0, (K - 1)) {
		shieldarr.push_back(1);
	}

	F(fidx, 0, ((N - 1) - (K - 1))) {
		shieldarr.push_back(0);
	}

	sort(shieldarr.begin(), shieldarr.end());
	do {
		int result = calculate_cost(shieldarr, numbers);
		
		if (answer > result) {
			answer = result;
		}


	} while (next_permutation(shieldarr.begin(), shieldarr.end()));

	return answer;
}



int main() {

	Input(N, K, numbers);
	int N;
	int K;
	cin >> N;
	cin >> K;
	vector<int > numbers(N, 0);

	F(idx, 0, N) {
		cin >> numbers[idx];
	}
	//cout << solution(N, K, numbers);
	vector<int> sh = { 0,0,0,1 , 1 };
	vector<int> numbers2 = { 4,8,15,16,23,42 };
	cout <<calculate_cost(sh, numbers2);

	return 0;
}

// 입력은 2개야.
// 하나는 N,순열의 개수, 하나는 K의 값인 데, K는 군집의 개수야.
// N개의 수가 입력이 되. 그런데 이 수는 오름 차순이야.
// K 개의 군집의 cost의 합의 최솟값을 출력.
//


//  6	3 
//4, 8, 15, 16, 23, 42 
// 12

// 6 1
//4, 8, 15, 16, 23, 42 
// 38


// 6 6
//4, 8, 15, 16, 23, 42 
//0

//N<= 3000, K<=N

// N = 3000, K = 1500.  2999C1499
// cost 는 