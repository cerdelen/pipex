#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char * command [] = { "/usr/bin/ls", NULL};
	execve(command[0], command, __environ);
}