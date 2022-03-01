#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(const int bridge_length, int weight, vector<int> truck_weights) {

    int n_time =0;// ���� �ð�
    int n_weight=0; // ���� �ٸ��� ����
    // bridge_length // �ٸ��� ����
    const int max_weight = weight; // �ٸ��� �ִ� ����

    int t_idx = 0; // truck idx. ���� Ʈ���� ����Ŵ.
    int b_e_idx = 0; //bridge end idx. �ٸ��� ���� �ִ� Ʈ���� ����Ŵ. 

    vector<int> t_o_t(truck_weights.size(), -1); // truck out time . Ʈ���� ������ �ð�.�� ��� ����.
    // �츮�� �� ������ Ʈ���� �����̵����� ��ĭ �մ��ٰ� ��������.

    n_time++;
    // �ʱ⿡ 1�ʰ� �귶�� �� Ʈ���� �����̵��ؼ� �� �� �ֳ�?

    //1. �ٸ��� ���� ���� ����  �߰��Ѵٸ� ��ƿ�� �ֳ�?
    while (true) {
        if (t_idx >= truck_weights.size()) {
            break;
            // ���̻� �� Ʈ���� ���� ���̴�.
        }
        if (max_weight >= (n_weight + truck_weights[t_idx])) {
            // ��ƿ �� �ִٸ�,
            // �߰� �Ѵ�.
            t_o_t[t_idx] = n_time + bridge_length;
            // �ٸ��� �߰��ϱ�.

            n_weight += truck_weights[t_idx];
            //���� �ٸ� ���� ����.

            t_idx++;
            // ���� Ʈ���� ����Ű��.
      
            n_time++;
            // ���� �ð��� ����Ű���� �ð��� ����.
            if (n_time >= t_o_t[b_e_idx]) {
                n_weight -= truck_weights[b_e_idx];
                b_e_idx++;
                // Ȥ�ö� Ʈ���� ������ �ð��̶��..
            }
        }
        else {
            // ��ƿ�� ���ٸ�.
            // ��� Ʈ���� ������ ���� ����.
            //����.
            n_time = t_o_t[b_e_idx];
            // �̽ð��� ���ϳ��� �ִ� �༮�� ����.

            n_weight -= truck_weights[b_e_idx];
            // ���� �ٸ� ���� ����

            b_e_idx++;
            // ���� ����.
        }

    }

    // ������ Ʈ���� �ٸ� ���� �ð��� �������� answer�� �ۼ�.
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