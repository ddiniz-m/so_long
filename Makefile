# - * - Makefile - * -

SRCS = main.c

OBJS = $(SRCS:%.c=%.o)

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
OBJ_DIR = objs

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

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

.PHONY: all clean fclean recd

#gcc -I /nfs/homes/ddiniz-m/Documents/so_long/mlx_linux main.c -L /nfs/homes/ddiniz-m/Documents/so_long/mlx_linux/mlx -lmlx -lXext -lX11