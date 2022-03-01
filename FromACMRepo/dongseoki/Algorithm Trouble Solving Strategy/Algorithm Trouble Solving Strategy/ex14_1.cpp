#include <stdio.h>

int main(void) {
	int num = 20;
	const int * ptr = &num;
	//*ptr = 30;
	int num2 = 60;
	num = 40;
	ptr = &num2;
	printf("ptrvalue : %d\n", num2);
	return 0;
}