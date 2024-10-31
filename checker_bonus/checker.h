/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:13:39 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/31 20:27:24 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

/**
 * @brief Wrapper function for ft_lstclear
 */
void	ft_lstclear_tnode(t_node **node, void (*del)(void *));
void	free_stack(t_stack *stack);

int		initialize_values(int **values, int **indices, int count);
int		initialize_push_swap(t_push_swap *ps, int *values, int *indices,
			int count);

int		check_args(int argc, char **argv);
int		parse_and_validate(int *argc, char ***argv);

int		*convert_args_to_values(char **argv, int count);
int		*sort_and_assign_indices(int *values, int count);

void	process_operations(t_push_swap *ps);

int		checker_execute(int argc, char **argv);

void	display_result(t_push_swap *ps);

#endif