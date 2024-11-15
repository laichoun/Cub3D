/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:43:12 by pibernar          #+#    #+#             */
/*   Updated: 2024/04/10 12:17:53 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strconcat(char *str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = 0;
	}
	new_str = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1));
	if (!new_str)
		return (free(str), NULL);
	i = -1;
	j = 0;
	while (str[++i])
		new_str[i] = str[i];
	while (buf[j])
		new_str[i++] = buf[j++];
	new_str[i] = 0;
	return (free(str), new_str);
}

char	*ft_get_left_side(char *current_line)
{
	char	*left_side;
	int		i;

	i = 0;
	if (current_line[i] == 0)
		return (0);
	while (current_line[i] && current_line[i] != '\n')
		i++;
	left_side = malloc(sizeof(char) * (i + 2));
	if (!left_side)
		return (NULL);
	i = 0;
	while (current_line[i] != '\n' && current_line[i])
	{
		left_side[i] = current_line[i];
		i++;
	}
	if (current_line[i] == '\n')
		left_side[i++] = '\n';
	left_side[i] = 0;
	return (left_side);
}

void	set_remainder(char *remainder, char *str)
{
	int	i;
	int	shift;

	i = 0;
	shift = 0;
	remainder[i] = '\0';
	while (str[shift] && str[shift] != '\n')
		shift++;
	if (str[shift] == '\0')
		return ;
	shift++;
	while (str[shift])
		remainder[i++] = str[shift++];
	remainder[i] = '\0';
}

char	*ft_get_line(int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	buf[0] = 0;
	while (ft_strchr(buf, '\n') == 0 && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(str), NULL);
		buf[bytes_read] = 0;
		str = strconcat(str, buf);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_strdup(remainder);
	if (!str)
		return (NULL);
	str = ft_get_line(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_left_side(str);
	set_remainder(remainder, str);
	free(str);
	return (line);
}
