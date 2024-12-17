NAME := push_swap
BONUS_NAME := checker
.DEFAULT_GOAL := all
CC := cc
RM := rm -rf

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

# OBJ_DIR := _obj
# INC_DIRS := . libft
# SRC_DIRS := . 
# BONUS_DIR := checker_bonus/_obj_bonus
OBJ_DIR := _obj
BONUS_DIR := checker_bonus/_obj_bonus
INC_DIRS := . libft checker_bonus
SRC_DIRS := . checker_bonus

# Tell the Makefile where headers and source files are
vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

SRCS := 		move_calculation.c find_target_pos.c \
				push_swap_sort.c sort_helpers.c validate_args.c \
				sorting_algorithm.c stack_operations.c stack_rotate_reverse.c \
				stack_rotate_simple.c stack_utils.c \
				copy_and_sort_values.c initialize_stacks.c parsing.c \
				perform_rotations.c final_rotate_sort.c swap.c push_to_b.c
MAIN_SRCS :=	push_swap_main.c

BONUS_MAIN_SRCS := 	checker_bonus/cps_main.c
BONUS_SRCS := 		checker_bonus/cps_convert_args.c checker_bonus/cps_parse_validate.c \
					checker_bonus/cps_initialize.c checker_bonus/cps_operations.c \
					checker_bonus/cps_helpers.c checker_bonus/cps_sort_assign_indices.c \
					checker_bonus/assign_indices.c
    					

# BONUS_SRCS := 	cps_convert_args.c cps_helpers.c cps_initialize.c \
# 				cps_main.c cps_operations.c cps_parse_validate.c \
# 				cps_sort_assign_indices.c 

################################################################################
###############                  OBJECT FILES                     ##############
################################################################################

# Common object files used by both main and bonus
COMMON_OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# Main program object files
MAIN_OBJS := $(addprefix $(OBJ_DIR)/, $(MAIN_SRCS:%.c=%.o))

# Bonus program object files
BONUS_OBJS := $(addprefix $(BONUS_DIR)/, $(notdir $(BONUS_SRCS:%.c=%.o) $(BONUS_MAIN_SRCS:%.c=%.o)))

LIBFT := libft/libft.a


# OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o) $(MAIN_SRCS:%.c=%.o))
# # BONUS_OBJS := $(addprefix $(BONUS_DIR)/, $(SRCS:%.c=%.o) $(BONUS_SRCS:%.c=%.o) $(BONUS_MAIN_SRCS:%.c=%.o))
# BONUS_OBJS := $(addprefix $(BONUS_DIR)/, $(notdir $(SRCS:%.c=%.o) $(BONUS_SRCS:%.c=%.o) $(BONUS_MAIN_SRCS:%.c=%.o)))
# # GNL_OBJS := $(addprefix $(OBJ_DIR)/, $(GNL_SRCS:%.c=%.o))
# # GC_OBJS := $(addprefix $(OBJ_DIR)/, $(GC_SRCS:%.c=%.o))

# LIBFT := libft/libft.a

################################################################################
########                         COMPILING                      ################
################################################################################

# CFLAGS := -Wall -Wextra -Werror -g -MMD -MP -I$(INC_DIRS)
CFLAGS := -Wall -Wextra -Werror -g -MMD -MP $(addprefix -I, $(INC_DIRS))
LDFLAGS := -Llibft -lft
#ARFLAGS := -rcs

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) $(COMMON_OBJS) $(MAIN_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(MAIN_OBJS) $(LDFLAGS) -o $(NAME)

bonus: $(LIBFT) $(BONUS_DIR) $(COMMON_OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_OBJS) $(LDFLAGS) -o $(BONUS_NAME)


$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)/%.o: checker_bonus/%.c | $(BONUS_DIR)
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

re: fclean all

$(LIBFT):
	make -C libft


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

.PHONY: all bonus clean fclean re help