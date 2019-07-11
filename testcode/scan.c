#include <stdio.h>

int main() {
	int resp;
	char test[] = "abc 123 456";
	char r1[4];
	int r2;
	int r3;

	resp = sscanf(test, "%3s%d%d",&r1, &r2, &r3);
	if(resp == EOF) {
		printf("error");
		return -1;
	}

	printf("%s\n", r1);
	printf("%d\n", r2);
	printf("%d\n", r3);
}
