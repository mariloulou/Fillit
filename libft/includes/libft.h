/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 00:06:46 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/08 14:34:23 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <================================= TODO =================================> **
** Write sorting functions (sortinttab)
** Write hash functions
** Write array functions
** Write file reading functions
** Find other mathematical functions
** strcapitalize, tablen, strnjoin
*/

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define CHAR_MIN	-128
# define CHAR_MAX	127
# define UCHAR_MAX	255
# define SHRT_MIN	-32768
# define SHRT_MAX	32767
# define USHRT_MAX	65535
# define INT_MIN	-2147483648
# define INT_MAX	2147483647
# define UINT_MAX	4294967295
# define LONG_MIN	-2147483648
# define LONG_MAX	2147483647
# define ULONG_MAX	4294967295

/*
** <========================= Binary Tree Functions ========================> **
*/

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*data;
}					t_btree;

int					ft_btree_lvlcount(t_btree *root);
t_btree				*ft_btree_nodenew(void *data);
t_btree				*ft_btree_search_data(t_btree *root, void *data,
					int (*fcmp)(void *, void *));
void				ft_btree_apply_infix(t_btree *root,
					void (*fapply)(void *));
void				ft_btree_apply_prefix(t_btree *root,
					void (*fapply)(void *));
void				ft_btree_apply_suffix(t_btree *root,
					void (*fapply)(void *));
void				ft_btree_insert_data(t_btree **root,
					void *data, int (*fcmp)(void *, void *));
void				ft_btree_treedel(t_btree **root,
					void (*fdel)(void *));

/*
** Future funcions :
** void				ft_btree_nodedel(t_btree *node, void (*fdel)(void *));
** void				ft_btree_apply_breadth(t_btree *root,
**					void (*fapply)(void *));
** void				ft_btree_egalize(t_btree **root);
** Red & Black btree functions
*/

/*
** <=========================== Display functions ==========================> **
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putnendl(char const *s, size_t n);
void				ft_putnendl_fd(char const *s, int fd, size_t n);
void				ft_putnstr(char const *s, size_t n);
void				ft_putnstr_fd(char const *s, int fd, size_t n);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);

/*
** <============================ List functions ============================> **
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);

/*
** <================================= Math =================================> **
*/

int					ft_abs(int nb);
int					ft_isprime(unsigned int nb);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_sign(int nb);
unsigned int		ft_power(int nb, unsigned int power);
unsigned int		ft_sqrt(unsigned int nb);

/*
** <=========================== Memory functions ===========================> **
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memrchr(const void *s, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);

/*
** <============================ Misc functions ============================> **
*/

char				*ft_basename(const char *filename);
char				*ft_dirname(char *filename);
char				*ft_itoa(int n);
int					ft_atoi(const char *s);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_iscntrl(char c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_ispunct(char c);
int					ft_isspace(char c);
int					ft_isxdigit(char c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** <=========================== String functions ===========================> **
*/

char				**ft_strsplit(char const *s, char c);
char				*ft_strcasestr(const char *s1, const char *s2);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strndup(const char *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_strcasecmp(char const *s1, char const *s2);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
