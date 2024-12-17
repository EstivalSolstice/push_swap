/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:55:10 by joltmann          #+#    #+#             */
/*   Updated: 2024/12/17 22:21:57 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_push_swap *ps)
{
	t_node	*temp;

	while (ps->a->top)
	{
		temp = ps->a->top;
		ps->a->top = ps->a->top->next;
		free(temp);
	}
	free(ps->a);
	while (ps->b->top)
	{
		temp = ps->b->top;
		ps->b->top = ps->b->top->next;
		free(temp);
	}
	free(ps->b);
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
