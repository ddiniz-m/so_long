#include "so_long.h"

int map_lines(int fd)
{
	int i;
	static char buf[2];

	i = 0;
	while ()
	{
		read(fd, buf, 1);
		printf("%s", buf);
		if (*buf == '\n')
			i++;
	}
	printf("\ni = %d\n", i);
	return(i);
}

char **map(int j)
{
	int i;
	int fd;
	char **map;

	fd = open("test.ber", O_RDONLY);
	i = map_lines(fd);
	map = malloc(sizeof(char *) * (i + 1));
	while (j <= i)
	{
		map[j] = get_next_line(fd);
		j++;
		printf("line %d : %s\n", j, map[j]);
	}
	return(map);
}

int main()
{
	char **test;
	test = map(0);
	(void) test;
	return(0);
}