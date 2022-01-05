#include <stdio.h>
#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	// char	*output;

	if(argc < 5)
		return(printf("Error: not enough arguments\n"));
	// if(ft_strncmp(argv[1], "here_doc", 9) == 0)
	// 	output = double_redirection(argc, argv);
	// else
		single_redirection(argc, argv, env);
	// printf("%s", output);
}