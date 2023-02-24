/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:37:55 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/24 18:37:09 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_images(t_game *game)
{
	int	size;

	size = TILE_SIZE;
	game->image.sea_img = mlx_xpm_file_to_image(game->mlx, PATH_SEA, &size,
			&size);
	game->image.wall_img = mlx_xpm_file_to_image(game->mlx, PATH_WALL, &size,
			&size);
	game->image.zoro_img = mlx_xpm_file_to_image(game->mlx, PATH_ZORO, &size,
			&size);
	game->image.nami_img = mlx_xpm_file_to_image(game->mlx, PATH_NAMI, &size,
			&size);
	game->image.usopp_img = mlx_xpm_file_to_image(game->mlx, PATH_USOPP, &size,
			&size);
	game->image.sanji_img = mlx_xpm_file_to_image(game->mlx, PATH_SANJI, &size,
			&size);
	game->image.meat_img = mlx_xpm_file_to_image(game->mlx, PATH_MEAT, &size,
			&size);
	game->image.luffy_img = mlx_xpm_file_to_image(game->mlx, PATH_LUFFY, &size,
			&size);
	game->image.exit1_img = mlx_xpm_file_to_image(game->mlx, PATH_EXIT1, &size,
			&size);
	game->image.exit2_img = mlx_xpm_file_to_image(game->mlx, PATH_EXIT2, &size,
			&size);
	return (0);
}
