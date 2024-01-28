/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:12:36 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/08 16:28:55 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_lstsize(t_list	*lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
char	*ft_itoa(int n);
char	*ft_strchr(const char	*s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(const char	*s1);
char	*ft_substr(char	const	*s, unsigned int start, size_t	len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char	const	*s, char (*f)(unsigned	int, char));
char	**ft_split(char	const	*s, char c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
long	ft_atoi(const char	*str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_strncmp(const char	*s1, const char	*s2, unsigned int n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_memcmp(const void	*s1, const void	*s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void	*dst, const void	*src, size_t len);
void	ft_bzero(void	*s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char	*s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_calloc(size_t	count, size_t	size);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char	*s, void (*f)(unsigned	int, char*));
#endif
