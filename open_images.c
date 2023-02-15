/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:37:55 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/15 18:40:08 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_images(t_game *game)
{
	int	size;

	size = TILE_SIZE;
	game->image.sea_img = mlx_xpm_file_to_image(game->mlx, PATH_SEA, &size,
			&size);
	game->image.land_img = mlx_xpm_file_to_image(game->mlx, PATH_LAND, &size,
			&size);
	game->image.collect1_img = mlx_xpm_file_to_image(game->mlx, PATH_COLLECT1,
			&size, &size);
	game->image.collect2_img = mlx_xpm_file_to_image(game->mlx, PATH_COLLECT2,
			&size, &size);
	game->image.collect3_img = mlx_xpm_file_to_image(game->mlx, PATH_COLLECT3,
			&size, &size);
	game->image.collect4_img = mlx_xpm_file_to_image(game->mlx, PATH_COLLECT4,
			&size, &size);
	game->image.collect5_img = mlx_xpm_file_to_image(game->mlx, PATH_COLLECT5,
			&size, &size);
	game->image.player_img = mlx_xpm_file_to_image(game->mlx, PATH_PLAYER,
			&size, &size);
	game->image.exit1_img = mlx_xpm_file_to_image(game->mlx, PATH_EXIT1, &size,
			&size);
	game->image.exit2_img = mlx_xpm_file_to_image(game->mlx, PATH_EXIT2, &size,
			&size);
	return (0);
}
