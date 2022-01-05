#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
# include <stdlib.h>

# include <unistd.h>

int main()
{
	int check;
	char *XD[] = { "/usr/bin/ls", "-l", NULL};
	check = access("/usr/bin/ls", X_OK);
	printf("check of access = %d\n", check);
	check = execve(XD[0], XD, __environ);
	printf("check of exec = %d\n", check);





}
