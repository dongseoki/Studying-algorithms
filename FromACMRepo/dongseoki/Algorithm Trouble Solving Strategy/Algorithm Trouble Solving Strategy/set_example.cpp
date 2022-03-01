#include <iostream>
#include <set>
#include <functional>
using namespace std;

int main() {

	set<int, greater<int>> s;

	pair<set<int>::iterator, bool> pr;
	pr = s.insert(50);    // insert ��� pair ��ȯ
	s.insert(40);
	s.insert(80);

	if (true == pr.second)
		cout << *pr.first << " ���� ����!" << endl;
	else
		cout << *pr.first << "�� �̹� �ֽ��ϴ�. ���� ����! " << endl;

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	pr = s.insert(50);        // �ߺ� �� insert
	if (true == pr.second)
		cout << *pr.first << " ���� ����!" << endl;
	else
		cout << *pr.first << "�� �̹� �ֽ��ϴ�. ���� ����!" << endl;

	for (iter = s.begin(); iter != s.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	s.insert(pr.first, 60);        // 50 ��ġ�� �� 50 �ٷ� ����

	for (iter = s.begin(); iter != s.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	set<int, greater<int>> s2;        // �������� ����
	s2.insert(50);
	s2.insert(30);
	s2.insert(80);
	s2.insert(40);
	s2.insert(10);
	s2.insert(70);
	s2.insert(90);

	for (iter = s2.begin(); iter != s2.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	// key_compare, value_compare Ȯ��
	cout << "key_compare less : " << typeid(s.key_comp()).name() << endl;
	cout << "key_compare greater : " << typeid(s2.key_comp()).name() << endl;

	cout << "value_compare less : " << typeid(s.value_comp()).name() << endl;
	cout << "value_compare greater : " << typeid(s2.value_comp()).name() << endl;

	return 0;
}

//��ó: https://hyeonstorage.tistory.com/327 [������ �ϰ� �;��]