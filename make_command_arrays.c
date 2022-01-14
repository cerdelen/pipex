#include "pipex.h"

void	make_path_child(char **which_command_arr, int *fd, pipex_info *info)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	execve(which_command_arr[0], which_command_arr, info->env);
	perror("Error");
	close(fd[1]);
	exit(-1);
}

char	*make_path_parent(int *fd, char *name)
{
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * 100);								///maybe getnextline
	ret = read(fd[0], buf, 100);
	if (ret == 0)
	{
		printf("Error: %s : %s", name, strerror(errno));			////make it ft_printf
		return ("ERRORMESSAGE");
	}
	buf[ret - 1] = 0;
	close(fd[0]);
	return (buf);
}

char	*make_path(char *name, pipex_info *info)
{
	char	*out;
	char	*which_command_arr[3];
	int		fd[2];
	int		id;
	int		wstatus;

	which_command_arr[0] = "/usr/bin/which";
	which_command_arr[1] = name;
	which_command_arr[2] = NULL;
	pipe(fd);
	id = fork();
	if (id == -1)
		perror("Error");
	if (id == -1)
		return ("ERRORMESSAGE");
	if (id == 0)
		make_path_child(which_command_arr, fd, info);
	close(fd[1]);
	wait(&wstatus);
	free(name);
	if (wstatus == -1)
		return ("ERRORMESSAGE");
	out = make_path_parent(fd, name);
	return (out);
}

int	make_command_arrays(pipex_info *info, char ***com_arrays)
{
	int	ind;
	int	error;

	error = 0;
	ind = 2;
	while (ind < (info->argc - 1))
	{
		com_arrays[ind - 2] = ft_split(info->argv[ind], ' ');
		com_arrays[ind - 2][0] = make_path(com_arrays[ind - 2][0], info);
		if (ft_strncmp(com_arrays[ind -2][0], "ERRORMESSAGE", 13) == 0)
			error = -1;
		ind++;
	}
	// printf("this is command array ind of NULL = %d\n", ind -2);
	com_arrays[ind - 2] = NULL;
	if (error != 0)
		return (-1);
	return (0);
}
