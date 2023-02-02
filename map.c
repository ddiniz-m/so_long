/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:52:04 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/02 15:29:16 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines(int fd, t_game *game)
{
	int			j;
	int			k;
	static char	buf[1];

	j = 0;
	k = 0;
	game->map_y = 1;
	while (read(fd, buf, 1) > 0)
	{
		if (*buf == '\n')
			game->map_y++;
		if (*buf == 'P' || *buf == 'E')
			j++;
		if (*buf == 'C')
			k++;
		if (*buf != '0' && *buf != '1' && *buf != 'P' && *buf != 'C'
			&& *buf != 'E' && *buf != '\n')
			return (-1);
	}
	if (j != 2 || k <= 0)
		return (-1);
	return (game->map_y);
}

int	map(t_game *game, char *ber_file)
{
	int	j;
	int	i;
	int	fd;
	char **buff;
	buff = NULL;
	
	j = 0;
	fd = open(ber_file, O_RDONLY);
	i = map_lines(fd, game);
	if (i < 0)
		return (1);
	buff = malloc(sizeof(char *) * (i + 1));
	if (!buff)
		return (2);
	fd = open(ber_file, O_RDONLY);
	while (j <= i)
	{
		buff[j] = get_next_line(fd);
		j++;
	}
	game->tile_map = buff;
	return (0);
}

int	check_rect_wall(t_game *game, char **map)
{
	int	line;
	int	col;

	game->map_y = 0;
	game->map_x = 0;
	while (map[0][game->map_y] == '1')
		game->map_y++;
	while (map[game->map_x] && map[game->map_x][0] == '1')
		game->map_x++;
	line = game->map_y;
	col = game->map_x;
	game->map_y = 0;
	game->map_x = 0;
	while (map[col - 1][game->map_y] == '1')
		game->map_y++;
	while (map[game->map_x] && map[game->map_x][line - 1] == '1')
		game->map_x++;
	if (game->map_y != line || game->map_x != col)
		return (-1);
	return (1);
}

int	errors(t_game *game)
{
	char	*ber_file;
	int		i;

	ber_file = "test.ber";
	i = map(game, ber_file);
	if (i == 1)
	{
		printf("Error\nMap doesn't contain the correct components\n");
		return (-1);
	}
	if (i == 2)
	{
		printf("Error\nMap memory allocation error\n");
		return (-1);
	}
	if (check_rect_wall(game, game->tile_map) < 0)
	{
		printf("Error\nMap not rectangular or not surrounded by walls\n");
		return (-1);
	}
	return (0);
}