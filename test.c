#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>
void main()
{
	int fd=open("Folder/file",O_RDONLY);
	char buf[101];
	int b = read(fd,buf,100);
	buf[b]='\0';
	printf("%s\n",buf);
}
