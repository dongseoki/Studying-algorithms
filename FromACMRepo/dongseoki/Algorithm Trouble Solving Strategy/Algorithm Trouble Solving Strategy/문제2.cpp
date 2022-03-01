#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define F(p,q,r) for(int p =q ; p<r;p++)
using namespace std;


void parsing(string expression, vector<long long>& numbers, vector<string>& operators) {
    int start = -1;
    int last = 0;
    F(end, 0, expression.size()) {
        if (expression[end] == '+' || expression[end] == '-' || expression[end] == '*') {
            //string operatorStr(expression[end]);
            //operators.push_back(""+ expression[end]);
            operators.push_back(expression.substr(end, 1));
            string numstring = expression.substr(start+1, end - start);
            long long num = stoi(numstring);
            numbers.push_back(num);
            start = end;
        }
        
    }
    string numstring = expression.substr(start+1);
    long long num = stoi(numstring);
    numbers.push_back(num);
}

int findOperatorPos(vector<string>& operators, string operatorString) {
    F(idx, 0, operators.size()) {
        if (operators[idx] == operatorString)
            return idx;
    }
    return -1;
}

long long caculation(vector<long long> numbers, vector<string> operators, vector<string>& operatorPriority) {
    // 값복사를 하자. 다른 데 더 써야 하니;까.
    F(opIdx, 0, operatorPriority.size()) {
        while (true) {
            int pos = findOperatorPos(operators, operatorPriority[opIdx]);
            
            if (pos == -1) {
                break;
            }

            long long newNum = 0;
            switch (operatorPriority[opIdx][0])
            {
            case '*':
                newNum = numbers[pos] * numbers[pos + 1];
                break;
            case '-':
                newNum = numbers[pos] - numbers[pos + 1];
                break;
            case '+':
                newNum = numbers[pos] + numbers[pos + 1];
                break;
            default:
                break;
            }
            numbers[pos] = newNum;
            // 값 바꾸고.
            
            numbers.erase(numbers.begin() + pos+1);
            operators.erase(operators.begin() + pos);
            // 제거.

        }
    }

    // 값이 한개 있을 듯.

    return abs(numbers[0]);
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> numbers = {};
    vector<string> operators = {};
    parsing(expression ,numbers, operators);
    // 파싱 결과가 있다 치자.

    vector<long long> operatorBool = { 0,0,0 };
    int count = 0;
    int idx = expression.find("-");
    if (idx != -1)
        operatorBool[0] = 1;
    idx = expression.find("*");
    if (idx != -1)
        operatorBool[1] = 1;
    idx = expression.find("+");
    if (idx != -1)
        operatorBool[2] = 1;

    vector<long long> results = {};

    vector<string> indexOperator = { "-", "*", "+" };
    vector<string> operatorPriority = {};
    F(idx, 0, operatorBool.size()) {
        if (operatorBool[idx] == 1) {
            operatorPriority.push_back(indexOperator[idx]);
        }
    }
    sort(operatorPriority.begin(), operatorPriority.end());
    do {
        /*for (auto item : operatorPriority) {
            cout << item<<" ";
        }
        cout << "\n";*/

        results.push_back(caculation(numbers, operators, operatorPriority));
        // 여기 모든 경우의 수 나옴.

    } while (next_permutation(operatorPriority.begin(), operatorPriority.end()));
    

    answer = *max_element(results.begin(), results.end());
    


    return answer;
}

int main(void) {
    //string expression = "100-200*300-500+20";
    string expression = "50*6-3*2";
    //int idx1 = expression.find("-");
    //int idx2 = expression.find("&");
    //cout << idx1 << "\n";
    //cout << idx2 << "\n";
    cout << solution(expression);
}