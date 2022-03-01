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
                // �湮 �ϰ�
                pick(pickednum+1, obj, maked_n + numbers[i], numbers, visited, s);
                visited[i] = false;
            }
        }
    }
}
void Eratos(int n)
{
    /*  ���� n�� 1���� �۰ų� ������ �Լ� ���� */
    if (n <= 1) return;

    /*	2���� n���� n-1���� ������ �� �ִ� �迭 �Ҵ�
        �迭 ���� ��ȣ�� �Ҽ��� ��ġ�ϵ��� �迭�� ũ���
        n+1 ���̸�ŭ �Ҵ�(�ε��� ��ȣ 0�� 1�� ������� ����)	*/
    PrimeArray = new bool[n + 1];

    /*  �迭�ʱ�ȭ: ó���� ��� �Ҽ��� ���� true���� ��	*/
    for (int i = 2; i <= n; i++)
        PrimeArray[i] = true;

    /*	�����佺�׳׽��� ü�� �°� �Ҽ��� ����
        ����, PrimeArray[i]�� true�̸� i ������ i ����� ����� i��
        ������ �ִ� ���� �ǹǷ� i ������ i ����� ���� false���� �ش�.
        PrimeArray[i]�� false�̸� i�� �̹� �Ҽ��� �ƴϹǷ� i�� ��� ����
        �Ҽ��� �ƴϰ� �ȴ�. �׷��Ƿ� �˻��� �ʿ䵵 ����.
���� i*k (k < i) ������ �̹� �˻�Ǿ����Ƿ� j���� ���� i*2 ���� i*i�� ������ �� �ִ�.
    */
    for (int i = 2; i * i <= n; i++)
    {
        if (PrimeArray[i])
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
    }

    // ������ �۾� ...

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