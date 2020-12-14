SRCS = minishell.c srcs/other/init.c srcs/utils/utils_list.c srcs/parsing/parsing_1.c\
		srcs/parsing/parsing_2.c \
       srcs/utils/ft_splits.c srcs/utils/env_utils.c srcs/utils/get_next_line.c\
       srcs/utils/get_next_line_utils.c srcs/other/error.c srcs/commands/ft_echo.c\
       srcs/commands/ft_pwd.c srcs/commands/ft_env.c srcs/commands/ft_cd.c\
       srcs/utils/free.c srcs/commands/ft_unset.c srcs/commands/ft_export.c\
       srcs/utils/libft_1.c srcs/utils/libft_2.c srcs/utils/libft_3.c\
       srcs/utils/string_utils.c srcs/commands/exec_command.c\
	srcs/utils/env_utils_2.c srcs/parsing/redirection.c\
	srcs/utils/utils_list_2.c srcs/commands/ft_export2.c\
	srcs/utils/utils_exec.c srcs/parsing/pipe2.c srcs/utils/utils_sig.c\
	srcs/utils/utils_other_cmd.c\
	srcs/parsing/redirection_utils.c\
	srcs/utils/ft_splits2.c\
	srcs/utils/free2.c\
	srcs/parsing/parsing_1_utils.c\
	srcs/utils/string_utils2.c\
	srcs/utils/utils_list_3.c\
	srcs/parsing/redirection_utils_2.c\
	srcs/parsing/redirection_utils_3.c\
	srcs/parsing/redirection_utils_4.c\
	srcs/parsing/parsing_bs.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc #-ggdb -fsanitize=address
RM				= rm -f
INCLUDE			= -I./include/
CFLAGS			= -Wall -Wextra
LIBS			= 

NAME			= minishell

all:			$(NAME) $(clean)

%.o: %.c
				${CC} -c ${CFLAGS} ${INCLUDE} ${LIBS} $< -o $@

$(NAME):		$(OBJS)
				${CC} $(OBJS) ${INCLUDE} ${CFLAGS} ${LIBS} -o $(NAME)

clean:
				$(RM) ${OBJS}

fclean:			clean
				$(RM) $(NAME)

%:
		@:

bonus: re


re:				fclean all

.PHONY:			all clean fclean re bonus
