/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:15:48 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:15:48 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		ft_check(char *str);
char	*ft_fill(char *origin, char *append, char *dest);
char	*ft_read(char **save, int fd, ssize_t ret);
char	*ft_substr(char *temp);
char	*ft_strchr(char *s1, int c);
char	*ft_strcat(char *origin, char *append);
int		ft_strlen(char *s);
int		ft_makeline(char **save, char **line, int fd);
char	*ft_strdup(char *s1);

#endif
