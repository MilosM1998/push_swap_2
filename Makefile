NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

GREEN   = \e[0;32m
RED     = \e[0;31m
YELLOW  = \e[0;33m
BLUE    = \e[0;34m
RESET   = \e[0m

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

OP_SRC = ./operations/swap.c ./operations/push.c ./operations/rotate.c ./operations/reverse_rotate.c
UTILS_DIR = ./utils/stack_utils.c ./utils/checker.c ./utils/errors.c ./utils/init_stack.c ./utils/stack_utils_2.c \
./utils/sort_stack.c ./utils/sorting_utils.c ./utils/push_b_to_a.c


SRC = ./src/push_swap.c $(OP_SRC) $(UTILS_DIR)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE) Compiling libft..$(RESET)"
	@echo "$(YELLOW) $(MAKE) -C $(LIBFT_DIR) $(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(BLUE) Compiling push_swap $(RESET)"
	@echo "$(YELLOW) $(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) && echo "$(GREEN) Succesfully compiled.$(RESET)"

%.o: %.c
	@echo "$(YELLOW) $(CC) $(CFLAGS) -c $< -o $@ $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@echo "$(YELLOW) Cleaning objects..$(RESET)"
	$(MAKE)	-C	$(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	@echo "$(YELLOW) Cleaning everything..$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
re: fclean all

.PHONY:
	all clean fclean re
