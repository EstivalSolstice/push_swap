/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:51:07 by joltmann          #+#    #+#             */
/*   Updated: 2025/01/24 01:00:25 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *ps)
{
	swap(ps->a);
	if (ps->print_mode)
		ft_printf("sa\n");
	ps->move_count++;
}

void	sb(t_push_swap *ps)
{
	swap(ps->b);
	if (ps->print_mode)
		ft_printf("sb\n");
	ps->move_count++;
}

void	ss(t_push_swap *ps)
{
	swap(ps->a);
	swap(ps->b);
	if (ps->print_mode)
		ft_printf("ss\n");
	ps->move_count++;
}

void	pa(t_push_swap *ps)
{
	t_node	*node;

	node = pop(ps->b);
	if (node)
	{
		push(ps->a, node);
		if (ps->print_mode)
			ft_printf("pa\n");
		ps->move_count++;
	}
}

void	pb(t_push_swap *ps)
{
	t_node	*node;

	node = pop(ps->a);
	if (node)
	{
		push(ps->b, node);
		if (ps->print_mode)
			ft_printf("pb\n");
		ps->move_count++;
	}
}
