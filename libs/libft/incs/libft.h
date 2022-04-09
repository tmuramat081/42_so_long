/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:55 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 23:35:19 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_vector2 {
	int	x;
	int	y;
}	t_vector2;

/*** checker functions ***/
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);

/*** convert functions ***/
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);

/*** string functions ***/
size_t		ft_strlen(const char *c);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
long		ft_strtol_d(const char *nptr, char **endp);
size_t		ft_strcspn(const char *s1, const char *s2);
void		ft_strtoupper(char *str);

/*** memory functions ***/
void		ft_bzero(void *p, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memchr(const void *buff, int ch, size_t n);
int			ft_memcmp(const void *buff1, const void *buff2, size_t n);
void		*ft_memset(void *p, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_matrixlen(const char **src);
char		**ft_matrixdup(const char **src);
void		ft_free_matrix(char ***src);

/*** print functions ***/
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*** list functions ***/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*** math functions ***/
t_vector2	ft_vector_add(t_vector2 v1, t_vector2 v2);
t_vector2	ft_vector_sub(t_vector2 v1, t_vector2 v2);
t_vector2	ft_vector_mul(t_vector2 v1, float t);
bool		ft_vector_cmp(t_vector2 v1, t_vector2 v2);
t_vector2	ft_vector_lerp(t_vector2 v1, t_vector2 v2, float t);
int			ft_abs(int n);
int			ft_count_digits(long long int num, int radix);

#endif