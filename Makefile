NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror 
SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re: all

.PHONY: all fclean clean re