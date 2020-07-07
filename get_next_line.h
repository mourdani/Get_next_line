#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFF_SIZE
#define BUFF_SIZE 7
#endif

char	*ft_strdup(const char *src);
int	join_move(char *store,char **line,int i);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *str);
int	get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*join_free(char *s1, char *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
