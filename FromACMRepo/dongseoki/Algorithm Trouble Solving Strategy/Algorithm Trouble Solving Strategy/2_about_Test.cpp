#include <string>
#include <iostream>
using namespace std;
bool solution(string s)
{
	bool answer = true;
	int tmp = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[0] == ')' && s[s.length()] == '(')
		{
			return false;
		}
		if (s[i] == '(')
		{
			tmp++;
		}
		else
		{
			tmp--;
			if (tmp < 0)
			{
				return false;
			}
		}
	}

	if (tmp == 0) {
		return true;
	}




	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	//cout << "Hello Cpp" << endl;

	return false;
}

int main(void) {
	string a = "asdfzxcv";
	cout << a[a.length()] << "\n";
	cout << a[a.length()-1] << "\n";
	cout << solution("()()");
}