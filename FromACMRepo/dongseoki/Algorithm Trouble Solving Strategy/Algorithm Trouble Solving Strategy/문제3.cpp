#include <string>
#include <vector>
#include <iostream>
#include <map>
#define F(p,q,r) for(int p=q;p<r;p++)
using namespace std;


vector<int> find_fixed_size_gems(int mean, vector<string> & gems, map<string, int> & gemsMap) {
    map<string, int> tempGemsMap;
    F(idx, 0, mean) {
        tempGemsMap[gems[idx]]++;
    }
    // 초기화.
    int start = 0;

    if (tempGemsMap.size() == gemsMap.size())
        return { start, start + mean - 1 };

    while (true) {



        start++;
        if ((start + mean - 1) >= gems.size()) {
            // start + mean -1 은 마지막에 있는 원소의 위치.
            break;
        }
        tempGemsMap[gems[start-1]]--;
        if (tempGemsMap[gems[start - 1]] <= 0) {
            tempGemsMap.erase(tempGemsMap.find(gems[start - 1]));
        }
        tempGemsMap[gems[start + mean - 1]]++;

        if(tempGemsMap.size() == gemsMap.size())
            return { start, start + mean - 1 };
    }


    // 여기 까지 오면 없다는 것.
    return { -1,-1 };
}

vector <int> binarySearch(int min, int max, vector<string>& gems, map<string, int>& gemsMap) {
    int mean = (min + max) / 2;
    map<string, int> tempGemsMap;

    vector<int> fixed_size_vec = find_fixed_size_gems(mean, gems,gemsMap);


    if (min == max) {
        // 예외 처리.
        return fixed_size_vec;
    }

    if (fixed_size_vec[0] == -1) {
        // 없다. 그러면 더 큰거에서 있다.
        return binarySearch(mean + 1, max, gems, gemsMap);
    }
    else {
        // 있다. 그러면 mean을 포함하는 작은 범위..!!
        return binarySearch(min, mean, gems, gemsMap);
    }

}

vector<int> solution(vector<string> gems) {
    vector<int> answer;


    map<string, int> gemsMap;

    // 우선 개수 세어보자.
    for (auto item : gems) {
        gemsMap[item]++;
    }

    cout << gemsMap.size() << "\n";

    int min = gemsMap.size();
    int max = gems.size();
    answer = binarySearch(min, max, gems, gemsMap);
    answer[0]++;
    answer[1]++;
    return answer;
}

int main(void) {
    //vector<string> gems ={"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<string> gems = { "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
    vector<int> result =  solution(gems);

    cout << result[0] << " " << result[1] << "\n";
    
}