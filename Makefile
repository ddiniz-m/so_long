# - * - Makefile - * -

SRCS = main.c put_pixel.c put_square.c close_game.c

OBJS = $(SRCS:%.c=%.o)

NAME = so_long.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@$(MAKE) -C mlx_linux
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) -I /nfs/homes/ddiniz-m/Documents/so_long/mlx_linux main.c -L /nfs/homes/ddiniz-m/Documents/so_long/mlx_linux/mlx -lmlx -lXext -lX11

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@$(MAKE) -C libft clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean $(NAME)
	@$(MAKE) -C libft re

.PHONY: all clean fclean re
