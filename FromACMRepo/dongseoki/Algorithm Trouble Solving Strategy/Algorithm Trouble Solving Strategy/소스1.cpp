#include <stdio.h>
int main(void) {
	int a, b, d = 0;
	for (b = 0; b < 5; b++) {
		a = 0;
		for (; a<1;) {
			printf("0보다 큰 수 입력 %d 번째 : ", b + 1);
			scanf("%d", &a);
		}
		d += a;
	}
	printf("총합 %d", d);
	return 0;
}