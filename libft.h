/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:23:34 by timlecou          #+#    #+#             */
/*   Updated: 2020/08/09 17:08:28 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define SUCCESS_CODE 1
# define EOF_CODE 0
# define ERROR_CODE -1

void			*ft_memset(void *s, int c, size_t n);
void			*ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isdigit(char c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strndup(const char *str, int len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(const char *s, char c);
char			*ft_itoa(int nb);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_putnbr_fd(int nb, int fd);
size_t			ft_strlcat(char *dst, const char *src, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strnstr(const char *h, const char *n, size_t l);
int				ft_printf(const char *format, ...);

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));
typedef	struct	s_pf
{
	int		width;
	int		prec;
	int		left;
	char	conv;
	int		char_nb;
	int		is_prec;
	int		is_zero;
	int		fd;
}				t_pf;

int				pf_ft_len(char *str);
int				ft_printf_fd(int fd, const char *str, ...);
t_pf			pf_ft_init_pf(int fd);
t_pf			pf_ft_fill_pf(char *format, va_list *list, int fd);
char			*pf_ft_get_string(char *str);
char			pf_ft_get_char(int nb, int num);
int				pf_ft_is_flag(char c);
int				pf_ft_skip_nb(char *str);
int				pf_ft_s_int(int nb, t_pf *pf);
int				pf_ft_s_u(unsigned int nb, t_pf *pf);
int				pf_ft_size_uintptr_t(uintptr_t nb);
void			print_conversion(va_list *list, t_pf *pf);
void			pf_ft_print_d(va_list *list, t_pf *pf);
void			pf_ft_print_c(va_list *list, t_pf *pf);
void			pf_ft_print_x(va_list *list, t_pf *pf, int nb);
int				pf_ft_pf_size(char *str, t_pf *pf);
void			pf_ft_print_s(va_list *list, t_pf *pf);
void			pf_ft_print_u(va_list *list, t_pf *pf);
void			pf_ft_print_per(t_pf *pf);
void			pf_ft_print_p(va_list *list, t_pf *pf);
int				pf_ft_set(t_pf *pf, int n, char c);
void			pf_ft_putnbr_fd_u(t_pf *pf, unsigned int nb, int fd);
char			*pf_ft_itoa_u(unsigned int nb, t_pf *pf);
char			*pf_ft_itoa_base_p(uintptr_t nb, int num);
char			*pf_ft_itoa_base_x(unsigned int nb, int num);
int				pf_ft_is_in_str(char c, char *str);
void			pf_ft_write(t_pf *pf, int fd, char *str, int l);
int				pf_ft_get_size_p(uintptr_t ptr);
int				pf_ft_get_size_x(unsigned long long nb);
void			pf_ft_last_change(t_pf *pf);
int				pf_ft_rigth_d2(t_pf *pf, intmax_t nb);
int				pf_ft_left_d2(t_pf *pf, intmax_t nb);
char			*pf_ft_itoa_d(int nb);
char			*ft_strnew(int size);
int				get_next_line(int fd, char **line);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
int				contains_char(char *s, char c);
int				free_string_and_return(char **str, int return_value);
#endif
