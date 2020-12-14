/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:44:18 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/17 17:56:37 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "structures.h"

int		ft_skip_quotes(char *str, int i);
int		ft_count_args(char *str, int index);
int		ft_command_size(char *line);
int		ft_count_commands(const char *str, char c);
void	find_command(char *str, t_cmd *cmd);
int		ft_get_str(char *line);
int		ft_get_word_size(char *line);
void	ft_parse_command(t_data *data);
void	quit(int state, char *str);
int		is_nl(char *str);
int		ft_len(char *str);
int		count_msg(char *str);
void	ft_parsing(t_data *data, int index);
void	ft_do_cmd(t_data *data, int index);
void	ft_del_elem(t_env *elem);
void	ft_free_splitted_array(char **arr);
void	ft_command_nf(char *str);
char	*get_env(t_env *env, char *str);
int		ft_is_valid_arg(char *str);
void	ft_other_cmd(t_data *data, int index);
char	**ft_get_args(t_data *data, char *str, int index, int ac);
char	*replace_str(char *str, char *del, char *repl);
int		get_last_pos(char *str, char c);
char	*get_fd_content(int fd);
int		is_perso_cmd(char *str);
int		count_doube_arr(void **p);
void	*ft_malloc(int n);
void	ft_memadd_back(void *addr);
void	ft_free(void *addr);
void	free_mem();
void	ft_quit(int code);
void	ft_utils_export(int *start);
void	ft_utils_export_2(int *j, int *start);
void	ft_utils_exec(t_data *data, int index, int *pipe_fd);
void	ft_utils_exec2(t_data *data, int index, int *pipe_fd);
void	ft_utils_exec3(t_data *data, int index, int *pipe_fd);
void	ft_utils_pipe(int fd[3][2], char io[2][2048], t_data *data, int j);
void	ft_utils_pipe2(int fd[3][2], char io[2][2048], int ize, t_data *data);
void	ft_utils_pipe3(int fd[3][2], char io[2][2048], int pid, t_data *data);
int		ft_pipe(t_data *data, char *line);
void	ft_print_begin(t_env *env);
void	sig_c(int i);
void	sig_bs(int i);
void	ft_utils_other_cmd(t_data *data, int index, int fd[2], int pid);
void	ft_utils_other_cmd2(t_data *data, int index, int fd[2], char ***env);
void	ft_utils_other_cmd3(char **dir, int index, t_data *data, char *file);
void	ft_utils_other_cmd4(t_data *data, char **file, char **str, int index);
int		file_exist(char *path, char *str, char **file);
int		exec_file(t_data *data, int index, char *file);
int		ft_utils_args(char *str, int index, t_arg **av, t_data *data);
int		ft_has_bs(char *str);
int		ft_count_bs(char *str);
char	*test(char *str);
char	**add_scd(char **arr, char *str, int size);
int		count_prec_bs(char *str, int i);
void	replace_wave(char **s, t_data *data);
int		contains_letter(char *str);

#endif
