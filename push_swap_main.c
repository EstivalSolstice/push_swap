/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:39:12 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/31 21:29:37 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_execute(int argc, char **argv)
{
	int			size;
	int			*values;
	int			*sorted_values;
	int			*indices;
	t_push_swap	ps;

	ps.print_mode = 1;
	parse_single_argument(&argc, &argv);
	size = argc - 1;
	if (!validate_args(argv, size))
	{
		ft_printf("Error\n");
		return ;
	}
	values = parse_and_convert_args(argv, size);
	sorted_values = copy_and_sort_values(values, size);
	indices = assign_indices(values, sorted_values, size);
	initialize_stacks(&ps, values, indices, size);
	sort_push_swap(&ps);
	final_rotate_sort(&ps);
	free(values);
	free(sorted_values);
	free(indices);
}
// ft_printf("Total moves: %d\n", ps.move_count);

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	push_swap_execute(argc, argv);
	return (0);
}
