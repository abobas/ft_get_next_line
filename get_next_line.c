/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:14:32 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:14:32 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*save[INT_MAX];
	ssize_t			ret;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strdup("");
	if (!save[fd])
		return (-1);
	save[fd] = ft_read(save, fd, ret);
	if (!save[fd])
		return (-1);
	return (ft_makeline(save, line, fd));
}

char	*ft_read(char **save, int fd, ssize_t ret)
{
	char		*buf;

	while (ret > 0)
	{
		buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
		{
			free(save[fd]);
			return (0);
		}
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buf);
			free(save[fd]);
			return (0);
		}
		buf[ret] = '\0';
		save[fd] = ft_strcat(save[fd], buf);
		if (!save[fd])
			return (0);
		if (ft_check(save[fd]))
			break ;
	}
	return (save[fd]);
}

int		ft_makeline(char **save, char **line, int fd)
{
	int		i;

	i = 0;
	while (save[fd][i] != '\n' && save[fd][i] != '\0')
		i++;
	if (save[fd][i] == '\n')
	{
		*line = ft_substr(save[fd]);
		if (!*line)
		{
			free(save[fd]);
			return (-1);
		}
		save[fd] = ft_strchr(save[fd], '\n');
		if (!save[fd])
			return (-1);
		return (1);
	}
	*line = ft_strdup(save[fd]);
	free(save[fd]);
	if (!*line)
		return (-1);
	save[fd] = 0;
	return (0);
}

int		ft_check(char *str)
{
	int		i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_fill(char *origin, char *append, char *dest)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (origin[i] != '\0')
	{
		dest[i] = origin[i];
		i++;
	}
	while (append[y] != '\0')
	{
		dest[i] = append[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (dest);
}
