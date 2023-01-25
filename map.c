/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:52:04 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/01/25 18:02:46 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines(int fd)
{
	int		i;
	int		j;
	int		k;
	static char buf[1];

	i = 1;
	j = 0;
	k = 0;
	while (read(fd, buf, 1) > 0)
	{
		if (*buf == '\n')
			i++;
		if (*buf == 'P' || *buf == 'E')
			j++;
		if (*buf == 'C')
			k++;
		if (*buf != '0' && *buf != '1' && *buf != 'P' && *buf != 'C' && *buf != 'E' 
			&& *buf != '\n')
			return (-1);
	}
	if (j != 2 || k <= 0)
		return (-1);
	return (i);
}

char	**map(t_game *game, char *ber_file)
{
	int		i;
	int		j;
	int		fd;

	j = 0;
	fd = open(ber_file, O_RDONLY);
	i = map_lines(fd);
	if (i < 0)
		return (NULL);
	game->tile_map = malloc(sizeof(char *) * (i + 1));
	fd = open(ber_file, O_RDONLY);
	while (j <= i)
	{
		game->tile_map[j] = get_next_line(fd);
		j++;
	}
	return (game->tile_map);
}

int	check_rect_wall(char **map)
{
	int	x;
	int	y;
	int	line;
	int	col;

	x = 0;
	y = 0;
	while (map[0][x] == '1')
		x++;
	while (map[y] && map[y][0] == '1')
		y++;
	line = x;
	col = y;
	x = 0;
	y = 0;
	while (map[col - 1][x] == '1')
		x++;
	while (map[y] && map[y][line - 1] == '1')
		y++;
	if (x != line || y != col)
	{
		printf("Error\nMap not rectangular or not surrounded by walls\n");
		return (-1);
	}
	return (line * col);
}
