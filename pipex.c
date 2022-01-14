#include "pipex.h"

int	setting_up_structure(int argc, char **argv,
	char **env, pipex_info *info)
{
	info->error = 0;
	info->argc = argc;
	info->argv = argv;
	info->env = env;
	info->command_arrays = malloc(sizeof(char**) * (argc -2));
	info->infile = open(argv[1], O_RDONLY);
	if (info->infile < 0)
		return ((printf("Error: %s : %s\n",argv[1] ,strerror(errno)) * 0) -1);				//make em ft_printf
	info->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (info->outfile < 0)
		return ((printf("Error: %s : %s\n",argv[argc - 1],									//make em ft_printf
			strerror(errno)) * 0) -1);

	// printf("infile fd %d outfile fd %d \n", info->infile, info->outfile);
	// info->which_com_arr[0] = "/usr/bin/which";
	// info->which_com_arr[3] = NULL;

	return (0);
}

void	free_remains(pipex_info *info)
{
	int ind;

	ind = 0;
	while (info->command_arrays[ind] != NULL)
	{
		free(info->command_arrays[ind][0]);
		ind++;
	}
	free(info->command_arrays);
}

int	main(int argc, char **argv, char **env)
{
	pipex_info	*info;
	int			ret;

	// if (argc < 5)
	// 	return ((ft_printf("Error: Not enough arguments\n") * 0) -1);
	// if (argc < 5)
	// 	return (ft_printf("Error: Not enough arguments\n"));
	if (argc < 5)
		return (printf("Error: Not enough arguments\n"));
	// if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	// 	return (double_redirection(argc, argv, env));
	info = (pipex_info *)malloc(sizeof(pipex_info));
	ret = setting_up_structure(argc, argv, env, info);
	if (ret != 0)
		return (ret);
	ret = single_redirection(info);
	// free_remains(info);
	free(info);
	return (ret);
}
