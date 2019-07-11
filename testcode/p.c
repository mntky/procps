#include <stdio.h>

int main() {
	int a, b;
	int *e;
	a = 3;
	b = 4;

	e = &a;

	printf("%10p %10p\n", &a, &b);
	printf("%10d %10d\n", a, b);

	//printf("%10p %10p\n", d, e);
	printf("%10p\n", e);
}
