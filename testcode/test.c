#include <stdio.h>


int main() {
	int up=10;
	int* up2=NULL;
	printf("%x %d\n", &up, up);
	printf("%x %p\n", &up2, up2);
	
	up2 = &up;
	printf("%x %d\n", &up, up);
	printf("%x %p\n", &up2, up2);


}
