#include "so_long.h"

void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*pixel;
	int		correct;

	correct = (y * image->line_len) + (x * (image->bits / 8));
	pixel = image->address + correct;
	*(unsigned int *)pixel = color;
}
