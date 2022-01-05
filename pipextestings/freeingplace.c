#include "pipex.h"

void	freecommandarguments(char **stringarr)
{
	int	ind;

	ind = 0;
	while (stringarr[ind] != NULL)
	{
		free(stringarr[ind]);
		ind++;
	}
	free(stringarr);
}
