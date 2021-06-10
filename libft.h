/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:18:39 by abensett          #+#    #+#             */
/*   Updated: 2021/06/10 20:51:45 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

/*Part 1*/

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n); /* Write n zeros*/
void	*ft_calloc(size_t count, size_t size);/* malloc + only 0  zeros*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
/*-> copies  n bytes   
  -> stop at c 
  -> returns pointer in dest at c
  -> Otherwise, n bytes copied, return NULL.*/

void	*ft_memchr(const void *s, int c, size_t n);
/*-> locates of c (converted to an unsigned char).
 * -> returns pointer */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/*The memcmp() function compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.*/

void	*ft_memcpy(void *dest, const void *src, size_t n);
/* ->copies n bytes  area dst..*/

void	*ft_memmove(void *dest, const void *src, size_t n);
/* ->  copies len bytes f
 * -> overlap ? = the copy is always done in a non-destructive
     manner.*/
void	*ft_memset(void *s, int c, size_t n);
/* -> write character c  =  n times*/

char	*ft_strchr(const char *s, int c);
/* -> 1st occurrence of c (converted to a char)
 * -> the terminating null included (can be c)*/

char	*ft_strdup(const char *s1);
/* -> function allocates sufficient memory for a copy.*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/*	-> copy  strings
 *	-> designed to be safer, more consistent, and less error prone replacements
     for the easily misused functions strncpy(3) and strncat(3).*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*  -> strlcat()  concatenate strings with
 *  -> dest then src
 *  -> max = dstsize - destlen -1*/

size_t	ft_strlen(const char *s);
/* -> len  without (\0)*/

int		ft_strncmp(const char *s1, const char *s2, size_t n);
/* -> compares not more than n characters. */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/*->locates the first occurrence of the null-terminated
     string needle in the null-terminated string haystack 
-> not more than len character seached*/

char	*ft_strrchr(const char *s, int c);
/*->     The strrchr() function is identical to strchr(), except
	 it locates the last occurrence
     of c.*/

int		ft_tolower(int c);
int		ft_toupper(int c);

/* PART 2 */
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
/* write a str in fd avec un retour a la ligne*/
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
/*concatene de str*/
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/* f(c) for every  c in s*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
/* create a string from s, starting at start and lens = len*/
char	*ft_strtrim(char const *s1, char const *set);

typedef struct s_list
{	
	void			*content;
	struct s_list	*next;
}					t_list;

/* PART 3 */

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
#endif
