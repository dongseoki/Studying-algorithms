#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
int count = 0;
bool* PrimeArray;
void pick(int pickednum, int obj, string maked_n, string & numbers, vector<bool> & visited, set<int> & s) {
    if (pickednum >= obj) {
        s.insert(stoi(maked_n));
        //cout << maked_n<<"\n";
        // isprimenumber
        return;
    }
    else {
        for (int i = 0; i < numbers.size(); i++) {
            if (pickednum == 0 && numbers[i] == '0')
                continue;
            if (visited[i] == false) {
                visited[i] = true;
                // 방문 하고
                pick(pickednum+1, obj, maked_n + numbers[i], numbers, visited, s);
                visited[i] = false;
            }
        }
    }
}
void Eratos(int n)
{
    /*  만일 n이 1보다 작거나 같으면 함수 종료 */
    if (n <= 1) return;

    /*	2부터 n까지 n-1개를 저장할 수 있는 배열 할당
        배열 참조 번호와 소수와 일치하도록 배열의 크기는
        n+1 길이만큼 할당(인덱스 번호 0과 1은 사용하지 않음)	*/
    PrimeArray = new bool[n + 1];

    /*  배열초기화: 처음엔 모두 소수로 보고 true값을 줌	*/
    for (int i = 2; i <= n; i++)
        PrimeArray[i] = true;

    /*	에라토스테네스의 체에 맞게 소수를 구함
        만일, PrimeArray[i]가 true이면 i 이후의 i 배수는 약수로 i를
        가지고 있는 것이 되므로 i 이후의 i 배수에 대해 false값을 준다.
        PrimeArray[i]가 false이면 i는 이미 소수가 아니므로 i의 배수 역시
        소수가 아니게 된다. 그러므로 검사할 필요도 없다.
또한 i*k (k < i) 까지는 이미 검사되었으므로 j시작 값은 i*2 에서 i*i로 개선할 수 있다.
    */
    for (int i = 2; i * i <= n; i++)
    {
        if (PrimeArray[i])
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
    }

    // 이후의 작업 ...

    return;
}
bool isPrime(int num) {
    if (PrimeArray[num] == true) {
        return true;
    }
    else
        return false;
}
int solution(string numbers) {
    Eratos(10000000);
    int answer = 0;
    vector<bool> visited(numbers.size(), false);
    set<int> s;
    for (int i = 1; i <= numbers.size(); i++) {
        pick(0, i, "", numbers, visited, s);
    }

    for (auto item : s) {
        if (isPrime(item) == true) {
            answer++;
        }
        //cout << item << "\n";
    }


    return answer;
}

int main(void) {
    cout << solution("17");
    //cout << solution("011");
}