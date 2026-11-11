NAME = libftprintf.a

LIBFTNAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O0
LIBFTDIR = ./libft

SRCS = ft_printf.c print_pointer.c print_str.c print_digit.c print_char.c print_hex.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)
	@ar -x $(LIBFTDIR)/$(LIBFTNAME)
	@ar rcs $(NAME) $(OBJS) *.o
	@rm -f *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
