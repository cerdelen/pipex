#include "pipex.h"

int	single_redirection(pipex_info *info)
{
	int		ret;
	int		ind;
	
	ind = 0;
	ret = make_command_arrays(info, info->command_arrays);
	if (ret != 0)
		return (-1);
	ret = check_access(info->command_arrays);
	if (ret != 0)
		return (-1);
	while (ind < (info->argc - 4))
	{
		// printf("this is in beginning info->infile: %d\n", info->infile);
		// printf("this is in beginning info->outfile: %d\n", info->outfile);
		// printf("ind: %d  <  info->argc -2 :%d\n", ind, (info->argc-2));
		info->infile = execute_commands(info->command_arrays[ind], info);
		// printf("this is info->infile: %d\n", info->infile);
		if (info->infile < 0)
			return (-1);
		ind++;
	}
	ret = last_command(info->command_arrays[ind], info);
	// free(info->command_arrays);
	// printf("sfdioisdfjiosdijiojfsdiojfsd\n\n");
	// printf("This is info->error: %d\n", info->error);
	return (ret);
}