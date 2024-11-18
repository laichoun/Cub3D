/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:38:55 by laichoun          #+#    #+#             */
/*   Updated: 2024/11/18 15:39:04 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <fcntl.h>

//copier sans les new line
int	length_file(char *file);

char	**copy_file(char *file, t_file *data_file)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_fprintf(2, "Error\nOpening file\n");
		return (NULL);
	}
	data_file->cp_file = malloc((length_file(file) + 1) * sizeof(char *));
	while (1)
	{
		data_file->cp_file[i] = get_next_line(fd);
		if (data_file->cp_file[i] == NULL)
			break;
		i ++;	
	}
	close(fd);
	data_file->cp_file[i] = NULL;
	return (data_file->cp_file);	
}

int	length_file(char *file)
{
	int		fd;
	char	*line;
	int		length;

	length = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_fprintf(2, "Error\nOpening file\n");
		return (-1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		length ++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (length);
}
/*
int	set_variable(t_file *data_file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data_file->cp_file[i])
	{
		if ()
	}
}
*/


int	main(int argc, char **argv)
{
	t_file	data_file;

	if (argc != 2)
		return(ft_fprintf(1, "Error\nWrong number of argument put a file.cub\n"), 1);
	printf("%d\n", length_file(argv[1]));
	if (!copy_file(argv[1], &data_file))
		return(1);
	int	i = 0;
	while (data_file.cp_file[i])
	{
		printf("%s", data_file.cp_file[i]);
		i ++;
	}
	ft_free_split(data_file.cp_file);
	return (0);
}
