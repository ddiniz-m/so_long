/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:25:06 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/24 16:53:48 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// puts different collectible imgages depending on the number
// of collectibles that there are
void	collect_img(int a, int b, t_game *game)
{
	static int	i;

	if (b == (a - game->collect_og) + 1)
		mlx_put_image_to_window(game->mlx, game->win, game->image.zoro_img,
			game->tile.x, game->tile.y);
	if (b == (a - game->collect_og) + 2)
		mlx_put_image_to_window(game->mlx, game->win, game->image.nami_img,
			game->tile.x, game->tile.y);
	if (b == (a - game->collect_og) + 3)
		mlx_put_image_to_window(game->mlx, game->win, game->image.usopp_img,
			game->tile.x, game->tile.y);
	if (b == (a - game->collect_og) + 4)
		mlx_put_image_to_window(game->mlx, game->win, game->image.sanji_img,
			game->tile.x, game->tile.y);
	if (i == 0)
		i = 5;
	if (b == (a - game->collect_og) + i)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->image.meat_img,
			game->tile.x, game->tile.y);
		i++;
	}
}

// changes collectibles to empty(Sea) when player reaches tile
void	collectible_tile(t_game *game)
{
	static int	b = 0;
	static int	a = 0;

	if (b == a)
		a += game->collect_og;
	if (b != a)
		b++;
	if (game->tile.x != game->player.x || game->tile.y != game->player.y)
		collect_img(a, b, game);
	if (game->tile.x == game->player.x && game->tile.y == game->player.y)
	{
		game->tile_map[game->tile.y / 64][game->tile.x / 64] = '0';
		a -= game->collect_og;
		game->collect++;
	}
}

void	exit_tile(t_game *game)
{
	if (game->collect == game->collect_og)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->image.exit2_img,
			game->tile.x, game->tile.y);
		if (game->tile.x == game->player.x && game->tile.y == game->player.y)
			close_game(game);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->image.exit1_img,
			game->tile.x, game->tile.y);
}

int	image_to_window(char tile, t_game *game)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->image.wall_img,
			game->tile.x, game->tile.y);
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image.sea_img,
			game->tile.x, game->tile.y);
	if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->image.sea_img,
			game->tile.x, game->tile.y);
	if (tile == 'C')
		collectible_tile(game);
	if (tile == 'E')
		exit_tile(game);
	return (0);
}

void	put_tiles(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->tile.y = 0;
	while ((game->tile.y <= game->win_size_y - TILE_SIZE))
	{
		game->tile.x = 0;
		while (i * TILE_SIZE <= game->win_size_x)
		{
			image_to_window(map[j][i], game);
			game->tile.x += TILE_SIZE;
			i++;
		}
		i = 0;
		j++;
		game->tile.y += TILE_SIZE;
	}
}
