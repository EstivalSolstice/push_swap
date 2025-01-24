/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cps_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:05:47 by joltmann          #+#    #+#             */
/*   Updated: 2025/01/24 01:14:00 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	invalid_input(t_push_swap *ps, char *operation)
{
	write(2, "Error\n", 6);
	if (operation)
		free(operation);
	free_stacks(ps);
	exit(1);
}

static void	execute_operation(t_push_swap *ps, char *operation)
{
	if (ft_strncmp(operation, "sa\n", 3) == 0)
		sa(ps);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		sb(ps);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		ss(ps);
	else if (ft_strncmp(operation, "pa\n", 3) == 0)
		pa(ps);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		pb(ps);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		ra(ps);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rb(ps);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		rr(ps);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		rra(ps);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		rrb(ps);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		rrr(ps);
	else
		invalid_input(ps, operation);
}

void	process_operations(t_push_swap *ps)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		execute_operation(ps, operation);
		free(operation);
		operation = get_next_line(0);
	}
}
