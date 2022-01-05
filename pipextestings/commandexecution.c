#include "pipex.h"

int		commandexecution(char *path, char **argarr, int infd)
{
	int		id;
	int		fd[2];

	pipe(fd);
	dup2(infd, STDIN_FILENO);
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(path, argarr, __environ);
	}
	close(fd[1]);
	wait(NULL);
	close(infd);
	return (fd[0]);
}

void	lastcommand(char *path, char **argarr, int infd, int outfd)
{
	dup2(infd, STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	execve(path, argarr, __environ);
}