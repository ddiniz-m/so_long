#include "so_long.h"

int map_lines(int fd)
{
	int i;
	static char buf[1];

	i = 0;
	while (read(fd, buf, 1) > 0)
	{
		printf("%s", buf);
		if (*buf == '\n')
			i++;
	}
	i++;
	printf("\n");
	return(i);
}

char **map(char *ber_file)
{
	int i;
	int j;
	int fd;
	char **map;
	j = 0;
	fd = open(ber_file, O_RDONLY);
	i = map_lines(fd);
	map = malloc(sizeof(char *) * (i + 1));
	fd = open(ber_file, O_RDONLY);
	printf("i = %d\n", i);
	while (j <= i)
	{
		map[j] = get_next_line(fd);
		printf("line %d : %s", j, map[j]);
		j++;
	}
	return(map);
}
