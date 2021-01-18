/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:01:41 by mourdani          #+#    #+#             */
/*   Updated: 2021/01/18 15:01:45 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void		ft_strdel(char **as);
size_t		ft_strlen(const char *str);
int			ft_strchr(const char *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strdup(const char *src);
void		*ft_memmove(void *dest, const void *src, size_t len);
int			get_next_line(int fd, char **line);
char		*ft_strnew(size_t size);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strncat(char *dst, const char *src, size_t n);
void		*ft_bzero(void *b, unsigned int n);

#endif
