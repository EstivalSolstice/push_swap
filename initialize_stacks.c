/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:07:20 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/28 19:09:39 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit_init(int *values, int *indices)
{
	ft_printf("Error\n");
	free(values);
	free(indices);
	exit(1);
}

void	initialize_ab(t_push_swap *ps, t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	ps->a = a;
	ps->b = b;
	ps->move_count = 0;
}

void	initialize_stacks(t_push_swap *ps, int *values, int *indices, int size)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*node;
	int		i;

	i = size - 1;
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		error_exit_init(values, indices);
	initialize_ab(ps, a, b);
	while (i >= 0)
	{
		node = new_node(values[i], indices[i]);
		if (!node)
			error_exit_init(values, indices);
		push(a, node);
		i--;
	}
	ps->move_count = 0;
}
