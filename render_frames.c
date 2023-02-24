/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:37:13 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/24 16:53:53 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.luffy_img,
		game->player.x, game->player.y);
	return (0);
}

int	render_frames(t_game *game)
{
	put_tiles(game->tile_map, game);
	player_move(game);
	return (0);
}
