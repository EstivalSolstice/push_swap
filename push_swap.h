/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:27:36 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/25 17:28:19 by joltmann         ###   ########.fr       */
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

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	int				move_count;
}					t_push_swap;

// Stack operations
// Swap
void				sa(t_push_swap *ps);
void				sb(t_push_swap *ps);
void				ss(t_push_swap *ps);
// Push
void				pa(t_push_swap *ps);
void				pb(t_push_swap *ps);
// Rotate
void				ra(t_push_swap *ps);
void				rb(t_push_swap *ps);
void				rr(t_push_swap *ps);
// Reverse Rotate
void				rra(t_push_swap *ps);
void				rrb(t_push_swap *ps);
void				rrr(t_push_swap *ps);

// Move eval
int					calculate_rotation_a(t_stack *a, int target_index);
int					calculate_rotation_b(t_stack *b, int element_index);
int					find_target_position(t_stack *a, int element_index);
int					calculate_move_cost(t_stack *a, t_stack *b, int b_position);

// Helper functions
// int 	compare_int(const void *a, const void *b);
t_node				*new_node(int value, int index);
void				push(t_stack *stack, t_node *node);
t_node				*pop(t_stack *stack);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);
void				swap(t_stack *stack);

void				perform_rotations(t_push_swap *ps, int rotation_a,
						int rotation_b);
int					is_empty(t_stack *stack);
int					is_sorted(t_stack *stack);
void				sort_three(t_stack *a, t_push_swap *ps);
void				swap_mod(int *a, int *b);
int					partition(int *arr, int low, int high);
void				quick_sort(int *arr, int low, int high);

void				push_swap_execute(int argc, char **argv);
int					*parse_and_convert_args(char **argv, int size);
int					*copy_and_sort_values(int *values, int size);
int					*assign_indices(int *values, int *sorted_values, int size);
void				initialize_stacks(t_push_swap *ps, int *values,
						int *indices, int size);
void				sort_push_swap(t_push_swap *ps);
void				final_rotate_sort(t_push_swap *ps);

#endif