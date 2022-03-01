#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXDATA 1000

typedef struct student {
	char name[30];
	char phone1[20];
	char phone2[20];
	char memo[40];
}std;

std s[200];

char* strArr[MAXDATA];

int file_line(FILE* fp) { //rewind!!
	char str[200];
	int i = 0;
	while (fgets(str, 256, fp) != NULL)
		i++;
	return i;
}

void printData(char* str) {
	while (*str != '\0') {
		if (*str != ':')
			printf("%c", *str++);
		else {
			printf(" ");
			str++;
		}
	}
	printf("\n");
}


void struccpy(char* s, std s1[], int i) {
	char* t1, * t2, * t3, * t4;

	t1 = s1[i].name;
	while (*s != ':') {
		*t1 = *s; s++; t1++;
		//copy each character
	}
	*t1 = '\0'; s++;
	//if ':' found then go to next step

	t2 = s1[i].phone1;
	while (*s != ':') {
		*t2 = *s; s++; t2++;
	}
	*t2 = '\0'; s++;

	t3 = s1[i].phone2;
	while (*s != ':') {
		*t3 = *s; s++; t3++;
	}
	*t3 = '\0'; s++;

	t4 = s1[i].memo;
	while (*s != '\0') {
		*t4 = *s; s++; t4++;
	}
	*t4 = '\0'; s++;
}

void swap(int a, int i, char* arr[]) {
	char* temp = arr[a];
	arr[a] = arr[i];
	arr[i] = temp;
}

int search(int len, char* arr[], char* argv[], int flag, FILE* fp) {
	int i = 0, a = 0, tf = 0, idx = 1, idxNum = 0, ds = 0;
	int strIdx[10000];
	char* str;
	//motivated from strcmp
	for (i = 0; i < len; i++) { //search all String Array
		str = arr[i];
		while (*str != '\0') { //
			a = 0; ds = 0;
			while (*str++ == argv[flag + 1][a]) {//found first match
				a++;
				if (argv[1][a] == '\0') {//if argv[1][a] ends
					//found
					strIdx[idx++] = i;
					//copy index of matched string's idx
					if (flag == 0)
						printf("%s\n", arr[i]);
					tf = 1; //bool
					ds = 1;
					break;
				}
			}
			if (ds)
				break;
		}
	}

	if (flag == 1) {
		for (i = 1; i < idx; i++)
			printf("%d %s\n", i, arr[strIdx[i]]);
		printf("Which One?\n");
		scanf("%d", &idxNum);
		if (idxNum < idx) { // proper idx
			printf("proper number\n");
			for (i = strIdx[idxNum]; i < len; i++) {
				arr[i] = arr[i + 1];
			}
			arr[--i] = NULL;
		}
		else {
			return 0;
		}
		for (i = 0; i < len - 1; i++)
			printData(arr[i]);
		fclose(fp);
		fp = fopen("data.txt", "w");
		//rewind(fp);
		for (i = 0; i < len - 1; i++) {
			fputs(arr[i], fp);
			fputc('\n', fp);
		}
	}

	return tf; //1 found , //0(none changed) not found
}

void add(FILE* fp, char* arr[], char* argv[]) {
	if (strlen(argv[2]) > 30) {
		printf("name's lenght is too long\n");
		return;
	}
	if (strlen(argv[3]) > 20) {
		printf("phone1 is too long\n");
		return;
	}
	if (strlen(argv[4]) > 20) {
		printf("phone2 is too long\n");
		return;
	}
	if (strlen(argv[5]) > 40) {
		printf("memo is too long\n");
		return;
	}

	char str[120];
	int i, a = 0, x = 0;
	for (i = 2; i < 6; i++) {
		a = 0;
		printf("%s ", argv[i]);
		while (argv[i][a] != '\0') {
			//copy to str[]
			str[x++] = argv[i][a++];
		}
		//+ ':' to seperate name , phone1 , phone2 , memo
		str[x++] = ':';
	}
	//end of string
	str[--x] = '\0';

	printf("\nadd? [Y/N]: ");
	char boo;
	scanf("%c", &boo);
	if ((boo - 'Y') == 0 || (boo - 'y') == 0) {
		fputc('\n', fp);//put '\n'
		fputs(str, fp);
	}
	else
		return;
}

void sort(char* arr[], int len) {
	//':' lower than alphabet character in ASCII code
	//So, it doesn't matter to compare ':' and alphabet

	int i = 0, a, idx;
	for (i = 0; i < len; i++) {
		for (a = i; a < len; a++) {
			//compare string's each index
			for (idx = 0; arr[i][idx] != '\0' || arr[a][idx] != '\0'; idx++) {
				if (arr[i][idx] > arr[a][idx]) {
					swap(i, a, arr);
					break;
				}
				else if (arr[i][idx] == arr[a][idx])
					continue;
				else
					break;
			}
		}
	}
}


int main(int argc, char* argv[]) {
	FILE* fp = fopen("data.txt", "r+t");
	int i, a;
	char arr[40];
	int len = file_line(fp);
	rewind(fp);

	for (i = 0; i < len; i++) {
		a = 0;
		fscanf(fp, "%s", arr);
		//printf("%s\n",arr);
		strArr[i] = malloc(110 * sizeof(char));
		strcpy(strArr[i], arr);
		struccpy(arr, s, i);
	}

	if (argc == 1)
	{
		printf("non option\n");
		printf("You need to type something\n");
		printf("\n");
		printf("-a name phone1 phone2 memo add to data.txt\n");
		printf("-l sort and print list from data.txt\n");
		printf("-d");
	}

	else if (argc > 1 && strcmp(argv[1], "-a") == 0) {
		//option -a 
		add(fp, strArr, argv);

	}

	else if (argc > 1 && strcmp(argv[1], "-d") == 0) {
		//option -d
		printf("-d detected\n");
		search(len, strArr, argv, 1, fp);

	}
	else if (argc > 1 && strcmp(argv[1], "-l") == 0) {
		//option -l
		sort(strArr, len);
		for (i = 0; i < len; i++) {
			printData(strArr[i]);
		}
	}
	else if (argc > 1) {
		if (search(len, strArr, argv, 0, fp))
			printf("match found\n");
		else
			printf("no match found\n");

	}

	fclose(fp);
	return 0;
}
