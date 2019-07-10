#include <stdio.h>
static int c;
#define TEN 10
#define TEST(a, b) do{ \
	c = a + b;	\
}while(0)
	

int main(){
	int i;
	int j = TEN;
	scanf("%d", &i);
	printf("%d\n", i*112);
	printf("%d\n",j);
	printf("-------------------\n");
	TEST(10, 20);
	printf("%d",c);
}
