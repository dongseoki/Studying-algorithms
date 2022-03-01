#include <stdio.h>
#include <vector>
using namespace std;

void merge(int N, int M, vector<int>& v1, vector<int>& v2, vector<int>& v3) {
	int lptr = 0;
	int rptr = 0;
	int bptr = 0;
	int le = N - 1;
	int re = M - 1;

	while (lptr <= le && rptr <= re) {
		if (v1[lptr] < v2[rptr])
			v3[bptr++] = v1[lptr++];
		else
			v3[bptr++] = v2[rptr++];
	}

	if (lptr > le)
		for (int i = rptr; i <= re; i++)
			v3[bptr++] = v2[i];
	if (rptr > re)
		for (int i = lptr; i <= le; i++)
			v3[bptr++] = v1[i];
}
int mcnt = 0;
void merge2(int sx, int ex, int sy, int ey, vector<int>& xarr, vector<int>& yarr, vector<int>& marr) {
	if (sx > ex) {
		for (int i = sy; i <= ey; i++) {
			marr[mcnt++] = yarr[i];
		}
		return;
	}

	if (sy > ey) {
		for (int i = sx; i <= ex; i++) {
			marr[mcnt++] = xarr[i];
		}
		return;
	}

	if (xarr[sx] < yarr[sy]) {
		marr[mcnt++] = xarr[sx];
		merge2(sx + 1, ex, sy, ey, xarr, yarr, marr);
	}
	else {
		marr[mcnt++] = yarr[sy];
		merge2(sx, ex, sy + 1, ey, xarr, yarr, marr);
	}
}

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	vector<int> v1(N, 0);
	vector<int> v2(M, 0);
	vector<int> v3(N + M, 0);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v1[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &v2[i]);
	}
	//merge(N,M, v1,v2, v3);
	merge2(0, N - 1, 0, M - 1, v1, v2, v3);

	for (int i = 0; i < (M + N); i++) {
		printf("%d ", v3[i]);
	}
}

//void merge(int ls, int le, int rs, int re, int A[])
//{
//	int lptr = ls, rptr = rs, bptr = 0;
//	int* B = (int*)calloc((le – ls) + (re – rs) + 2, sizeof(int));
//	while (lptr <= le && rptr <= re) {
//		if (A[lptr] < A[rptr])
//			B[bptr++] = A[lptr++];
//		else
//			B[bptr++] = A[rptr++];
//	}
//	if (lptr > le)
//		for (int i = rptr; i <= re; i++)
//			B[bptr++] = A[i];
//	if (rptr > re)
//		for (int i = lptr; i <= le; i++)
//			B[bptr++] = A[i];
//	A  B;
//}