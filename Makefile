NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I. -I$(PRINTF_DIR) -I$(PRINTF_DIR)/libft

SRCS = main.c \
       stack/functions.c \
	   stack/stack_utils.c \
       parsing/parsing.c \
       parsing/helper_functions.c \
	   parsing/parsing_handle.c \
       operations/swap_moves.c \
       operations/rotate_moves.c \
       operations/reverse_rotate_moves.c \
       operations/push_moves.c \
	   algorithms/simple.c \
	   algorithms/medium.c \
	   algorithms/complex.c \
	   algorithms/sort_stack.c \
	   disorder/disorder.c \
	   benchmark/benchmark.c \
	   benchmark/benchmark_print.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME).exe
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
