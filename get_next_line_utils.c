#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int     ft_strchr(const char *s, char c)
{
        int             i;

        i = 0;
        while (s[i] && s[i] != (char)c)
                i++;
        if (s[i] != (char)c)
                return (-1);
        return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	if (src && dest)
	{
		i = 0;
		src_size = ft_strlen(src);
		if (size == 0)
			return (src_size);
		while (i++ < size - 1 && *src)
			*dest++ = *src++;
		*dest = '\0';
		return ((i > src_size) ? --i : src_size);
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	a = ft_strlen(src);
	if (!(str = malloc(sizeof(char) * (a + 1))))
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((char *)dst)[i] = ((char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

char		*ft_strnew(size_t size)
{
	char	*result;

	result = (char *)malloc((size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size + 1);
	return (result);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}


char		*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	while (src[i] && i < n)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (dst);
}

void	*ft_bzero(void *b, unsigned int n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)b;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (b);
}


void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}
