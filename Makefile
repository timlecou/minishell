NAME = minishell

SRCS = minishell.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

all:
	$(CC) $(FLAGS) libft.a $(SRCS) -o $(NAME)
