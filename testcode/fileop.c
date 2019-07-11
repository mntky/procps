#include <stdio.h>

void op(char *filename);


int main() {
	char f[10] = "text.txt";
	char *p = f;

	op(p);
}

void op(char *filename) {
	printf("%s", filename);
	//printf("%s %d", filename, fd);
}
