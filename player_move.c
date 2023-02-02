/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:43:43 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/02 13:36:29 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.player_img,
				game->player.x, game->player.y);
	return (0);
}