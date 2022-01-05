// #include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*getnameofcommand(char *command)
{
	int		ind;
	int 	length;
	char	*temp;

	ind = 0;
	length = ft_strlen(command);
	temp = malloc((sizeof(char) * length) + 1);
	while(ind < length)
	{
		if(command[ind] != ' ')
			temp[ind] =  command[ind];
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
	if(id == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(commarr[0], commarr, __environ);
	}
	else
	{
		close(fd[1]);
		id = read(fd[0], out, 100);
		out[id] = 0;
		return(out);
	}
}

int main()
{
	char *res;
	res = getpath("ls -l");
	printf("%s\n", res);
}