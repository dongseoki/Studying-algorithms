#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#define F(p,q,r) for(int p=q; p<r; p++)
using namespace std;

class Try {
public:
    bool leaf_flag ;
    vector<Try*> nextTriePtrs;

    Try() {
        this->leaf_flag = false;
        this->nextTriePtrs.assign(26, NULL);
    }
    void insertTry(string & word, int start) {
        if (start < word.size()) {
            int idx = word[start] - 'a';
            if(this->nextTriePtrs[idx] == NULL)
                this->nextTriePtrs[idx] = new Try();
            this->nextTriePtrs[idx]->insertTry(word, start + 1);
        }
        else {
            this->leaf_flag = true;
        }
    }

    int findHowMany(string& query, int start) {
        int sum = 0;
        if (start == query.size() ) {
            if (this->leaf_flag == true)
                return 1;
            else
                return 0;
        }
        else {

            if (query[start] == '?') {
                F(idx, 0, 26) {
                    if (this->nextTriePtrs[idx] != NULL) {
                        sum += this->nextTriePtrs[idx]->findHowMany(query, start + 1);
                    }
                }
            }
            else {
                // ?가 아닌 케이스
                int idx = query[start] -'a';
                if (this->nextTriePtrs[idx] != NULL) {
                    sum += this->nextTriePtrs[idx]->findHowMany(query, start + 1);
                }
            }
            return sum;
        }

    }
    
};

vector<int> solution(vector<string> words, vector<string> queries) {
    Try root = Try();
    for (string& item : words) {
        root.insertTry(item, 0);
    }
    vector<string> reversed_words = words;
    Try reverseroot = Try();
    F(i, 0, reversed_words.size()) {
        reverse(reversed_words[i].begin(), reversed_words[i].end());
        reverseroot.insertTry(reversed_words[i],0);
    }

    cout << root.findHowMany(queries[0], 0);

    vector<int> answer;
    map<string, int> memo;
    F(i, 0, queries.size()) {
        int result = 0;
        string original = queries[i];
        if (memo.find(original) != memo.end()) {
            answer.push_back(memo[original]);
            continue;
        }

        if (queries[i][0] == '?') {
            // reverse case;
            reverse(queries[i].begin(), queries[i].end());
            result = reverseroot.findHowMany(queries[i], 0);
        }
        else {
            result = root.findHowMany(queries[i], 0);
        }
        memo[original] += result;
        answer.push_back(result);
    }

    return answer;
}

vector<int> solution_binarysearch(vector<string> words, vector<string> queries) {


    sort(queries.begin(), queries.end());
    sort(words.begin(), words.end());
    cout << *lower_bound(words.begin(), words.end(), "fro??");
    vector<int> answer;
    return answer;
}
int main(void) {
    //vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    //vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
    // original
    vector<string> tests = { "yz", "y{", "za" };
    sort(tests.begin(), tests.end());

    vector<string> words = { "frodo","frot", "fro", "froa","front", "frost", "frozen", "frame", "kakao" };
    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
    //vector<int> answer = solution(words, queries);
    //vector<int> answer = solution_binarysearch(words, queries);
    // 새로운 sorting 방식을 적용해야하는 문제가 생겼다. 자릿수가 꽤 중요한 요소이기 때문이다.
    // ex) fab fa fc     fa?
    // fa fab fc
    // 길이 별로 했다면 금방 찾을 수도 있겠지.
    // ex) fa fc fab.
    // 
    cout << "end";
}