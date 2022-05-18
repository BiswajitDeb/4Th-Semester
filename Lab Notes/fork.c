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


//Fork && and ||

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	if(fork() && fork())
	{
		printf("True\n");
	}
	else	printf("False");
	
	if(fork() || fork())
	{
		printf("True\n");
	}
	else	printf("False\n");

	//pid_t pid;
	//pid = fork();
	//printf("Hello\n");
	//printf("Pid : %d\tPPid : %d",getpid(),getppid());
	//printf("\n");
	return 0;
}
