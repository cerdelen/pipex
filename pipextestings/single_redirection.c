#include "pipex.h"

void printargarr(char **knoodle)
{
	int ind;

	ind = 0;
	while (knoodle[ind] != NULL)
	{
		printf("this is argument nr %d = %s\n", ind +1, knoodle[ind]);
		ind++;
	}
}

char	**makecommandarg(char *command)
{
	char	*temp1;
	char	*temp2;
	char	**out;

	temp1 = getpath(command);
	if ((temp2 = ft_strchr(command, ' ')))
		temp1 = ft_strjoin(temp1, temp2 + 1);
	out = ft_split(temp1, ' ');
	free(temp1);
	return (out);
}


char	*single_redirection(int argc, char **argv)
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
		commandarguments = makecommandarg(argv[ind]);
		// printargarr(commandarguments);
		infd = commandexecution(commandarguments[0], commandarguments, infd);
		freecommandarguments(commandarguments);
		ind++;
	}
	commandarguments = makecommandarg(argv[ind]);
	// printargarr(commandarguments);
	lastcommand(commandarguments[0], commandarguments, infd, outfd);
	freecommandarguments(commandarguments);
	return ("abc");
}
