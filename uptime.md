#procps uptime

[uptime.c]

```
~
int main(int argc. char *argv[]) {
	if(argc == 1) {
		print_uptime(); 
		return 0;
~
```

[proc/whattime.c :85]

```c
void print_uptime(void) {
	printf("%s\n", sprint_uptime());
}
```

[proc/whattime.c :30]

```c
char *sprint_uptime(void) {
/*variable difination */
	struct utmp *utmpstruct;
	int upminutes, uphours, updays;
	int pos;
	struct tm *realtime;
	time_t realseconds;
	int numuser;
	double uptime_secs, idle_secs;

/* get current time */
	time(&realseconds); //time() return seconds since 1970/1/1 00:00:00
	realtime = localtime(&realseconds); //tm struct (tm_sec,tm_min,tm_hour...)
	pos = sprintf(buf, "%02d,%02d,%02d",
		realtime->tm_hour, realtime->tm_min, realtime->tm_sec);

/* read and calculate the amount of uptime */
	uptime(&uptime_secs, &idle_secs); //:33 0.0, 0.0
~
```

[proc/sysinfo.c :75]

```
int uptime(double *restrict uptime_secs, double *restrict idle_secs) {
	double up=0, idle=0;
	char *restrict savelocale;

	FILE_TO_BUF(UPTIME_FILE,uptime_fd); // /proc/uptime, -1
~
```

[proc/sysinfo.c :54]

```
#define FILE_TO_BUF(filename, fd) do{
	static int local_n;
	if (fd == -1 && (fd = open(filename, 0_RDONLY)) == -1) {
	fputs(BAD_OPEN_MESSAGE, stderr); //write to stderr
	fflush(NULL); //all stream
	_exit(103);
	}
	lseek(fd, 0L, SEEK_SET); //set 0
	if ((local_n = read(fd, buf, sizeof buf -1)) == -1) {
		途中
	
	
