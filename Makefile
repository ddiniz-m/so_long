# - * - Makefile - * -

SRCS = so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c map.c\
		close_game.c put_tiles.c open_images.c input.c render_frames.c\
		player_move.c
		
OBJS = $(SRCS:%.c=%.o)
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) -g -I ../mlx_linux $(SRCS) -L ../mlx_linux/mlx -lmlx -lXext -lX11 -o $(NAME)

map1:
	@$(CC) $(CFLAGS) -g -I ../mlx_linux $(SRCS) -L ../mlx_linux/mlx -lmlx -lXext -lX11 -o $(NAME) && ./so_long maps/map1.ber

map2:
	@$(CC) $(CFLAGS) -g -I ../mlx_linux $(SRCS) -L ../mlx_linux/mlx -lmlx -lXext -lX11 -o $(NAME) && ./so_long maps/map2.ber

map3:
	@$(CC) $(CFLAGS) -g -I ../mlx_linux $(SRCS) -L ../mlx_linux/mlx -lmlx -lXext -lX11 -o $(NAME) && ./so_long maps/map3.ber

val:
	@$(CC) $(CFLAGS) -g -I ../mlx_linux $(SRCS) -L ../mlx_linux/mlx -lmlx -lXext -lX11 -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map2.ber

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean run re
