#ifndef PIPEX_H

# define PIPEX_H

#include "./Libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>       //delete when finished with project!!!!!

char	*single_redirection(int argc, char **argv, char **env);
char	*getpath(char *command, char **env);
char	*getnameofcommand(char *command);
void	freecommandarguments(char **stringarr);
int		commandexecution(char *path, char **argarr, int infd, char **env);
void	lastcommand(char **argarr, int infd, int outfd, char **env);

#endif


///seriosuly delete it