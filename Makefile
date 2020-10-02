NAME = minishell

SRCS = minishell.c init.c utils_1.c parsing.c ft_split.c ft_substr.c ft_strlen.c ft_strdup.c ft_strndup.c\
       utils_2.c get_next_line.c get_next_line_utils.c error.c\
       ft_echo.c utils_list.c ft_pwd.c ft_env.c ft_cd.c utils_3.c\
       ft_unset.c ft_split_args.c utils_4.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

all:
	$(CC)  $(SRCS) -o $(NAME)
