NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard ft_*.c)
OBJ = $(SRC:.c=.o)
HEADER = libft.h

PUSH_SWAP := push_swap

PUSH_SWAP_SRCS = push_swap.c
#CHECKER_SRCS = push_swap_checker.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
#CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME) $(PUSH_SWAP) $(CHECKER)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Compiled $(NAME)"

$(PUSH_SWAP): $(PUSH_SWAP_OBJS) $(NAME)
	@$(CC) $(CFLAGS) -g -o $(PUSH_SWAP) $(PUSH_SWAP_OBJS) $(NAME)
	@rm -f $(OBJ) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	@echo "Compiled $(PUSH_SWAP)"

$(CHECKER): $(CHECKER_OBJS) $(NAME)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS) $(NAME)
	@rm -f $(OBJ) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	@echo "Compiled $(CHECKER)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	@echo "Cleaned object files"

fclean: clean
	@rm -f $(NAME) $(PUSH_SWAP) $(CHECKER)
	@echo "Removed $(NAME), $(PUSH_SWAP), and $(CHECKER)"

re: fclean all

.PHONY: all clean fclean re
