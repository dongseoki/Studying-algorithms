#pragma warning (disable: 4996)

//https://yunsu3042.github.io/devlog/2018/02/15/%EB%B0%B1%EC%A4%80-2957%EB%B2%88-C++/

#include "pch.h"
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//https://injunech.tistory.com/74
//scanf 문제 해결.


void insert(map<int, long long int>& v, vector<long long int>& sum, int x)
{
	map<int, long long int>::iterator lower_bound;
	map<int, long long int>::iterator upper_bound;

/*
	lower(x)는 x이상인 최초의 지점을 찾아주는 겁니다.upper는 x보다 큰, 최초의 위치를 찾아주는 것이고요. 3을 로어, 어퍼로 찾았을 때, 가리키는 위치를 그림에서 나타내 보았는데요.이 정도면 대략적인 차이는 이해가 되실 듯 싶습니다.
		[출처] 탐색의 기초 lower_bound와 upper_bound | 작성자 조가희
*/

	//lower_bound = --v.lower_bound(x);
	lower_bound = --v.upper_bound(x);
	upper_bound = v.upper_bound(x);
	long long int count = 0;
	count = max(lower_bound->second, upper_bound->second) + 1;
	v.insert(pair<int, long long int>{x, count});
	if (sum.size() > 1)
	{
		sum.push_back(sum[sum.size() - 1] + count);
	}
	else
	{
		sum.push_back(count);
	}
	return;
}


int main()
{
	map<int, long long int> tree;
	tree.insert(pair<int, long long int>{0, -1});
	tree.insert(pair<int, long long int>{300001, -1});
	int n;
	int m;
	vector<long long int>sum;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		insert(tree, sum, m);
	}

	for (long long int x : sum)
	{
		printf("%lld\n", x);
	}


}