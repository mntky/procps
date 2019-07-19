# procps uptime

[uptime.c]

```c
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

```c
int uptime(double *restrict uptime_secs, double *restrict idle_secs) {
	double up=0, idle=0;
	char *restrict savelocale;

	FILE_TO_BUF(UPTIME_FILE,uptime_fd); // /proc/uptime, -1
~
```

[proc/sysinfo.c :54]

```c
#define FILE_TO_BUF(filename, fd) do{
	static int local_n;
	/* ファイルのオープン */
	if (fd == -1 && (fd = open(filename, 0_RDONLY)) == -1) {
	fputs(BAD_OPEN_MESSAGE, stderr); //write to stderr
	fflush(NULL); //all stream
	_exit(103);
	}

	/* ファイルの先頭にシーク	*/
	lseek(fd, 0L, SEEK_SET); 

	/* ↑でfd（handle)に繋がってるファイルから、 */
	/* buf-1(2047byte)分bufに読み込み			*/
	/* local_nには読み込んだbyte数を返す		*/
	if ((local_n = read(fd, buf, sizeof buf -1)) == -1) {
	perror(filename);
	fflush(NULL);
	_exit(103);
	}
	/*local_nバイト目に'\0'をに書き込み*/
	/*/proc/uptimeに(例 753.86 2942.88)みたいな感じで書いてある*/
	buf[local_n] = '\0';
}while(0)
```


[proc/sysinfo.c :80]

```c
/*現状のlocale一旦保存しておく*/
/*setlocale(LC_NUMERIC, NULL)自分の環境では67帰ってきた*/
savelocale = setlocale(LC_NUMERIC, NULL);

/*localeをCにセット"*/
setlocale(LC_NUMERIC, "C"); 

/*bufの中身をupとidleに入れる*/
/*bufには " 753.86 2942.88 \0 " データ入っている */
if (sscanf(buf, "%lf %lf", &up, &idle) < 2) {
	/*もとのlocaleに戻す*/
	setlocale(LC_NUMERIC, savelocale);
	fputs("bad data in" UPTIME_FILE "\n", stderr);
	return 0;
}
/*もとのlocaleに戻す*/
setlocale(LC_NUMERIC, savelocale);
/*uptime_secsがnullじゃなかったらuptime_secsにup入れる*/
SET_IF_DESIRED(uptime_secs, up);
/*idle_secsがnullじゃなかったらidle_secsにidle入れる*/
SET_IF_DESIRED(idle_secs, idle);
return up;
```

[proc/whattime.c :48]

```c
/* proc/sysinfoで/proc/uptimeから取ったデータ
uptime(&uptime_secs, &idle_secs);
/*uptime_secs 計算して起動して何日立っているか計算*/
updays = (int) uptime_secs / (60*60*24);
/*bufの後ろに"up"を連結*/
strcat (buf, "up");
pos += 3;
if(updays)
	pos += sprintf(buf + pos, %d day%d, ", updays, (updays != 1) ? "s" : "");
upminutes = (int) uptime_secs / 60;
uphours = upminutes / 60;
/* uphoursを24で割って余りをuphoursに入れておく*/
uphours = uphours % 24;
upminutes = upminutes % 60;
if(uphours)
	pos += sprintf(buf + pos, "%2d:%02d, ", uphours, upminutes);
else
	pos += sprintf(buf + pos, "%d min, ", upminutes);

numuser = 0;
setutent();
while((utmpstruct = getutent())) {

/* 途中 */






```
