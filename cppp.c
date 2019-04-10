#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFSIZE 4096

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
	printf("using error\n");
	return ;
    }
    int num=0;
    int fd1,fd2;
    char *buff[BUFFSIZE];
    memset(buff,sizeof(buff),0);
    fd1=open(argv[1],O_RDONLY);
    fd2=open(argv[2],O_WRONLY);
    if(fd1==-1||fd2==-1)
    {
	printf("open error\n");
	return ;
    }
    //num=read(fd1,buff,BUFFSIZE);
    while((num=read(fd1,buff,BUFFSIZE))>0)
    {
	if(num!=write(fd2,buff,num))
	    printf("output error\n");
    }
    //puts(buff);
    printf("%s",buff);
    close(fd1);
    close(fd2);
    return 0;
}
