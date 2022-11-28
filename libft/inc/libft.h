/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:55:39 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/28 16:46:09 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define RED "\033[0;31m"
# define GREEN "\033[0;92m"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_intlst
{
	int				value;
	struct s_intlst	*next;
}					t_intlst;

int			ft_isalnum(char c);
int			ft_isalpha(char c);
int			ft_isascii(char c);
int			ft_ischarset(char c, const char *set);
int			ft_isdigit(char c);
int			ft_isline(char *str);
int			ft_isprint(char c);
int			ft_isspace(int c);
int			ft_isint(char *str);
int			ft_is_samesign(int a, int b);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);

int			ft_putchar_fd(int c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);
int			ft_putunbr_fd(unsigned int n, int fd);
int			ft_putuhexnbr_fd(size_t n, int fd, char cs);

char		**ft_split(const char *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strcat(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);

int			ft_abs(int n);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_digitcount(unsigned long n, int base);
int			ft_max(int a, int b);

int			ft_printf(const char *str, ...);
char		*ft_gnl(int fd);

t_intlst	*ft_intlst_new(int value);
t_intlst	*ft_intlst_last(t_intlst *lst);
t_intlst	*ft_intlst_before_last(t_intlst *lst);
void		ft_intlst_addback(t_intlst **lst, t_intlst *new);
void		ft_intlst_free(t_intlst **lst);
void		ft_intlst_print(t_intlst *lst);
t_intlst	*ft_args_to_intlst(int argc, char **argv);
int			ft_intlst_issorted(t_intlst *lst);
int			ft_intlst_isrevsorted(t_intlst *lst);
int			ft_intlst_minval(t_intlst *lst);
int			ft_intlst_maxval(t_intlst *lst);
size_t		ft_intlst_size(t_intlst *lst);

#endif
