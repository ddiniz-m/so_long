# -*- MakeFile -*-

SRCS = ft_printf.c ft_check.c ft_putchar.c ft_putstr.c ft_putnbr.c\
	ft_puthexa.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@$(MAKE) -C libft

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean $(NAME)
	$(MAKE) -C libft re

.PHONY: all clean fclean recd 