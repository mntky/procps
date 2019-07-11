#include <stdio.h>
#include <locale.h>

int main() {
	char *s;
	s = setlocale(LC_NUMERIC, NULL);
	printf("%d", *s);
}
