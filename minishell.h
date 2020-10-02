

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 32
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include <fcntl.h>
# include "structures.h"

t_env	*ft_fill_env_list(char **envp);
void    ft_lstclear(t_env **env, void (*ft_del_elem)(t_env *));
void    ft_do_cmd(t_data *data, int index);
void	ft_del_elem(t_env *elem);
void    ft_other_cmd(t_data *data, int index);
char    **ft_get_args(t_data *data, char *str, int index, int ac);
void    ft_echo(t_data *data, int index);
void    ft_pwd(t_data *data);
void	ft_env(t_data *data);
void	ft_cd(t_data *data, int index);
void	ft_free_splitted_array(char **arr);
void	ft_free_data_struct(t_data *data);
void	ft_unset(t_data *data, int index);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
t_data  init_data_struct(void);
t_cmd   init_cmd_struct(void);
int     ft_count_args(char *str, int index);
int     ft_command_size(char *line);
int     ft_count_commands(const char *str, char c);
void    find_command(char *str, t_cmd *cmd);
int     ft_get_str(char *line);
int     ft_get_word_size(char *line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void    ft_parse_command(t_data *data);
char	*ft_strndup(const char *str, int nb);
char	**ft_split(const char *str, char c);
char    **ft_split_args(const char *str, char c);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
int	    ft_strcmp(const char *s1, const char *s2);
int	    get_next_line(int fd, char **line);
void	ft_putstr(char *str);
char    *ft_itoa(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
char    *ft_inc_shlvl(char *str);
int     ft_atoi(const char *str);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
void	quit(int state, char *str);
char	*ft_cut(char *str);
char	*ft_cut_begin(char *str);
int	is_nl(char *str);
char	*ft_strdup(const char *str);
int	ft_len(char *str);
int	count_msg(char *str);
void	ft_parsing(t_data *data, int index);
#endif
