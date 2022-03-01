#include <string>
#include <vector>
#include <iostream>

using namespace std;
int c = 0;
void targetgo(int now, const int& obj, int m_sum, const int& target, const vector<int>& numbers) {
    if (now == obj) {
        if (m_sum == target)
            c++;
        return;
    }
    targetgo(now + 1, obj, m_sum - numbers[now], target, numbers);
    targetgo(now + 1, obj, m_sum + numbers[now], target, numbers);
 }

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int obj = numbers.size();
    targetgo(0, obj, 0, target, numbers);
    answer = c;
    return answer;
}

int main(void) {
    cout << solution({ 1,1,1,1,1 }, 3);
}