#include <stdio.h>
int main(void) {
	int a, b, d = 0;
	for (b = 0; b < 5; b++) {
		a = 0;
		for (; a<1;) {
			printf("0���� ū �� �Է� %d ��° : ", b + 1);
			scanf("%d", &a);
		}
		d += a;
	}
	printf("���� %d", d);
	return 0;
}