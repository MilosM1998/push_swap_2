NAME = push_swap
CC = -cc 
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft/
SRCS = push_swap.c
OBJS = ${SRCS:.c=.o}
RM = -rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) $(LIBFT_DIR) -C
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)libft.a -o $(NAME)

clean: 
	$(MAKE) $(LIBFT_DIR) fclean
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
.PHONY: all clean fclean re
 