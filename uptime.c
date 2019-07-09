#include <stdio.h>
#include <time.h>

static char buf[128];
static double av[3];

int main(){
	struct tm *realtime;
	time_t seconds;

	time(&seconds);
	realtime = localtime(&seconds);
	printf("%i\n",(((seconds/60)/60)/24)/365);
	sprintf(buf, "%02d,%02d,%02d", realtime->tm_hour, realtime->tm_min, realtime->tm_sec);
	printf(buf);
	//return 0;
}
