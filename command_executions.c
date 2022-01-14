#include "pipex.h"

int	execute_commands_child(char **com_arr, int *fd, pipex_info *info)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	execve(com_arr[0], com_arr, info->env);
	perror("Error");
	close(fd[1]);
	exit(-1);
}

int	execute_commands(char **com_arr, pipex_info *info)
{
	int		id;
	int		fd[2];
	int		wstatus;

	pipe(fd);
	dup2(info->infile, STDIN_FILENO);
	id = fork();
	if (id == -1)
		perror("Error");
	if (id == -1)
		return (-1);
	if (id == 0)
		execute_commands_child(com_arr, fd, info);
	close(fd[1]);
	wait(&wstatus);
	// waitpid(id, &wstatus, WNOHANG);
	// printf("this is wstatus: %d\n", wstatus);
	if (wstatus < 0)
		return (-1);
	close(info->infile);
	return (fd[0]);
}

// int	last_command(char **com_arr, pipex_info *info)
// {
// 	int	id;
// 	int	wstatus;

// 	dup2(info->infile, STDIN_FILENO);
// 	dup2(info->outfile, STDOUT_FILENO);
// 	id = fork();
// 	if (id == -1)
// 		perror("Error");
// 	if (id == -1)
// 		return (-1);
// 	if (id == 0)
// 	{
// 		execve(com_arr[0], com_arr, info->env);
// 		perror("Error");	
// 		exit(-1);
// 	}
// 	waitpid(id, &wstatus, WNOHANG);
// 	if (wstatus < 0)
// 		return (-1);
// 	return (0);
// }

int	last_command(char **com_arr, pipex_info *info)
{
	// int	id;
	// int	wstatus;

	dup2(info->infile, STDIN_FILENO);
	dup2(info->outfile, STDOUT_FILENO);
	execve(com_arr[0], com_arr, info->env);
	exit(-1);
}

