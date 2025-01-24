/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:59:35 by joltmann          #+#    #+#             */
/*   Updated: 2025/01/24 01:00:05 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_best_rotation(t_rotation *current, t_rotation *best)
{
	if (current->cost < best->cost)
	{
		best->cost = current->cost;
		best->rotation_a = current->rotation_a;
		best->rotation_b = current->rotation_b;
	}
}

static t_rotation	calculate_cost(t_push_swap *ps, int b_value, int b_position)
{
	t_rotation	rotation;
	int			target_position;

	target_position = find_target_position(ps->a, b_value);
	rotation.rotation_a = calculate_rotation_a(ps->a, target_position);
	rotation.rotation_b = calculate_rotation_b(ps->b, b_position);
	rotation.cost = calculate_rotation_cost(rotation.rotation_a,
			rotation.rotation_b);
	return (rotation);
}

static void	find_best_rotation(t_push_swap *ps, int *best_rotation_a,
		int *best_rotation_b)
{
	t_node		*b_node;
	int			b_position;
	t_rotation	best_rotation;
	t_rotation	current_rotation;

	b_node = ps->b->top;
	b_position = 0;
	best_rotation.cost = INT_MAX;
	while (b_node)
	{
		current_rotation = calculate_cost(ps, b_node->value, b_position);
		update_best_rotation(&current_rotation, &best_rotation);
		b_node = b_node->next;
		b_position++;
	}
	*best_rotation_a = best_rotation.rotation_a;
	*best_rotation_b = best_rotation.rotation_b;
}

static void	push_until_three(t_push_swap *ps)
{
	int			best_rotation_a;
	int			best_rotation_b;

	while (ps->a->size > 3)
	{
		find_best_move_to_b(ps, &best_rotation_a, &best_rotation_b);
		perform_rotations(ps, best_rotation_a, best_rotation_b);
		pb(ps);
	}
}

void	sort_push_swap(t_push_swap *ps)
{
	int	best_rotation_a;
	int	best_rotation_b;

	if (ps->a->size == 2)
	{
		sa(ps);
		return ;
	}
	push_until_three(ps);
	sort_three(ps->a, ps);
	while (ps->b->size > 0)
	{
		find_best_rotation(ps, &best_rotation_a, &best_rotation_b);
		perform_rotations(ps, best_rotation_a, best_rotation_b);
		pa(ps);
	}
}
