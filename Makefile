CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push.c reverse_rotate.c swap.c push_swap.c rotate.c sort_chunks.c linked_list.c helper.c parse_input.c split.c filling_stack.c
NAME = push_swap
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean clean all re