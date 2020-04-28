/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:14:20 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:14:20 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*dst;
	int		i;

	i = ft_strlen(s1);
	dst = (char*)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strcat(char *origin, char *append)
{
	int		x;
	char	*dest;

	x = ft_strlen(origin) + ft_strlen(append);
	dest = (char*)malloc(sizeof(char) * (x + 1));
	if (!dest)
	{
		free(append);
		free(origin);
		return (0);
	}
	dest = ft_fill(origin, append, dest);
	free(append);
	free(origin);
	return (dest);
}

char	*ft_strchr(char *s1, int c)
{
	int		i;
	char	*dest;

	i = 0;
	if (s1 == 0)
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
		{
			dest = ft_strdup(s1 + i + 1);
			if (!dest)
			{
				free(s1);
				return (0);
			}
			free(s1);
			return (dest);
		}
		i++;
	}
	return (0);
}

char	*ft_substr(char *save)
{
	char	*dst;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (save == 0)
		return (0);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	dst = (char*)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	while (y < i)
	{
		dst[y] = save[y];
		y++;
	}
	dst[y] = '\0';
	return (dst);
}
