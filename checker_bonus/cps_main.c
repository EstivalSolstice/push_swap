/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cps_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:10:59 by joltmann          #+#    #+#             */
/*   Updated: 2025/01/24 01:14:49 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	display_result(t_push_swap *ps)
{
	if (is_sorted(ps->a) && ps->b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(ps);
}

int	checker_execute(int argc, char **argv)
{
	t_push_swap	ps;
	int			*values;
	int			*indices;

	ps.print_mode = 0;
	if (!check_args(argc, argv))
		return (0);
	values = malloc(sizeof(int) * (argc - 1));
	if (!values)
		return (write(2, "Error\n", 6), 1);
	indices = malloc(sizeof(int) * (argc - 1));
	if (!indices)
	{
		free_values_and_indices(values, indices);
		write(2, "Error\n", 6);
		return (1);
	}
	initialize_values((const char **)(argv + 1), values, indices, argc - 1);
	initialize_push_swap(&ps, values, argc - 1);
	process_operations(&ps);
	display_result(&ps);
	free_values_and_indices(values, indices);
	return (0);
}

int	main(int argc, char **argv)
{
	checker_execute(argc, argv);
	return (0);
}
