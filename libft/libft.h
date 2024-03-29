/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:57:50 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 14:24:02 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include "./ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# define ATOI_CONDITION *str == ' ' || *str == '\t' || ATOI_CONDITION2
# define ATOI_CONDITION2 *str == '\n' || *str == '\v' || ATOI_CONDITION3
# define ATOI_CONDITION3 *str == '\f' || *str == '\r'
# define STRTRIM_CONDITION *s == ' ' || *s == '\n' || *s == '\t'
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define TRUE 1
# define FALSE 0
# define SPACE ft_putchar(' ');
# define NEW_LINE ft_putchar('\n');
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"
# define L_RED     "\x1b[1;31m"
# define L_GREEN   "\x1b[1;32m"
# define L_YELLOW  "\x1b[1;33m"
# define L_BLUE    "\x1b[1;34m"
# define L_MAGENTA "\x1b[1;35m"
# define L_CYAN    "\x1b[1;36m"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef	unsigned char	t_byte;

int				ft_words(char const *str, int c);
char			*ft_strmjoin(int num, ...);
void			ft_lstpush(t_list **list, t_list *new);
size_t			ft_lstcount(t_list *lst);
void			ft_putchar(char z);
void			ft_putstr(const char *str);
void			ft_putnbr(int num);
size_t			ft_strlen(const char *str);
size_t			ft_strnlen(const char *str, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			ft_bzero_bwd(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memcpy_bwd(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strdup(char const *src);
char			*ft_strcpy(char *des, const char *src);
char			*ft_strncpy(char *des, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *csrc, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isspace(char x);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnjoin(char const *s1, char const *s2, int size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s1, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, int c);
void			ft_print2d(char **array);
void			ft_print_byte(t_byte byte);
char			*ft_itoa(int n);
void			ft_putendl(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr_fd(int nb, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			*ft_bubblesort(int *array, size_t array_size);
void			ft_print_array_int(int *array, size_t array_size);
void			*push(void *array, size_t len, void *data, size_t data_len);

#endif
