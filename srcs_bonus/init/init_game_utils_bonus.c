/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:26:32 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 13:17:33 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	set_file_colors(t_file *file, char **tab)
{
	if (!file || !tab)
		return (err_msg(0, NULL), FAILURE);
	if (!ft_strcmp(tab[0], "F"))
	{
		if (!ft_isnumber(tab[1]) || !ft_isnumber(tab[2])
			|| !ft_isnumber(tab[3]))
			return (err_msg(ERROR_INVALID_RGB, NULL), FAILURE);
		++file->f;
		file->f_rgb[0] = ft_atoi(tab[1]);
		file->f_rgb[1] = ft_atoi(tab[2]);
		file->f_rgb[2] = ft_atoi(tab[3]);
	}
	else if (!ft_strcmp(tab[0], "C"))
	{
		if (!ft_isnumber(tab[1]) || !ft_isnumber(tab[2])
			|| !ft_isnumber(tab[3]))
			return (err_msg(ERROR_INVALID_RGB, NULL), FAILURE);
		++file->c;
		file->c_rgb[0] = ft_atoi(tab[1]);
		file->c_rgb[1] = ft_atoi(tab[2]);
		file->c_rgb[2] = ft_atoi(tab[3]);
	}
	else
		return (err_msg(ERROR_INVALID_ID, NULL), FAILURE);
	return (SUCCESS);
}

int	set_textures(t_game *game, t_file *file)
{
	game->textures.f_rgb
		= (file->f_rgb[0] << 16) | (file->f_rgb[1] << 8) | file->f_rgb[2];
	game->textures.c_rgb
		= (file->c_rgb[0] << 16) | (file->c_rgb[1] << 8) | file->c_rgb[2];
	return (SUCCESS);
}
