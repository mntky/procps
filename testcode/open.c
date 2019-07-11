#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE "text.txt"

void op(char *filename, int fd);
static char buf[1024];

void op(char *filename, int fd) {
	static int local_n;
	if (fd == -1 && (fd = open(filename, O_RDONLY)) == -1 ) {
		fputs("open err", stderr);
		fflush(NULL);
		//_exit(102);
	}
	lseek(fd, 0L, SEEK_SET);
	if ((local_n = read(fd, buf, sizeof buf -1)) < 0) {
		perror(filename);
		fflush(NULL);
		//_exit(103);
	}
	buf[local_n] = '\0';
}

int main() {
	int fd = -1;
	char f[10] = "test.txt";
	char *p = f;
	op(p, fd);
	fputs(buf, stdout);
}
