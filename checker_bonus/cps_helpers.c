/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cps_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:07:37 by joltmann          #+#    #+#             */
/*   Updated: 2024/12/18 16:25:11 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// void	free_stack(t_stack *stack)
// {
// 	t_node	*current;
// 	t_node	*next;

// 	current = stack->top;
// 	while (current)
// 	{
// 		next = current->next;
// 		free(current);
// 		current = next;
// 	}
// 	free(stack);
// }

// void	cps_free_stacks(t_push_swap *ps)
// {
// 	if (ps->a)
// 		free_stack(ps->a);
// 	if (ps->b)
// 		free_stack(ps->b);
// }