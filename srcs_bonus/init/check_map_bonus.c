/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:26:49 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/06 18:26:57 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	check_components(t_file *file);
int	is_map_valid(t_file *file);
int	is_valid_row(t_file *file);
int	is_valid_col(t_file *file);
int	check_player(t_file *file);

int	is_map_valid(t_file *file)
{
	if ((check_components(file) == SUCCESS && is_valid_row(file) == SUCCESS
			&& is_valid_col(file) == SUCCESS && check_player(file) == SUCCESS))
		return (SUCCESS);
	return (FAILURE);
}

int	check_components(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->height)
	{
		j = 0;
		while (j < file->width)
		{
			if (file->map[i][j] != 'N' && file->map[i][j] != 'S'
				&& file->map[i][j] != 'W' && file->map[i][j] != 'E'
				&& file->map[i][j] != '1' && file->map[i][j] != '0'
				&& file->map[i][j] != 'D' && file->map[i][j] != 'O'
				&& file->map[i][j] != ' ' && file->map[i][j] != 'L'
				&& file->map[i][j] != 'B')
				return (err_msg(ERROR_CHAR, NULL), FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_player(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->height)
	{
		j = 0;
		while (j < file->width)
		{
			if (file->map[i][j] == 'N' || file->map[i][j] == 'S'
				|| file->map[i][j] == 'W' || file->map[i][j] == 'E')
			{
				file->player++;
				file->player_x = j;
				file->player_y = i;
				file->dir = file->map[i][j];
			}
			j++;
		}
		i++;
	}
	if (file->player != 1)
		return (err_msg(ERROR_PLAYER, NULL), FAILURE);
	return (SUCCESS);
}

int	is_valid_row(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->height)
	{
		j = 0;
		while (j < file->width)
		{
			while (j < file->width && file->map[i][j] == 32)
				j++;
			if (j < file->width && file->map[i][j] != '1')
				return (err_msg(ERROR_NOT_SURROUNDED, NULL), FAILURE);
			while (j < file->width && file->map[i][j] != 32)
				j++;
			if (file->map[i][j - 1] != '1' && file->map[i][j - 1] != ' ')
				return (err_msg(ERROR_NOT_SURROUNDED, NULL), FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	is_valid_col(t_file *file)
{
	int	i;
	int	j;

	j = 1;
	while (j < file->width)
	{
		i = 0;
		while (i < file->height)
		{
			while (i < file->height && file->map[i][j] == 32)
				i++;
			if (i < file->height && file->map[i][j] != '1')
				return (err_msg(ERROR_NOT_SURROUNDED, NULL), FAILURE);
			while (i < file->height && file->map[i][j] != 32)
				i++;
			if (file->map[i - 1][j] != '1' && file->map[i - 1][j] != ' ')
				return (err_msg(ERROR_NOT_SURROUNDED, NULL), FAILURE);
			i++;
		}
		j++;
	}
	return (SUCCESS);
}
