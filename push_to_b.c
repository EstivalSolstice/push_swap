/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:05:32 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/29 18:21:08 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_node_at(t_stack *stack, int position)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current && i < position)
	{
		current = current->next;
		i++;
	}
	return (current);
}

int	find_target_position_in_b(t_stack *b, int value)
{
	t_node	*current;
	int		position;

	current = b->top;
	position = 0;
	while (current)
	{
		if (value > current->value)
			break ;
		current = current->next;
		position++;
	}
	return (position);
}

int	calculate_move_cost_to_b(t_stack *a, t_stack *b, int a_position)
{
	t_node	*a_node;
	int		i;
	int		target_position;
	int		rotation_a;
	int		rotation_b;

	a_node = a->top;
	i = 0;
	while (i < a_position && a_node != NULL)
	{
		a_node = a_node->next;
		i++;
	}
	if (a_node == NULL)
		return (INT_MAX);
	target_position = find_target_position_in_b(b, a_node->value);
	rotation_a = calculate_rotation_a(a, a_position);
	rotation_b = calculate_rotation_b(b, target_position);
	return (calculate_rotation_cost(rotation_a, rotation_b));
}

void	find_best_move_to_b(t_push_swap *ps, int *best_rotation_a,
		int *best_rotation_b)
{
	int	best_cost;
	int	current_cost;
	int	i;
	int	target_position;

	i = 0;
	best_cost = INT_MAX;
	while (i < ps->a->size)
	{
		current_cost = calculate_move_cost_to_b(ps->a, ps->b, i);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			target_position = find_target_position_in_b(ps->b,
					get_node_at(ps->a, i)->value);
			*best_rotation_a = calculate_rotation_a(ps->a, i);
			*best_rotation_b = calculate_rotation_b(ps->b, target_position);
		}
		i++;
	}
}
