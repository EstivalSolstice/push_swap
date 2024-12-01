/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:39:12 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/29 18:30:16 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_execute(int argc, char **argv)
{
	int			size;
	int			*values;
	int			*sorted_values;
	t_push_swap	ps;

	ps.print_mode = 1;
	parse_single_argument(&argc, &argv);
	size = argc - 1;
	if (!validate_args(argv, size))
	{
		write(2, "Error\n", 6);
		return ;
	}
	values = parse_and_convert_args(argv, size);
	sorted_values = copy_and_sort_values(values, size);
	initialize_stacks(&ps, values, size);
	sort_push_swap(&ps);
	final_rotate_sort(&ps);
	free(values);
	free(sorted_values);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	push_swap_execute(argc, argv);
	return (0);
}
