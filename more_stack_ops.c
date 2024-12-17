/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stack_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:21:40 by joltmann          #+#    #+#             */
/*   Updated: 2024/12/17 22:22:01 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	if (stack->top)
		stack->top->prev = node;
	stack->top = node;
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	node->next = NULL;
	stack->size--;
	return (node);
}

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	stack->top->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}
