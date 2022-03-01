#include "pch.h"
#include <iostream>
#include <cstdio>
#include <limits.h>
//
//https://www.crocus.co.kr/584

using namespace std;

typedef pair<int, int> pii;

pii tree[10002]; // first = left, second = right
pii len[10002]; // first = level , second = len
int minarr[10002];
int maxarr[10002];

long long int sum, maxval, level;

int real[10002];
int target;

int pos = 1; // 노드의 위치

// 전위 순회 dfs
void dfs(int now, int level)
{
	// 왼쪽 자식이 있다면
	if (tree[now].first > 0)
		dfs(tree[now].first, level + 1);

	// 현재 레벨 및 위치 저장
	len[now].first = level;
	len[now].second = pos;

	// 현재 레벨에서 가장 왼쪽 노드 위치를 갱신
	if (minarr[len[now].first] > len[now].second)
		minarr[len[now].first] = len[now].second;

	// 현재 레벨에서 가장 오른쪽 노드 위치를 갱신
	if (maxarr[len[now].first] < len[now].second)
		maxarr[len[now].first] = len[now].second;

	pos++;

	// 오른쪽 자식이 있다면
	if (tree[now].second > 0)
		dfs(tree[now].second, level + 1);
}

int main()
{
	int n;
	int root, left, right;
	scanf("%d", &n);

	// min값을 찾기 위해 INT_MAX로 전체를 초기화
	fill(minarr, minarr + 10002, INT_MAX);

	// 트리 생성
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &root, &left, &right);
		tree[root].first = left;
		tree[root].second = right;

		real[root]++;

		if (left != -1)
			real[left]++;
		if (right != -1)
			real[right]++;
	}

	// 루트 노드 찾기
	for (int i = 1; i <= n; i++)
		if (real[i] == 1)
			target = i;

	dfs(target, 1);

	// 각 레벨의 최대 - 최소 + 1을 하여 
	// 트리의 최대 너비 및 레벨을 구하는 과정
	for (int i = 1; i <= n; i++)
	{
		sum = maxarr[i] - minarr[i] + 1;
		if (sum > maxval)
		{
			maxval = sum;
			level = i;
		}
	}

	printf("%lld %lld", level, maxval);
	return 0;
}

//
//
//출처: https://www.crocus.co.kr/584 [Crocus]