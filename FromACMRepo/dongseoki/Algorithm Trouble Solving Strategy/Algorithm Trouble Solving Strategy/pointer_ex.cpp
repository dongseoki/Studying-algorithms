#include <stdio.h>
void swap(char** p, char** q) { // ºóÄ­À» Ã¤¿ì½Ã¿À
	char* temp = *p;
	*p = *q;
	*q = temp;
	return;
}

void swap2(int* p, int* q) { // ºóÄ­À» Ã¤¿ì½Ã¿À
	int temp = *p;
	*p = *q;
	*q = temp;
	return;
}

int main(void) { 
	char* a = (char *)"he";
	char* b = (char*)"llo";
	int c = 10;
	int d = 20;

	printf("%s%s\n", a, b);
	swap(&a, &b);  //ºóÄ­À» Ã¤¿ì½Ã¿À
	printf("%s%s\n", a, b);


	printf("%d %d\n", c, d);
	swap2(&c, &d);
	printf("%d %d\n", c, d);
	return 0;
}