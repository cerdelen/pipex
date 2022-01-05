#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *test;

	test = malloc(sizeof(char) * 10);
	test[0] = '1';
	test[1] = '1';
	test[2] = '1';
	test[3] = '1';
	test[4] = '1';
	test[5] = '1';
	test[6] = 0;
	printf("%s\n", test);
	free(test);
	printf("%s\n", test);

	test = malloc(sizeof(char) * 10);
	test[0] = '1';
	test[1] = '1';
	test[2] = '1';
	test[3] = '1';
	test[4] = '1';
	test[5] = '1';
	test[6] = 0;
	printf("%s\n", test);
	free(test);
	printf("%s\n", test);

}