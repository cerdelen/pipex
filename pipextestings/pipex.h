#ifndef PIPEX_H

# define PIPEX_H

#include "./Libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>       //delete when finished with project!!!!!

char	*single_redirection(int argc, char **argv);
char	*getpath(char *command);
char	*getnameofcommand(char *command);
void	freecommandarguments(char **stringarr);
int		commandexecution(char *path, char **argarr, int infd);
void	lastcommand(char *path, char **argarr, int infd, int outfd);

#endif


///seriosuly delete it