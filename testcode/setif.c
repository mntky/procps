#include <stdio.h>

#define SET_IF_DESIRED(x,y) do{ if(x) *(x) = (y); }while(0)


int main() {
	int up=10;
	int _uptime=100;
	int *uptime_secs= NULL;

	printf("uptimesec	: %10x %10d\n", &uptime_secs, *(&uptime_secs));
	printf("up       	: %10x %10d\n", &up, up);
	printf("---------------------------------------\n");

	uptime_secs = &_uptime;

	printf("uptimesec	: %10x %10d\n", &uptime_secs, *uptime_secs);
	printf("up       	: %10x %10d\n", &up, up);
	printf("---------------------------------------\n");

	SET_IF_DESIRED(uptime_secs, up);

	printf("uptimesec	: %10x %10d\n", &uptime_secs, *uptime_secs);
	printf("up       	: %10x %10d\n", &up, up);

}
