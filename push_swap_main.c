/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:39:12 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/14 18:08:48 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_stack *a, t_stack *b)
{
    t_node *current;

    printf("Stack A: ");
    current = a->top;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    printf("Stack B: ");
    current = b->top;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n\n");
}

void	push_swap_execute(int argc, char **argv)
{
	int			size;
	int			*values;
	int			*sorted_values;
	// int			*indices;
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
	// indices = assign_indices(values, sorted_values, size);
	initialize_stacks(&ps, values, size);
	sort_push_swap(&ps);
	final_rotate_sort(&ps);
	free(values);
	free(sorted_values);
	// free(indices);
	// ft_printf("Total moves: %d\n", ps.move_count);
}


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
