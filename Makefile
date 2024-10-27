NAME := push_swap
.DEFAULT_GOAL := all
CC := cc
RM := rm -rf

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR := _obj
INC_DIRS := . libft
SRC_DIRS := . 

# Tell the Makefile where headers and source files are
vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

SRCS := helper_functions.c main.c move_calculation.c \
		push_swap_main.c push_swap_sort.c sort_helpers.c \
		sorting_algorithm.c stack_operations.c stack_rotations_1.c \
		stack_rotations_2.c stack_utils.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
# BONUS_OBJS := $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:%.c=%.o))
# GNL_OBJS := $(addprefix $(OBJ_DIR)/, $(GNL_SRCS:%.c=%.o))
# GC_OBJS := $(addprefix $(OBJ_DIR)/, $(GC_SRCS:%.c=%.o))

LIBFT := libft/libft.a

################################################################################
########                         COMPILING                      ################
################################################################################

# CFLAGS := -Wall -Wextra -Werror -g -MMD -MP -I$(INC_DIRS)
CFLAGS := -Wall -Wextra -Werror -g -MMD -MP $(addprefix -I, $(INC_DIRS))
LDFLAGS := -Llibft -lft
#ARFLAGS := -rcs

all: $(LIBFT) $(NAME)

# Linking push_swap executable with libft
$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# Rule to compile .o files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the directories exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean submodule_update all

$(LIBFT):
	make -C libft

submodule_update:
	git submodule update --remote --merge

re_sub: submodule_rebuild

submodule_rebuild:
	git submodule deinit -f .
	git submodule update --init --recursive

-include $(OBJS:%.o=%.d)
# -include $(BONUS_OBJS:%.o=%.d)
# -include $(GNL_OBJS:%.o=%.d)

.PHONY: all clean fclean re re_sub submodule_rebuild