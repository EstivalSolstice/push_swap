/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:45:14 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/28 19:39:12 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_rotation_a(t_stack *a, int target_position)
{
	if (target_position <= a->size / 2)
		return (target_position);
	else
		return ((a->size - target_position) * -1);
}

int	calculate_rotation_b(t_stack *b, int b_position)
{
	if (b_position <= b->size / 2)
		return (b_position);
	else
		return ((b->size - b_position) * -1);
}

int	calculate_move_cost(t_stack *a, t_stack *b, int b_position)
{
	t_node	*b_node;
	int		i;
	int		target_position;
	int		rotation_a;
	int		rotation_b;
	int		cost;
	int		rotation_a_abs;
	int		rotation_b_abs;

	b_node = b->top;
	i = 0;
	while (i < b_position && b_node != NULL)
	{
		b_node = b_node->next;
		i++;
	}
	if (b_node == NULL)
	{
		return (INT_MAX);
	}
	target_position = find_target_position(a, b_node->index);
	rotation_a = calculate_rotation_a(a, target_position);
	rotation_b = calculate_rotation_b(b, b_position);
	cost = 0;
	if (rotation_a < 0)
		rotation_a_abs = -rotation_a;
	else
		rotation_a_abs = rotation_a;
	if (rotation_b < 0)
		rotation_b_abs = -rotation_b;
	else
		rotation_b_abs = rotation_b;
	if ((rotation_a >= 0 && rotation_b >= 0) || (rotation_a < 0
			&& rotation_b < 0))
	{
		if (rotation_a_abs > rotation_b_abs)
			cost = rotation_a_abs;
		else
			cost = rotation_b_abs;
	}
	else
	{
		cost = rotation_a_abs + rotation_b_abs;
	}
	cost += 1;
	return (cost);
}
