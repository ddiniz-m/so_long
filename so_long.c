#include "so_long.h"

/*int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
void	mlx_hook(t_win_list *win_ptr, int x_event, int x_mask, int (*f)(), void *param);
char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel, int *size_line,int *endian);
int		mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img, int x,int y);
int		mlx_key_hook(t_win_list *win, int (*funct)(),void *param); 
int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
void	*mlx_xpm_file_to_image(t_xvar *xvar,char *file,int *width,int *height); */


/* int	key_hook(int keycode, t_game *win)
{
	t_game game;
	t_image image;
	int x = 0;
	int y = 0;
	if (keycode == 114)
		mlx_clear_window(game.mlx, game.win);
	if (keycode == 115)
	{
		y += 64;
		mlx_put_image_to_window(game.mlx, game.win, image.img, x, y);
	}
	(void)win;
	return(0);
} */

/* int render_next_frame(void *my_struct)
{
	t_game game;
	mlx_key_hook(game.mlx, key_hook, &game);
	(void)my_struct;
	return(0);
} */

int	main(void)
{
	t_game game;
	/* t_image image; */
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	char **tile_map;
	int tile_size = 64;
	int win_sizex = 832;
	int win_sizey = 320;
	char *path_sea = "sprites/sea.xpm";
	char *path_land = "sprites/land.xpm";

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, win_sizex, win_sizey, "so_long");
	tile_map = map("test.ber");
/* 	image.img = mlx_xpm_file_to_image(game.mlx, path_sea, &win_sizex, &win_sizey);
	image.address = mlx_get_data_addr(image.img, &image.bits, &image.line_len,
			&image.endian); */
	/* mlx_put_image_to_window(game.mlx, game.win, image.img, 0, 0); */
	game.tile_img.sea_img = mlx_xpm_file_to_image(game.mlx, path_sea, &tile_size, &tile_size);
	game.tile_img.land_img = mlx_xpm_file_to_image(game.mlx, path_land, &tile_size, &tile_size);
	while((y <= win_sizey - tile_size))
	{
		while(i * tile_size <= win_sizex)
		{
			if(tile_map[j][i] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.tile_img.land_img, x, y);
			else if (tile_map[j][i] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.tile_img.sea_img, x, y);
			x += tile_size;
			i++;
		}
		x = 0;
		i = 0;
		j++;
		y += tile_size;
	}
	printf("i = %d\n", i);
	printf("j = %d\n", j);
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	mlx_key_hook(game.win, close_game, &game);
	mlx_loop(game.mlx);
	/* 	mlx_key_hook(game.mlx, key_hook, &game); */
	/* mlx_loop_hook(game.mlx, render_next_frame, &game); */
}