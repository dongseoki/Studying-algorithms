#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define F(p,q,r) for(int p = q; p<r; p++)
#define IMPOSSIBLE_MAX 100000001
using namespace std;

long long caculate_time_to_finish_foods_which_time_is_not_bigger_than_specific_time(const vector<int>& food_times, const int s_time) {
    long long result = 0;
    for (auto item : food_times) {
        if (item < s_time) {
            result += item;
        }
        else {
            result += s_time;
        }
    }
    return result;
}
bool except_case(const vector<int>& food_times, const long long k) {
    long long result = 0;
    for (auto item : food_times) {
 
            result += item;

    }

    if (result <= k)
        return true;
    else
        return false;
}

pair<int, long long> food_times_binary_search(const vector<int>& food_times, const vector<int>& sortedfood_times, const long long k) {
    int low = 0;
    int high = sortedfood_times.size() - 2;
    int mid = 0;
    long long result =0;
    long long above_result =0;
    while (true) {
        mid = (low + high) / 2;
        int s_time = sortedfood_times[mid];
        result = caculate_time_to_finish_foods_which_time_is_not_bigger_than_specific_time(food_times, s_time);
        s_time = sortedfood_times[mid + 1];
        above_result = caculate_time_to_finish_foods_which_time_is_not_bigger_than_specific_time(food_times, s_time);
        if (result <= k) {
            if (above_result > k) {
                break;
            }
            else {
                low = mid;
            }
        }
        else {
            high = mid;
        }
    }
    pair<int, long long> p = make_pair(mid, result);
    return p;
}

int solution(vector<int> food_times, long long k) {

    vector<int> sorted_food_times = food_times;
    sorted_food_times.push_back(IMPOSSIBLE_MAX);
    sorted_food_times.push_back(0);
    // 양 끝 값 추가.
    sort(sorted_food_times.begin(), sorted_food_times.end());


    //예외 케이스 처리.
    if (except_case(food_times, k) == true) {
        return -1;
    }

    pair<int, long long> data = food_times_binary_search(food_times, sorted_food_times, k);
    // 1. 이진 탐색하여 특정 시간대 이하 음식을 모두 먹는데 걸린 시간과, 그 특정 시간대에 해당하는 index를 구한다.

    
    //if (data.first == (sorted_food_times.size() - 2)) {
    //    return -1;
    //}

    vector<pair<int, int>> decreased_food_times;
    // 첫번째는 인덱스, 두번째는 남은 시간.
    int s_time = sorted_food_times[data.first];
        F(idx, 0, food_times.size()) {
            int item = food_times[idx];
            if (item > s_time)
                decreased_food_times.push_back(make_pair(idx+1, item));
        }
    
    long long decreased_k = k - data.second;

    int answer = decreased_food_times[decreased_k % decreased_food_times.size()].first;

    // 2. k -특정 시간대 이하 음식을 모두 먹는데 걸린 시간 하고,
    // 특정 시간대를 초과하는 food times 원소만 새로운 vector에 넣어서 마지막에 먹어야 하는 인덱스를 구한다.
    return answer;
}


int main(void) {
    vector<int> food_times = { 3, 1, 2 };
    long long k = 15;
    cout << solution(food_times, k);
}