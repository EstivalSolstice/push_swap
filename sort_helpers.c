/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:56:11 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/29 17:46:17 by joltmann         ###   ########.fr       */
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
		return ;
	if (first > second && second < third && first < third)
		return (sa(ps));
	if (first < second && second > third && first < third)
		return (rra(ps), sa(ps));
	if (first < second && second > third && first > third)
		return (sa(ps), rra(ps));
	if (first > second && second < third && first > third)
		return (ra(ps));
	if (first > second && second > third)
		return (ra(ps), sa(ps));
}

void	swap_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
