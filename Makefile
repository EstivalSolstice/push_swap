NAME := push_swap
BONUS_NAME := checker
.DEFAULT_GOAL := all
CC := cc
RM := rm -rf

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR := _obj
INC_DIRS := . libft
SRC_DIRS := . 
BONUS_DIR := checker_bonus/_obj_bonus

# Tell the Makefile where headers and source files are
vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

SRCS := 		helper_functions.c move_calculation.c find_target_pos.c \
				push_swap_sort.c sort_helpers.c validate_args.c \
				sorting_algorithm.c stack_operations.c stack_rotate_reverse.c \
				stack_rotate_simple.c stack_utils.c assign_indices.c \
				copy_and_sort_values.c initialize_stacks.c parsing.c \
				perform_rotations.c final_rotate_sort.c swap.c
MAIN_SRCS :=	push_swap_main.c

BONUS_MAIN_SRCS := 	cps_main.c
BONUS_SRCS := 		cps_convert_args.c cps_parse_validate.c cps_initialize.c \
    					cps_operations.c cps_helpers.c cps_sort_assign_indices.c
    					

# BONUS_SRCS := 	cps_convert_args.c cps_helpers.c cps_initialize.c \
# 				cps_main.c cps_operations.c cps_parse_validate.c \
# 				cps_sort_assign_indices.c 

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o) $(MAIN_SRCS:%.c=%.o))
BONUS_OBJS := $(addprefix $(BONUS_DIR)/, $(SRCS:%.c=%.o) $(BONUS_SRCS:%.c=%.o) $(BONUS_MAIN_SRCS:%.c=%.o))
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

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LDFLAGS) -o $(BONUS_NAME)


$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)/%.o: %.c | $(BONUS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS_DIR):
	mkdir -p $(BONUS_DIR)

clean:
	$(RM) $(OBJ_DIR) $(BONUS_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(RM) libft/_obj libft/libft.a

re: fclean submodule_update all

$(LIBFT):
	make -C libft

submodule_update:
	git submodule update --remote --merge

re_submodule: submodule_rebuild

submodule_rebuild:
	git submodule deinit -f .
	git submodule update --init --recursive

help:
	@echo "Makefile for $(NAME)"
	@echo "Usage:"
	@echo "	make						Build the project"
	@echo "	make bonus					Build the project with bonus functions"
	@echo "	make clean					Remove object files in the main project"
	@echo "	make fclean					Remove all build files, including libft's objects"
	@echo "	make re						Clean and rebuild the project"
	@echo "	make submodule_update				Update all submodules to the latest commit"
	@echo "	make re_submodule				Fully reset and update submodules"
	@echo "	make submodule_rebuild				Reinitialize submodules from scratch"
	@echo "	make help					Display this help message"

-include $(OBJS:%.o=%.d)
# -include $(BONUS_OBJS:%.o=%.d)
# -include $(GNL_OBJS:%.o=%.d)

.PHONY: all bonus clean fclean re submodule_update re_submodule submodule_rebuild help