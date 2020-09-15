/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:09:42 by mourdani          #+#    #+#             */
/*   Updated: 2020/08/13 01:52:35 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len;

	len_s1 = 0;
	len_s2 = ft_strlen(s2);
	if (s1)
		len_s1 = ft_strlen(s1);
	len = len_s1 + len_s2;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(result, s1, (len_s1 + 1));
		ft_strdel(&s1);
	}
	ft_strlcpy(result + len_s1, s2, (len_s2 + 1));
	return (result);
}

int			join_move(char *store, char **line, int i)
{
	*line = ft_substr(store, 0, i);
	i++;
	store = ft_memmove(store, store + i, (ft_strlen(store + i) + 1));
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*store;
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (store && ((i = ft_strchr(store, '\n')) != -1))
		return (join_move(store, line, i));
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		store = ft_strjoin_gnl(store, buff);
		if (store && ((i = ft_strchr(store, '\n')) != -1))
			return (join_move(store, line, i));
	}
	if (store)
	{
		*line = ft_strdup(store);
		free(store);
		store = NULL;
		return (ret);
	}
	*line = ft_strdup("");
	return (0);
}
