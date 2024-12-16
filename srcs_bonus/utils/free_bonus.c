/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:56 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/06 16:19:54 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	free_bonus(t_game *game);

void	free_game(t_game *game)
{
	ft_free_split(game->map);
	mlx_destroy_image(game->mlx, game->screen);
	mlx_destroy_image(game->mlx, game->textures.img_no);
	mlx_destroy_image(game->mlx, game->textures.img_so);
	mlx_destroy_image(game->mlx, game->textures.img_ea);
	mlx_destroy_image(game->mlx, game->textures.img_we);
	free_bonus(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_file(t_file *filep)
{
	ft_free_split(filep->cp_file);
	ft_free_split(filep->map);
	free(filep->tex_no);
	free(filep->tex_so);
	free(filep->tex_we);
	free(filep->tex_ea);
}

void	free_cardinals(t_file *file)
{
	free(file->tex_no);
	free(file->tex_so);
	free(file->tex_ea);
	free(file->tex_we);
}

void	free_bonus(t_game *game)
{
	mlx_destroy_image(game->mlx, game->door);
	mlx_destroy_image(game->mlx, game->torch[0]);
	mlx_destroy_image(game->mlx, game->torch[1]);
	mlx_destroy_image(game->mlx, game->torch[2]);
	mlx_destroy_image(game->mlx, game->start[0]);
	mlx_destroy_image(game->mlx, game->start[1]);
}
