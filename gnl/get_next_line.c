/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:41:18 by chunpark          #+#    #+#             */
/*   Updated: 2024/03/12 16:45:20 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_newline(char **str, int i)
{
	char	*line;
	char	*tmp;

	line = ft_substr(*str, 0, i);
	tmp = ft_strdup(&(*str)[i + 1]);
	free(*str);
	*str = tmp;
	return (line);
}

char	*ft_return_line(char **str, int ret)
{
	char	*line;
	int		i;

	i = 0;
	if (ret < 0)
		return (NULL);
	if (!*str || !**str)
	{
		free(*str);
		return (NULL);
	}
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		return (handle_newline(str, i));
	line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	int			ret;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ft_return_line(&str, ret));
}
