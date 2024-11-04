/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cps_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:10:59 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/01 22:50:21 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	display_result(t_push_swap *ps)
{
	if (is_sorted(ps->a) && ps->b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(ps->b);
}

int	checker_execute(int argc, char **argv)
{
	t_push_swap	ps;
	int			*values;
	int			*indices;

	ps.print_mode = 0;
	if (!check_args(argc, argv))
		return (0);
	if (!parse_and_validate(&argc, &argv))
		return (1);
	if (!initialize_values(&values, &indices, argc - 1))
		return (1);
	values = convert_args_to_values(argv, argc - 1);
	if (!values)
		return (1);
	indices = sort_and_assign_indices(values, argc - 1);
	if (!indices)
		return (1);
	initialize_push_swap(&ps, values, indices, argc - 1);
	process_operations(&ps);
	display_result(&ps);
	return (0);
}

int	main(int argc, char **argv)
{
	checker_execute(argc, argv);
	return (0);
}
