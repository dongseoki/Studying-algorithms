#include <tuple>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	tuple<int, string, bool> tp = make_tuple(4, "hi", true);
	cout << get<0>(tp) << "\n";
	get<0>(tp) = 6;
	cout << get<0>(tp) << "\n";

	int num;
	string st;
	bool bl;
	tie(num, st, bl) = tp;

	cout << num <<" "<< st <<" "<< bl<<"\n";
	int asdf = 2;
	// cout << get<asdf>(tp);
	//asdf 이런것은 저기 꺽쇄 사이에 못들어감.
}