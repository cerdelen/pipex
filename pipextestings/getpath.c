#include "pipex.h"

char	*getnameofcommand(char *command)
{
	int		ind;
	int		length;
	char	*temp;

	ind = 0;
	length = ft_strlen(command);
	temp = malloc((sizeof(char) * length) + 1);
	while (ind < length)
	{
		if (command[ind] != ' ')
			temp[ind] = command[ind];
		else
			break ;
		ind++;
	}
	temp[ind] = 0;
	return (temp);
}

char	*getpath(char *command)
{
	char	*out;
	int		fd[2];
	int		id;
	char	*commarr[3];

	commarr[0] = "/usr/bin/which";
	commarr[1] = getnameofcommand(command);
	commarr[2] = NULL;
	pipe(fd);
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(commarr[0], commarr, __environ);
	}
	close(fd[1]);
	out = malloc(sizeof(char) * 100);
	id = read(fd[0], out, 100);
	out[id - 1] = ' ';
	out[id] = 0;
	free(commarr[1]);
	return (out);
}
