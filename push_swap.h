/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:27:36 by joltmann          #+#    #+#             */
/*   Updated: 2024/12/18 15:59:26 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/**
 * @struct s_node
 * @brief Represents a node in the stack.
 * @details Each node stores a value and its sorted index, along with pointers
 * to the previous and next nodes, forming a doubly linked list structure.
 */
typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

/**
 * @struct s_stack
 * @brief Represents a stack with a pointer to the top node and the current size.
 *
 * @details This structure is used to track elements in a stack and support
 * operations like push, pop, and swap.
 */
typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

/**
 * @struct s_push_swap
 * @brief Holds the two stacks (`a` and `b`) and tracks the number of moves.
 *
 * @see s_stack
 * @details This structure manages sorting operations in the push_swap program,
 * tracking the stacks and counting the number of moves performed.
 */
typedef struct s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	int				move_count;
	int				print_mode;
}					t_push_swap;

typedef struct s_rotation
{
	int				rotation_a;
	int				rotation_b;
	int				cost;
}					t_rotation;

// Stack Operations (Swap, Push, Rotate)

void				sa(t_push_swap *ps);
void				sb(t_push_swap *ps);
void				ss(t_push_swap *ps);
void				pa(t_push_swap *ps);
void				pb(t_push_swap *ps);
void				ra(t_push_swap *ps);
void				rb(t_push_swap *ps);
void				rr(t_push_swap *ps);
void				rra(t_push_swap *ps);
void				rrb(t_push_swap *ps);
void				rrr(t_push_swap *ps);

// Move Evaluation Functions

int					calculate_rotation_a(t_stack *a, int target_position);
int					calculate_rotation_b(t_stack *b, int b_position);
int					find_target_position(t_stack *a, int b_value);
int					calculate_move_cost(t_stack *a, t_stack *b, int b_position);
int					calculate_rotation_cost(int rotation_a, int rotation_b);

// Stack Utility Functions

t_node				*new_node(int value);
t_node				*get_node_at(t_stack *stack, int position);
void				push(t_stack *stack, t_node *node);
t_node				*pop(t_stack *stack);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);
void				swap(t_stack *stack);
int					is_empty(t_stack *stack);
int					is_sorted(t_stack *stack);
void				sort_three(t_stack *a, t_push_swap *ps);
void				perform_rotations(t_push_swap *ps, int rotation_a,
						int rotation_b);
void				free_stacks(t_push_swap *ps);

// Helper Functions

void				swap_mod(int *a, int *b);
int					partition(int *arr, int low, int high);
void				quick_sort(int *arr, int low, int high);

// Main Functions for push_swap Execution and Setup

void				push_swap_execute(int argc, char **argv);
int					parse_single_argument(int *argc, char ***argv);
int					*parse_and_convert_args(char **argv, int size);
int					*copy_and_sort_values(int *values, int size);
void				initialize_stacks(t_push_swap *ps, int *values, int size);
void				sort_push_swap(t_push_swap *ps);
void				final_rotate_sort(t_push_swap *ps);

void				initialize_ab(t_push_swap *ps, t_stack *a, t_stack *b);
void				error_exit_indices(int *values, int *sorted_values);
void				error_exit_init(int *values);
int					validate_args(char **argv, int size);
void				free_argv(char **argv);

// Functions for Pushing Elements to Stack B

t_node				*get_node_at(t_stack *stack, int position);
int					find_target_position_in_b(t_stack *b, int value);
int					calculate_move_cost_to_b(t_stack *a, t_stack *b,
						int a_position);
void				find_best_move_to_b(t_push_swap *ps, int *best_rotation_a,
						int *best_rotation_b);
// parsing_utils.c
void				free_argv(char **argv);
void				free_new_argv_on_error(char **new_argv, int allocated);
void				free_split(char **split);

#endif