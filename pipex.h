#ifndef PIPEX_H

# define PIPEX_H

#include "./Libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>       //delete when finished with project!!!!!

typedef struct info_list_pipex
{
	int			argc;
	char		**argv;
	char		**env;
	char		***command_arrays;
	int			infile;
	int			outfile;
	int			error;
}					pipex_info;


int			single_redirection(pipex_info *info);
int			make_command_arrays(pipex_info *info, char ***com_arrays);
int			check_access(char ***command_arrays);
int			execute_commands(char **com_arr, pipex_info *info);
int			last_command(char **com_arr, pipex_info *info);



#endif







///seriosuly delete it