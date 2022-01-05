#include "pipex.h"

int		commandexecution(char *path, char **argarr, int infd, char **env)
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
		execve(path, argarr, env);
	}
	close(fd[1]);
	wait(NULL);
	close(infd);
	return (fd[0]);
}

void	lastcommand(char **argarr, int infd, int outfd, char **env)
{
	dup2(infd, STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	execve(argarr[0], argarr, env);
}