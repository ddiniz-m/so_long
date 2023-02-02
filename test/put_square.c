#include "so_long.h"

void	put_square(t_image *image, int side, int startx, int starty)
{
	int x;
	int y;

	x = startx;
	y = starty;
	while (x <= startx + side)
	{
		put_pixel(image, x++, starty, 0xFFFFFF);
		put_pixel(image, startx, y++, 0xFFFFFF);
	}
	x = startx;
	y = starty;
	while (x <= startx + side)
	{
		put_pixel(image, x++, side + starty, 0xFFFFFF);
		put_pixel(image, side + startx, y++, 0xFFFFFF);
	}
}