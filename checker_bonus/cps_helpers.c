/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cps_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:07:37 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/31 20:50:12 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstclear_tnode(t_node **node, void (*del)(void *))
{
	ft_lstclear((t_list **)node, del);
}

void	free_stack(t_stack *stack)
{
	ft_lstclear_tnode(&(stack->top), NULL);
	free(stack);
}
