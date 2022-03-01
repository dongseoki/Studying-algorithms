#include <stdio.h>

int main(void) {
	int first = 0;
	int last = 9;

	int step = 1;
	int i = 0;

	printf("-------for 문에 의한 i 값의 증가.\n");
	for (i = first; i <= last; i += step) {
		printf("%d ", i);
		if (i % 2 == 0)
			continue;
		
	}
	{
		printf("\n-------while 문에 의한 i 값의 증가.\n");
		i = first;
		while (i <= last) {
			printf("%d ", i);
			if (i % 2 == 0)
				continue;
			i += step;
		}
	}

}