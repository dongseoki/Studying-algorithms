#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(const int bridge_length, int weight, vector<int> truck_weights) {

    int n_time =0;// 현재 시간
    int n_weight=0; // 현재 다리의 무게
    // bridge_length // 다리의 길이
    const int max_weight = weight; // 다리의 최대 무게

    int t_idx = 0; // truck idx. 넣을 트럭을 가리킴.
    int b_e_idx = 0; //bridge end idx. 다리의 끝에 있는 트럭을 가리킴. 

    vector<int> t_o_t(truck_weights.size(), -1); // truck out time . 트럭이 나가는 시간.이 담긴 벡터.
    // 우리는 그 순간에 트럭을 순간이동으로 한칸 앞당긴다고 생각하자.

    n_time++;
    // 초기에 1초가 흘렀을 때 트럭이 순간이동해서 들어갈 수 있나?

    //1. 다리의 현재 하중 에서  추가한다면 버틸수 있나?
    while (true) {
        if (t_idx >= truck_weights.size()) {
            break;
            // 더이상 볼 트럭이 없는 것이다.
        }
        if (max_weight >= (n_weight + truck_weights[t_idx])) {
            // 버틸 수 있다면,
            // 추가 한다.
            t_o_t[t_idx] = n_time + bridge_length;
            // 다리에 추가하기.

            n_weight += truck_weights[t_idx];
            //현재 다리 무게 증가.

            t_idx++;
            // 다음 트럭을 가리키기.
      
            n_time++;
            // 다음 시간을 가리키도록 시간을 증가.
            if (n_time >= t_o_t[b_e_idx]) {
                n_weight -= truck_weights[b_e_idx];
                b_e_idx++;
                // 혹시라도 트럭이 나갔을 시간이라면..
            }
        }
        else {
            // 버틸수 없다면.
            // 모든 트럭이 못들어가는 경우는 없다.
            //따라서.
            n_time = t_o_t[b_e_idx];
            // 이시간에 제일끝에 있는 녀석이 나감.

            n_weight -= truck_weights[b_e_idx];
            // 현재 다리 무게 감소

            b_e_idx++;
            // 끝을 갱신.
        }

    }

    // 마지막 트럭의 다리 나온 시간을 기준으로 answer를 작성.
    int answer = t_o_t.back();
    return answer;
}

int main(void) {
    //2	10	{7, 4, 5, 6}	8
    //    100	100	{10}	101
    //    100	100	{10, 10, 10, 10, 10, 10, 10, 10, 10, 10}	110

    cout << solution(2, 10, { 7, 4, 5, 6 })<<"\n";
    cout << solution(100,	100, { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }) << "\n";
    cout << solution(100, 100, { 10 }) << "\n";
    cout << solution(5, 5, { 1, 1, 1, 1, 1, 2, 2, 2, 2 }) << "\n";
}