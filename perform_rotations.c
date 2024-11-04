/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:53:17 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/04 17:48:11 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_case1(t_push_swap *ps, int rotation_a, int rotation_b)
{
	while (rotation_a > 0 && rotation_b > 0)
	{
		rr(ps);
		rotation_a--;
		rotation_b--;
	}
	while (rotation_a > 0)
	{
		ra(ps);
		rotation_a--;
	}
	while (rotation_b > 0)
	{
		rb(ps);
		rotation_b--;
	}
}

static void	rotate_case2(t_push_swap *ps, int rotation_a, int rotation_b)
{
	while (rotation_a < 0 && rotation_b < 0)
	{
		rrr(ps);
		rotation_a++;
		rotation_b++;
	}
	while (rotation_a < 0)
	{
		rra(ps);
		rotation_a++;
	}
	while (rotation_b < 0)
	{
		rrb(ps);
		rotation_b++;
	}
}

static void	rotate_opposite_case(t_push_swap *ps, int rotation_a, int rotation_b)
{
	while (rotation_a > 0)
	{
		ra(ps);
		rotation_a--;
	}
	while (rotation_a < 0)
	{
		rra(ps);
		rotation_a++;
	}
	while (rotation_b > 0)
	{
		rb(ps);
		rotation_b--;
	}
	while (rotation_b < 0)
	{
		rrb(ps);
		rotation_b++;
	}
}

void perform_rotations(t_push_swap *ps, int rotation_a, int rotation_b)
{
	if (rotation_a >= 0 && rotation_b >= 0)
		rotate_case1(ps, rotation_a, rotation_b);
	else if (rotation_a < 0 && rotation_b < 0)
		rotate_case2(ps, rotation_a, rotation_b);
	else
		rotate_opposite_case(ps, rotation_a, rotation_b);
}
