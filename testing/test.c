#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	int ind = 0;
	char *temp;
	printf("argc = %d\n", argc);
	while(ind <= argc)
	{
		// temp = argv[ind];
		printf("ind = %d   argv[ind] = %s\n", ind, argv[ind]);
		ind++;
	}
	ind = 0;
	while (env[ind] !=NULL)
	{
		printf("%s/|", env[ind]);
		ind++;
	}
}