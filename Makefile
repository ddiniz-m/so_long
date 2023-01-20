# - * - Makefile - * -

SRCS = 
OBJS = $(SRCS:%.c=%.o)
NAME = so_long.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) -I ./mlx_linux $(SRCS) -L ./mlx_linux/mlx -lmlx -lXext -lX11
	@$(MAKE) -C mlx_linux
	@$(MAKE) -C libft

run:
	@$(CC) $(CFLAGS) -I ./mlx_linux $(SRCS) -L ./mlx_linux/mlx -lmlx -lXext -lX11 && ./a.out

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C libft clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean $(NAME)
	@$(MAKE) -C libft re

.PHONY: all clean fclean run re
