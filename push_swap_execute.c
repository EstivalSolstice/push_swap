/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:39:12 by joltmann          #+#    #+#             */
/*   Updated: 2025/01/25 19:08:34 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_parsing(int *argc, char ***argv)
{
	int	argv_modified;

	argv_modified = parse_single_argument(argc, argv);
	if (!validate_args((*argv) + 1, *argc - 1))
	{
		write(2, "Error\n", 6);
		if (argv_modified)
			free_argv(*argv);
		return (0);
	}
	return (argv_modified);
}

static void	free_stacks_and_arrays(int *values,
		int *sorted_values, t_push_swap *ps)
{
	free(values);
	free(sorted_values);
	free_stacks(ps);
}

static void	free_if_modified(int argv_modified, char **argv)
{
	if (argv_modified)
		free_argv(argv);
}

static void	sort_stack(t_push_swap *ps)
{
	if (is_sorted(ps->a))
		return ;
	sort_push_swap(ps);
	if (!is_sorted(ps->a) && is_empty(ps->b))
		final_rotate_sort(ps);
}

void	push_swap_execute(int argc, char **argv)
{
	int			size;
	int			*values;
	int			*sorted_values;
	t_push_swap	ps;
	int			argv_modified;

	ps.print_mode = 1;
	argv_modified = handle_parsing(&argc, &argv);
	if (argc <= 2)
		return (free_if_modified(argv_modified, argv));
	// if (!argv_modified)
	// 	return ;
	size = argc - 1;
	if (!validate_args(argv + 1, size))
	{
		free_if_modified(argv_modified, argv);
		return ;
	}
	values = parse_and_convert_args(argv, size);
	sorted_values = copy_and_sort_values(values, size);
	initialize_stacks(&ps, values, size);
	sort_stack(&ps);
	free_stacks_and_arrays(values, sorted_values, &ps);
	free_if_modified(argv_modified, argv);
}
