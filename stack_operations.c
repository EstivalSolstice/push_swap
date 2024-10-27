/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:51:07 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/27 19:39:46 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"


void	sa(t_push_swap *ps)
{
	swap(ps->a);
	ft_printf("sa\n");
	ps->move_count++;
}

void	sb(t_push_swap *ps)
{
	swap(ps->b);
	ft_printf("sb\n");
	ps->move_count++;
}

void	ss(t_push_swap *ps)
{
	swap(ps->a);
	swap(ps->b);
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
		ft_printf("pb\n");
		ps->move_count++;
	}
}
