/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:38:51 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/29 18:03:05 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_target_position(t_stack *a, int b_value)
// {
// 	t_node	*current;
// 	int		position;
// 	int		target_position;
// 	int		min_diff;
// 	int		diff;
// 	int		max_value;

// 	current = a->top;
// 	position = 0;
// 	target_position = 0;
// 	min_diff = INT_MAX;
// 	while (current)
// 	{
// 		diff = current->value - b_value;
// 		if (diff > 0 && diff < min_diff)
// 		{
// 			min_diff = diff;
// 			target_position = position;
// 		}
// 		current = current->next;
// 		position++;
// 	}
// 	if (min_diff == INT_MAX)
// 	{
// 		current = a->top;
// 		position = 0;
// 		max_value = INT_MIN;
// 		while (current)
// 		{
// 			if (current->value > max_value)
// 			{
// 				max_value = current->value;
// 				target_position = position + 1;
// 			}
// 			current = current->next;
// 			position++;
// 		}
// 	}
// 	return (target_position % a->size);
// }

int	find_best_position(t_stack *a, int b_value)
{
	t_node	*current;
	int		position;
	int		target_position;
	int		min_diff;
	int		diff;

	current = a->top;
	position = 0;
	target_position = 0;
	min_diff = INT_MAX;
	while (current)
	{
		diff = current->value - b_value;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target_position = position;
		}
		current = current->next;
		position++;
	}
	if (min_diff == INT_MAX)
		return (-1);
	return (target_position);
}

int	find_max_position(t_stack *a)
{
	t_node	*current;
	int		position;
	int		target_position;
	int		max_value;

	current = a->top;
	position = 0;
	target_position = 0;
	max_value = INT_MIN;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			target_position = position + 1;
		}
		current = current->next;
		position++;
	}
	return (target_position);
}

int	find_target_position(t_stack *a, int b_value)
{
	int	target_position;

	target_position = find_best_position(a, b_value);
	if (target_position == -1)
		target_position = find_max_position(a);
	return (target_position % a->size);
}
