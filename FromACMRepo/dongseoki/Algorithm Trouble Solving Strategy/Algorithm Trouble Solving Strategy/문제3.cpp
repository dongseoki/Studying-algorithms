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
    // �ʱ�ȭ.
    int start = 0;

    if (tempGemsMap.size() == gemsMap.size())
        return { start, start + mean - 1 };

    while (true) {



        start++;
        if ((start + mean - 1) >= gems.size()) {
            // start + mean -1 �� �������� �ִ� ������ ��ġ.
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


    // ���� ���� ���� ���ٴ� ��.
    return { -1,-1 };
}

vector <int> binarySearch(int min, int max, vector<string>& gems, map<string, int>& gemsMap) {
    int mean = (min + max) / 2;
    map<string, int> tempGemsMap;

    vector<int> fixed_size_vec = find_fixed_size_gems(mean, gems,gemsMap);


    if (min == max) {
        // ���� ó��.
        return fixed_size_vec;
    }

    if (fixed_size_vec[0] == -1) {
        // ����. �׷��� �� ū�ſ��� �ִ�.
        return binarySearch(mean + 1, max, gems, gemsMap);
    }
    else {
        // �ִ�. �׷��� mean�� �����ϴ� ���� ����..!!
        return binarySearch(min, mean, gems, gemsMap);
    }

}

vector<int> solution(vector<string> gems) {
    vector<int> answer;


    map<string, int> gemsMap;

    // �켱 ���� �����.
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