/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:27:57 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/18 17:02:34 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	init_mlx(t_game *game, t_file *file)
{
	int	w;
	int	h;

	game->textures.img_no = mlx_xpm_file_to_image(game->mlx, file->tex_no, &w,
			&h);
	game->textures.img_so = mlx_xpm_file_to_image(game->mlx, file->tex_so, &w,
			&h);
	game->textures.img_we = mlx_xpm_file_to_image(game->mlx, file->tex_we, &w,
			&h);
	game->textures.img_ea = mlx_xpm_file_to_image(game->mlx, file->tex_ea, &w,
			&h);
	return (SUCCESS);
}
