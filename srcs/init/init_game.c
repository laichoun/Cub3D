/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:26:22 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 11:27:26 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		init_game_data(t_game *gamep, t_file *file);
int		check_extension(char *filename, char *ext);
int		set_textures(t_game *game, t_file *file);
void	init_blank_game(t_game *gamp);
int		set_file_colors(t_file *file, char **tab);

int	init_game(t_game *gamep, char *filename)
{
	t_file	file;

	if (check_extension(filename, "cub"))
		return (FAILURE);
	if (init_file(&file))
		return (FAILURE);
	if (copy_file(filename, &file))
		return (free_file(&file), FAILURE);
	if (set_variable(&file))
		return (free_file(&file), FAILURE);
	if (check_file(&file))
		return (free_file(&file), FAILURE);
	if (init_game_data(gamep, &file))
		return (free_file(&file), FAILURE);
	return (free_file(&file), SUCCESS);
}

int	check_setvar(t_file *file, int i)
{
	char	**tab;
	int		size;

	tab = ft_strtok(file->cp_file[i], " ,\n");
	if (!tab)
		return (err_msg(ERROR_MALLOC, NULL), FAILURE);
	size = ft_split_size(tab);
	if (size == 0)
	{
		ft_free_split(tab);
		return (-10);
	}
	if (size != 2 && size != 4)
		return (ft_free_split(tab), err_msg(ERROR_MISSING_INFO, 0),
			FAILURE);
	if (size == 2)
		if (set_cardinal_points(file, tab))
			return (ft_free_split(tab), FAILURE);
	if (size == 4)
		if (set_file_colors(file, tab))
			return (ft_free_split(tab), FAILURE);
	ft_free_split(tab);
	return (SUCCESS);
}

int	set_variable(t_file *file)
{
	int		i;
	int		check;
	int		count;

	i = -1;
	count = 0;
	while (file->cp_file[++i])
	{
		check = check_setvar(file, i);
		if (check == -10)
			continue ;
		else if (check)
			return (FAILURE);
		if (++count == 6)
			break ;
	}
	if (count != 6)
		return (err_msg(ERROR_MISSING_INFO, NULL), FAILURE);
	file->map_ind = i + 1;
	if (init_map(file))
		return (FAILURE);
	return (SUCCESS);
}

int	init_game_data(t_game *gamep, t_file *file)
{
	init_blank_game(gamep);
	if (!file)
		return (FAILURE);
	gamep->map = ft_dupsplit(file->map);
	gamep->row = file->width;
	gamep->col = file->height;
	init_raycast(gamep, file);
	set_player_dir(gamep, file);
	set_textures(gamep, file);
	if (init_mlx(gamep, file))
		return (free_game(gamep), FAILURE);
	return (SUCCESS);
}
