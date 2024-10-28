/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:53:17 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/28 19:53:26 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_rotations(t_push_swap *ps, int rotation_a, int rotation_b)
{
	if (ps->a->size == 3 && !is_sorted(ps->a))
	{
		sort_three(ps->a, ps);
		return ;
	}
	if (rotation_a >= 0 && rotation_b >= 0)
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
	else if (rotation_a < 0 && rotation_b < 0)
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
	else
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
}
