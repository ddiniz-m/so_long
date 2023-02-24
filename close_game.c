/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:45:01 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/24 16:54:17 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image.sea_img);
	mlx_destroy_image(game->mlx, game->image.wall_img);
	mlx_destroy_image(game->mlx, game->image.zoro_img);
	mlx_destroy_image(game->mlx, game->image.nami_img);
	mlx_destroy_image(game->mlx, game->image.usopp_img);
	mlx_destroy_image(game->mlx, game->image.sanji_img);
	mlx_destroy_image(game->mlx, game->image.meat_img);
	mlx_destroy_image(game->mlx, game->image.luffy_img);
	mlx_destroy_image(game->mlx, game->image.exit1_img);
	mlx_destroy_image(game->mlx, game->image.exit2_img);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free(game, game->tile_map);
	free(game->mlx);
	exit (0);
	return (0);
}
