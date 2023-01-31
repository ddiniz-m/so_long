# - * - Makefile - * -

SRCS = so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c map.c\
		close_game.c put_tiles.c open_images.c put_square.c put_pixel.c\
		input.c render_frames.c player_move.c
		
OBJS = $(SRCS:%.c=%.o)
NAME = so_long.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) -I ../mlx_linux $(SRCS) -L ../mlx_linux/mlx -lmlx -lXext -lX11

run:
	@$(CC) $(CFLAGS) -I ../mlx_linux $(SRCS) -L ../mlx_linux/mlx -lmlx -lXext -lX11 && ./a.out

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean run re
