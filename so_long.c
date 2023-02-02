#include "so_long.h"

/*int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
void	mlx_hook(t_win_list *win_ptr, int x_event, int x_mask, int (*f)(), void *param);
char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel, int *size_line,int *endian);
int		mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img, int x,int y);
int		mlx_key_hook(t_win_list *win, int (*funct)(),void *param); 
int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
void	*mlx_xpm_file_to_image(t_xvar *xvar,char *file,int *width,int *height); */

int	main(void)
{
	t_game game;
	if (errors(&game) < 0)
		return(0);
	
	int win_sizex = 512;
	int win_sizey = 320;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, win_sizex, win_sizey, "so_long");

/* 	game.image.img = mlx_new_image(game.mlx, win_sizex, win_sizey);
	game.image.address = mlx_get_data_addr(game.image.img, &game.image.bits, &game.image.line_len, &game.image.endian); */
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0 ,input, &game);
	mlx_loop_hook(game.mlx, render_frames, &game);

	mlx_loop(game.mlx);
}

	/* mlx_put_image_to_window(game.mlx, game.win, image.img, 0, 0); */
	/* 	mlx_key_hook(game.mlx, key_hook, &game); */
	/* mlx_loop_hook(game.mlx, render_next_frame, &game); */