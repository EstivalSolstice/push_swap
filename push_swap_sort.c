/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:59:35 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/28 17:31:33 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_push_swap(t_push_swap *ps)
{
	int		min_cost;
	int		best_rotation_a;
	int		best_rotation_b;
	t_node	*b_node;
	int		b_position;
	int		cost;
	int		target_position;

	while (ps->a->size > 3)
	{
		pb(ps);
	}
	if (!is_sorted(ps->a))
	{
		sort_three(ps->a, ps);
	}
	while (ps->b->size > 0)
	{
		min_cost = INT_MAX;
		best_rotation_a = 0;
		best_rotation_b = 0;
		b_node = ps->b->top;
		b_position = 0;
		while (b_node)
		{
			cost = calculate_move_cost(ps->a, ps->b, b_position);
			if (cost < min_cost)
			{
				min_cost = cost;
				target_position = find_target_position(ps->a, b_node->index);
				best_rotation_a = calculate_rotation_a(ps->a, target_position);
				best_rotation_b = calculate_rotation_b(ps->b, b_position);
			}
			b_node = b_node->next;
			b_position++;
		}
		perform_rotations(ps, best_rotation_a, best_rotation_b);
		pa(ps);
	}
}

void	final_rotate_sort(t_push_swap *ps)
{
	int		min_position;
	t_node	*current;
	int		min_index;
	int		position;
	int		rotation;

	min_position = 0;
	current = ps->a->top;
	min_index = INT_MAX;
	position = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	rotation = calculate_rotation_a(ps->a, min_position);
	while (rotation > 0)
	{
		if (!is_sorted(ps->a) && !is_empty(ps->b))
			break ;
		ra(ps);
		rotation--;
	}
	while (rotation < 0)
	{
		if (!is_sorted(ps->a) && !is_empty(ps->b))
			break ;
		rra(ps);
		rotation++;
	}
}
