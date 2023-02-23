# - * - Makefile - * -

PRT_SRC = ft_printf/ft_printf.c  ft_printf/ft_check.c ft_printf/ft_puthexa.c\
		ft_printf/utils.c

GNL_SRC = gnl/get_next_line.c gnl/get_next_line_utils.c

LIB_SRC = libft/ft_strlen.c libft/ft_strcpy.c libft/ft_strchr.c libft/ft_strstr.c

SRCS = so_long.c map_init.c close_game.c put_tiles.c open_images.c input.c render_frames.c\
		ft_free.c  errors.c $(PRT_SRC) $(GNL_SRC) $(LIB_SRC)

OBJS = $(SRCS:%.c=%.o)
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.SILENT: $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I ../mlx_linux $(SRCS) -L ../mlx_linux/mlx -lmlx -lXext -lX11 -o $(NAME)

map1:
	@$(CC) $(CFLAGS) -I ../mlx_linux $(SRCS) -L ../mlx_linux/mlx -lmlx -lXext -lX11 -o $(NAME)
	@./so_long maps/map1.ber

map2: $(NAME)
	@./so_long maps/map2.ber

map3: $(NAME)
	@./so_long maps/map3.ber

val:
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./so_long maps/map1.ber

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean run re
