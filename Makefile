NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Iincludes

SRCS_DIR = srcs

SRCS = $(SRCS_DIR)/main.c \
       $(SRCS_DIR)/error_handling.c \
       $(SRCS_DIR)/init_stack.c \
       $(SRCS_DIR)/input_check.c \
       $(SRCS_DIR)/large_sort.c \
       $(SRCS_DIR)/node_operations.c \
       $(SRCS_DIR)/parse_elements.c \
       $(SRCS_DIR)/push_cost_1.c \
       $(SRCS_DIR)/push_cost_2.c \
       $(SRCS_DIR)/push_operations.c \
       $(SRCS_DIR)/reverse_rotate_operations.c \
       $(SRCS_DIR)/rotate_operations.c \
       $(SRCS_DIR)/small_sort.c \
       $(SRCS_DIR)/split_functions.c \
       $(SRCS_DIR)/stack_operations.c \
       $(SRCS_DIR)/swap_operations.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lm -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run