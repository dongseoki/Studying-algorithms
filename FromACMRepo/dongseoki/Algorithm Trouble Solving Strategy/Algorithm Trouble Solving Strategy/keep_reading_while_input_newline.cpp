#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
int main()
{
	scanf("%d %d", &n, &m);
	int
		for (int i = 1; i <= n; i++) {
			int x;
			//scanf("%d", &v);

			while (v--) {
				scanf("%d", &x);
				node[i].push_back(x);
			}
		}
	printf("%d", bmatch());
	return 0;
}


//출처: https://jason9319.tistory.com/149 [ACM-ICPC 상 탈 사람]