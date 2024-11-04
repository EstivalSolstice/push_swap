/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:38:51 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/03 18:26:48 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_closest_larger(t_stack *a, int b_index)
{
	t_node	*current;
	int		position;
	int		min_diff;
	int		target_position;
	int		diff;

	current = a->top;
	position = 0;
	min_diff = INT_MAX;
	target_position = 0;
	while (current)
	{
		diff = current->index - b_index;
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

static int	find_closest_smaller(t_stack *a, int b_index)
{
	t_node	*current;
	int		position;
	int		min_diff;
	int		target_position;
	int		diff;

	current = a->top;
	position = 0;
	min_diff = INT_MAX;
	target_position = 0;
	while (current)
	{
		diff = b_index - current->index;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target_position = position + 1;
		}
		current = current->next;
		position++;
	}
	return (target_position);
}

int	find_target_position(t_stack *a, int b_index)
{
	int	target_position;

	target_position = find_closest_larger(a, b_index);
	if (target_position == -1)
		target_position = find_closest_smaller(a, b_index);
	return (target_position);
}
