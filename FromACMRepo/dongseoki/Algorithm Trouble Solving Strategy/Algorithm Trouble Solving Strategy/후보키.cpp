#include <iostream>
#include <vector>

#include <string>
#define F(p,q,r) for(int p = q; p<r; p++)

using namespace std;


using namespace std;

int column_length;
int row_length;
int cnt = 0;
int answer = 0;


bool is_it_in_c_vec(int selected_state, vector<int> & c_vec) {
    //bool flag = false;

    for (int  item : c_vec) {
        if ((item & selected_state) == item) {
            return true;
        }
    }
    return false;
}
bool same_posible(int t1, int t2 , int selected_state, vector<vector<string>>& relation) {
    F(idx, 0, column_length) {
        if (selected_state & (1 << idx)) {
            if (relation[t1][idx] == relation[t2][idx]) {
                continue;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

bool can_this_be_candidate_key(int selected_state, vector<vector<string>>& relation) {
    F(x, 0, row_length) {
        F(y, (x+1), row_length) {
            if (same_posible(x, y, selected_state, relation) == true) {
                //if (all_value_same(x, y, relation) == true)
                //    return false;
                return false;
            }
        }
    }

    return true;
}
void find_candidate_key(int length, int picked_num, int pre_value, 
    int selected_state, vector<int> & c_vec, vector<vector<string>> & relation, vector<bool>& visited) {
    if (picked_num >= length) {
        //degenerate case;
        cnt++;

        if (is_it_in_c_vec(selected_state, c_vec) == false) {
            if (can_this_be_candidate_key(selected_state, relation) == true) {
                c_vec.push_back(selected_state);
                answer++;
            }
        }

        return;
    }
    F(r_idx, 0, column_length) {
        if (visited[r_idx] == false && r_idx > pre_value) {
            visited[r_idx] = true;
            selected_state = selected_state | (1 << r_idx);
            find_candidate_key(length, picked_num +1 , r_idx,selected_state, c_vec, relation, visited);
            selected_state = selected_state & (~(1 << r_idx));
            visited[r_idx] = false;
        }
    }

}

int solution(vector<vector<string>> relation) {
    
    vector<int> c_vec;  // candidate vectors.

    //0. 찾기전 해당 요소가 후보키를 포함하는 지 파악한다.
    //1. 1개짜리를 찾는다.
    // .... N개 짜리의 후보키를 찾는다.

    
    column_length = relation[0].size();
    row_length = relation.size();
    //cout <<"result = "<<can_this_be_candidate_key(8, relation)<<"\n";
    F(length, 1, (column_length + 1)) {
        cnt = 0;
        vector<bool> visited(column_length, false);
        find_candidate_key(length,0, -1, 0,c_vec, relation, visited);
        //cout << "cnt = " << cnt << "\n";
    }

    for (auto item : c_vec) {
        cout << item << " ";
    }
    cout << "\n";


    return answer;
}

int main(void) {
    vector<vector<string>> relation ={ {"100", "ryan", "music", "2"}, { "200","apeach","math","2" }, { "300","tube","computer","3" }, { "400","con","computer","4" }, { "500","muzi","music","3" }, { "600","apeach","music","2" }};

    cout << solution(relation);
}