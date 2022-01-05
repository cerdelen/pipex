#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int test;
	char* argarr[] ={ "ls", NULL };
	printf("test123\n");
	int id = fork();
	if (id == 0)
		test = execl("ping", "ping", "google.com", NULL);
	else 
		test = 100;
	printf("%d", test);
}