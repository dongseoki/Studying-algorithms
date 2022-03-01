#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int s_b_s_u_length(string p) {
	int l = 0;
	int r = 0;
	int length = p.length();
	for (int i = 0; i < length; i++) {
		if (p[i] == '(')
			l++;
		if (p[i] == ')')
			r++;
		if (l != 0 && (l == r)) {
			return (i + 1);
		}
	}
}

bool rightString(string p)
{
	int count = 0;
	int length = p.length();
	for (int i = 0; i < length; i++)
	{
		if (p[0] == ')')
		{
			return false;
		}
		if (p[length - 1] == '(')
		{
			return false;
		}


		if (p[i] == '(')
		{
			count++;
		}
		else
		{
			count--;
			if (count < 0)
			{
				return false;
			}
		}
	}

	if (count == 0) {
		return true;
	}
	else
		return false;
}

string rightP(string p) {
	if (p.empty()) {
		return "";
	}
	int u_l = s_b_s_u_length(p);
		// separate balanced string u length;

	string u = p.substr(0, u_l);
	string v = "";
	if(u_l == p.length())
		v = "";
	v = p.substr(u_l);
	if (rightString(u) == true) {
		return  (u + rightP(v));
	}
	else {
		string ans = "(";
		ans = ans + rightP(v);
		ans = ans + ")";
		u = u.substr(1, u.length() - 2);
		reverse(u.begin(), u.end());
		ans = ans + u;
		return ans;
	}

}
string solution(string p) {
	string answer = "";
	if (rightString(p) == true)
		return p;
	answer = rightP(p);
	return answer;
}
int main(void) {
	cout << solution("(()())()")<<"\n";
	cout << solution(")(") << "\n";
	cout<< solution("()))((()") << "\n";
}