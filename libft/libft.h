/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:18:39 by abensett          #+#    #+#             */
/*   Updated: 2021/06/09 15:02:42 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <stdlib.h>

/*partie 1*/

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
/*The memccpy() function copies bytes from string src to string dst.  If
     the character c (as converted to an unsigned char) occurs in the string
     src, the copy stops and a pointer to the byte after the copy of c in the
     string dst is returned.  Otherwise, n bytes are copied, and a NULL
     pointer is returned.*/

void	*ft_memchr(const void *s, int c, size_t n);
/*The memchr() function locates the first occurrence of c (converted to an
     unsigned char) in string s.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**The memcmp() function compares byte string s1 against byte string s2.
     Both strings are assumed to be n bytes long.*/

void	*ft_memcpy(void *dest, const void *src, size_t n);
/* The memcpy() function copies n bytes from memory area src to memory area
     dst.  If dst and src overlap, behavior is undefined.  Applications in
     which dst and src might overlap should use memmove(3) instead.*/

void	*ft_memmove(void *dest, const void *src, size_t n);
/*The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner.*/
void	*ft_memset(void *s, int c, size_t n);
/*The memset() function writes len bytes of value c (converted to an
     unsigned char) to the string b.*/

char	*ft_strchr(const char *s, int c);
/*The strchr() function locates the first occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is `\0', the func-
     tions locate the terminating `\0'*/

char	*ft_strdup(const char *s1);
/* The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.  The pointer may
     subsequently be used as an argument to the function free(3).*/

size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
/*iThe strlcpy() and strlcat() functions copy and concatenate strings with
     the same input parameters and output result as snprintf(3).  They are
     designed to be safer, more consistent, and less error prone replacements
     for the easily misused functions strncpy(3) and strncat(3).*/

size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
/*The strlcpy() and strlcat() functions copy and concatenate strings with
     the same input parameters and output result as snprintf(3).  They are
     designed to be safer, more consistent, and less error prone replacements
     for the easily misused functions strncpy(3) and strncat(3).*/

size_t	ft_strlen(const char *s);
 /*The strlen() function computes the length of the string s.  The strnlen()
     function attempts to compute the length of s, but never scans beyond the
     first maxlen bytes of s.*/

int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*The strncmp() function compares not more than n characters.  Because
     strncmp() is designed for comparing strings rather than binary data,
     characters that appear after a `\0' character are not compared.*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/*The strstr() function locates the first occurrence of the null-terminated
     string needle in the null-terminated string haystack.

     The strcasestr() function is similar to strstr(), but ignores the case of
     both strings.

     The strnstr() function locates the first occurrence of the null-termi-
     nated string needle in the string haystack, where not more than len char-
     acters are searched.  Characters that appear after a `\0' character are
     not searched.  Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.

     While the strcasestr() function uses the current locale, the
     strcasestr_l() function may be passed a locale directly. See xlocale(3)
     for more information.*/

char *ft_strrchr(const char *s, int c);
/*The strchr() function locates the first occurrence of c (converted to a char) in the
     string pointed to by s.  The terminating null character is considered to be part of the
     string; therefore if c is `\0', the functions locate the terminating `\0'.

     The strrchr() function is identical to strchr(), except it locates the last occurrence
     of c.*/

int	ft_tolower(int c);
int	ft_toupper(int c);

char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);

typedef struct		s_list
{	
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list				*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);


#endif
