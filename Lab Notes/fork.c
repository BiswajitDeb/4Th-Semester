#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid>0)
	{
		printf("We're in the parent process\n");
	}
	else if (pid == 0)
	{
		printf("We're in the child process");
	}
	return 0;
}
