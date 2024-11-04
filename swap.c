/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:29:23 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/04 18:41:34 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	swap(t_stack *stack)
// {
// 	t_node	*first;
// 	t_node	*second;

// 	if (!stack || stack->size < 2)
// 		return ;
// 	first = stack->top;
// 	second = first->next;
// 	first->next = second->next;
// 	if (second->next)
// 		second->next->prev = first;
// 	second->next = first;
// 	first->prev = second;
// 	second->prev = NULL;
// 	stack->top = second;
// }

void swap(t_stack *stack)
{
    int temp;
    if (stack->size < 2)
        return;
    temp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = temp;
}
