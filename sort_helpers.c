/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:56:11 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/28 17:31:41 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
	{
		return (1);
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
	{
		return (1);
	}
	current = stack->top;
	while (current && current->next)
	{
		if (current->index > current->next->index)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

void	sort_three(t_stack *a, t_push_swap *ps)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first < second && second < third)
	{
		return ;
	}
	if (first > second && second < third && first < third)
	{
		sa(ps);
		return ;
	}
	if (first < second && second > third && first < third)
	{
		rra(ps);
		sa(ps);
		return ;
	}
	if (first < second && second > third && first > third)
	{
		sa(ps);
		rra(ps);
		return ;
	}
	if (first > second && second < third && first > third)
	{
		ra(ps);
		return ;
	}
	if (first > second && second > third)
	{
		ra(ps);
		sa(ps);
		return ;
	}
}

void	swap_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

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
