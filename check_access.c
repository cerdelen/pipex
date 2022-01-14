#include "pipex.h"

int	check_access(char ***command_arrays)
{
	int	ind;
	int	ret;
	int	error;

	ind = 0;
	error = 0;
	while (command_arrays[ind] != NULL)
	{
		ret = access(command_arrays[ind] [0], X_OK);
		if (ret != 0)
		{
			error = -1;
			perror("Error");
		}
		ind++;
	}
	return (error);
}