#include <iostream>
#include <deque>

//http://www.hanbit.co.kr/channel/category/category_view.html?cms_code=CMS3942847236
//https://hyeonstorage.tistory.com/325


using namespace std;

int main(void) {
	deque<int> d;
	d.push_back(1);
	d.push_front(2);

	int c = d.back();
	cout << c << "\n";
}