# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 21:48:26 by Cerdelen          #+#    #+#              #
#    Updated: 2022/01/04 21:48:26 by Cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Wall -Werror

NAME = pipex

AR = ar rcs

SRCS =  check_access.c command_executions.c make_command_arrays.c pipex.c single_redirection.c

OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(MAKE) -C Libft
	$(AR) $(NAME).a $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) pipex.a ./Libft/libft.a 

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	$(MAKE) fclean -C Libft
	$(RM) $(OBJS) $(NAME).a

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: bonus all clean fclean re