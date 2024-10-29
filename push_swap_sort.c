/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:59:35 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/29 18:49:08 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_best_rotation(t_push_swap *ps, int *best_rotation_a,
		int *best_rotation_b)
{
	t_node	*b_node;
	int		min_cost;
	int		b_position;
	int		cost;
	int		target_position;

	b_node = ps->b->top;
	min_cost = INT_MAX;
	b_position = 0;
	while (b_node)
	{
		cost = calculate_move_cost(ps->a, ps->b, b_position);
		if (cost < min_cost)
		{
			min_cost = cost;
			target_position = find_target_position(ps->a, b_node->index);
			*best_rotation_a = calculate_rotation_a(ps->a, target_position);
			*best_rotation_b = calculate_rotation_b(ps->b, b_position);
		}
		b_node = b_node->next;
		b_position++;
	}
}

static void	push_until_three(t_push_swap *ps)
{
	while (ps->a->size > 3)
		pb(ps);
	if (!is_sorted(ps->a))
		sort_three(ps->a, ps);
}

void	sort_push_swap(t_push_swap *ps)
{
	int	best_rotation_a;
	int	best_rotation_b;

	push_until_three(ps);
	while (ps->b->size > 0)
	{
		find_best_rotation(ps, &best_rotation_a, &best_rotation_b);
		perform_rotations(ps, best_rotation_a, best_rotation_b);
		pa(ps);
	}
}
