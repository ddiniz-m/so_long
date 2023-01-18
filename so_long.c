#include "so_long.h"

/*int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
void	mlx_hook(t_win_list *win_ptr, int x_event, int x_mask, int (*f)(), void *param);
char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel, int *size_line,int *endian);
int		mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img, int x,int y);
int		mlx_key_hook(t_win_list *win, int (*funct)(),void *param); 
int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
void	*mlx_xpm_file_to_image(t_xvar *xvar,char *file,int *width,int *height); */


int	key_hook(int keycode, t_game *win)
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
}

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
	t_image image;
	int win_size = 640;
	int tile_size = 64;
	char *path = "/nfs/homes/ddiniz-m/Documents/so_long/sea.xpm";
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, win_size, win_size, "so_long");
	image.img = mlx_xpm_file_to_image(game.mlx, path, &tile_size, &tile_size);
	image.address = mlx_get_data_addr(image.img, &image.bits, &image.line_len,
			&image.endian);
	/* int n = 0; */
	/*while (x != win_size && y != win_size)
	{
		while(n * tile_size <= win_size)
		{
			mlx_put_image_to_game(game.mlx, game.win, image.img, x, y);
			x += tile_size;
			n++;
		}
		n = 0;
		x = 0;
		y += tile_size;
	} */
	/* put_square(&image, side, i, j); */
	mlx_put_image_to_window(game.mlx, game.win, image.img, 0, 0);
	mlx_key_hook(game.win, close_game, &game);
	mlx_key_hook(game.mlx, key_hook, &game);
	/* mlx_loop_hook(game.mlx, render_next_frame, &game); */
	mlx_loop(game.mlx);
}