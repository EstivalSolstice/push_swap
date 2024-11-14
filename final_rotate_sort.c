/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:48:49 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/14 17:41:09 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_stack *a)
{
	t_node	*current;
	int		min_value;
	int		min_position;
	int		position;

	current = a->top;
	min_value = INT_MAX;
	min_position = 0;
	position = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	return (min_position);
}

static void	perform_final_rotation(t_push_swap *ps, int rotation)
{
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

void	final_rotate_sort(t_push_swap *ps)
{
	int	min_position;
	int	rotation;

	min_position = find_min_position(ps->a);
	rotation = calculate_rotation_a(ps->a, min_position);
	perform_final_rotation(ps, rotation);
	// print_stacks(ps->a, ps->b);
}
