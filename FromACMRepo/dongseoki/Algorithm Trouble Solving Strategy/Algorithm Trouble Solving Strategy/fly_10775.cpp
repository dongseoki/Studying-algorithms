#include <stdio.h>
using namespace std;

int g, p, a, i, cnt, empty_gate;
int parent[100001];

int find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	parent[x] = y;
}

int main() {
	scanf("%d %d", &g, &p);
	for (i = 1; i <= g; ++i)
		parent[i] = i;
	for (i = 0; i < p; ++i) {
		scanf("%d", &a);
		empty_gate = find(a);
		if (empty_gate == 0)
			break;
		else {
			cnt++;
			unite(empty_gate, empty_gate - 1);
		}
	}
	printf("%d\n", cnt);
	return 0;
}


//https://js1jj2sk3.tistory.com/20
