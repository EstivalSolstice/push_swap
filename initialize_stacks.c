/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:07:20 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/29 18:30:00 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit_init(int *values)
{
	write(2, "Error\n", 6);
	free(values);
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

void	initialize_stacks(t_push_swap *ps, int *values, int size)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*node;
	int		i;

	i = size - 1;
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		error_exit_init(values);
	initialize_ab(ps, a, b);
	while (i >= 0)
	{
		node = new_node(values[i]);
		if (!node)
			error_exit_init(values);
		push(a, node);
		i--;
	}
	ps->move_count = 0;
}
