#include <stdio.h> // standard input output
#include <stdlib.h>
#include <sys/stat.h> // mkfifo
#include <unistd.h>
#include <string.h>
#include <linux/stat.h>

int main(int argc, char** argv)
{
	FILE *fp;
	const char * fifo = "/tmp/named_pipe";
	mkfifo(fifo, 0666);

	char buf[10];

	fp = fopen(fifo, "r");
	fgets(buf, 10, fp);
	printf("Received string: %s\n", buf);
	fclose(fp);

	return 0;
}
