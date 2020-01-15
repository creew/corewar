/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:48:17 by eklompus          #+#    #+#             */
/*   Updated: 2019/10/06 17:36:48 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "get_next_line.h"

# define ABS(a) ((a) < 0 ? -(a) : (a))
# define MIN(a, b) ((a) < (b) ? (a) : (b))

# define FT_INTMAX	(2147483647)
# define FT_INTMIN	(-FT_INTMAX - 1)

# define FT_LONGMAX	(9223372036854775807)
# define FT_LONGMIN	(-FT_LONGMAX - 1)

# define FT_EOF (-2)

# define FT_ATOI_OK			(0)
# define FT_ATOI_OVERFLOW	(1)
# define FT_ATOI_EMPTY_ARG	(2)
# define FT_ATOI_WRONG_CHAR	(3)

typedef unsigned long t_bzero_elem;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_ftarray
{
	void	**data;
	size_t	num_elems;
	size_t	max_elems;
	size_t	init_val;
}				t_ftarray;

typedef t_ftarray	t_ftstack;

typedef	t_list		t_ftqueue;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);

char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
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
char			*ft_strsub(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);

void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);

void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstfind(t_list *alst, void *cmp,
							int (*f)(t_list *, void *));
t_list			*ft_lstaddblank(t_list **alst, size_t content_size);
char			*ft_strndup(const char *s1, size_t n);
void			*ft_memrealloc(void *data, size_t old_size, size_t new_size);
void			*ft_memndup(const void *mem, size_t size);
char			*ft_strrev(char *str);
int				ft_isspace(int c);
void			ft_intmove(int *dst, int *src, size_t size);
int				ft_getc(int fd);
void			ft_lstaddsorted(t_list **root, t_list *node, void *param,
							int (*cmp)(t_list *, t_list *, void *));
void			ft_lstaddrevsorted(t_list **root, t_list *node, void *param,
						int (*cmp)(t_list *, t_list *, void *));
t_list			*ft_lstnewblank(size_t content_size);
size_t			ft_lstsize(t_list *lst);
t_list			*ft_lstget(t_list *lst, int	index);

int				ft_stack_init(t_ftstack *stack, size_t init_val);
int				ft_stack_pop(t_ftstack *stack, void **data);
int				ft_stack_push(t_ftstack *stack, void *data);
void			ft_stack_delall(t_ftstack *stack, void (*f)(void *));
size_t			ft_stack_size(t_ftstack *stack);

int				ft_queue_add(t_ftqueue **queue, void *data);
int				ft_queue_poll(t_ftqueue **queue, void **data);

long			ft_strtol(const char *nptr, char **endptr, int base);

int				ft_abs(int a);
int				ft_min(int a, int b);
int				ft_max(int a, int b);

void			ft_bubble_sort(void *arr, size_t arr_size, size_t elem_size,
						int (*cmp)(const void *, const void *));
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_safe_atoi(const char *arg, int *res);
char			*ft_strpbrk(const char *s, const char *charset);
char			*ft_trim_spaces(char *str);

void			ft_voidcpy(void **dst, void **src, size_t size);

int				ft_array_init(t_ftarray *ftarray, size_t init_val);
int				ft_array_add(t_ftarray *arr, void *data);
int				ft_array_get(t_ftarray *arr, size_t index, void **data);
int				ft_array_remove(t_ftarray *arr, size_t index,
						void (*f)(void *));
void			ft_array_remove_all(t_ftarray *arr, void (*f)(void *));
size_t			ft_array_size(t_ftarray *arr);
int				ft_array_foreach(t_ftarray *arr, void (*f)(void *adata,
						void *udata), void *param);

void			ft_lstadd_back(t_list **alst, t_list *new);
t_list			*ft_lstremove_if(t_list **root, int (*cmp)(void *, void *),
						void *sec);
t_ftarray		*ft_array_new(size_t init_val);
void			ft_array_delete_all(t_ftarray **arr, void (*f)(void *));
int				ft_array_insert(t_ftarray *arr, void *data, size_t pos);
#endif
