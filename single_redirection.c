#include "pipex.h"

char	**makecommandarg(char *command, char **env)
{
	char	*temp1;
	char	*temp2;
	char	**out;

	temp1 = getpath(command, env);
	if ((temp2 = ft_strchr(command, ' ')))
	{
		temp2 = ft_strjoin(temp1, temp2 + 1);
		out = ft_split(temp2, ' ');
		free(temp2);
	}
	else
		out = ft_split(temp1, ' ');
	free(temp1);
	return (out);
}


char	*single_redirection(int argc, char **argv, char **env)
{
	int		ind;
	int		infd;
	int		outfd;
	char	**commandarguments;

	outfd = open(argv[argc - 1], O_WRONLY | O_CREAT,  0777);
	infd = open(argv[1], O_RDONLY);
	ind = 2;
	while (ind < argc - 2)
	{
		commandarguments = makecommandarg(argv[ind], env);
		infd = commandexecution(commandarguments[0], commandarguments, infd, env);
		freecommandarguments(commandarguments);
		ind++;
	}
	commandarguments = makecommandarg(argv[ind], env);
	lastcommand(commandarguments, infd, outfd, env);
	freecommandarguments(commandarguments);
	return ("abc");
}
