/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:39:12 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/28 17:47:06 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	stack->top = second;
}

void	push_swap_execute(int argc, char **argv)
{
	int			size;
	int			*values;
	int			*sorted_values;
	int			*indices;
	t_push_swap	ps;

	parse_single_argument(&argc, &argv);
	size = argc - 1;
	values = parse_and_convert_args(argv, size);
	sorted_values = copy_and_sort_values(values, size);
	indices = assign_indices(values, sorted_values, size);
	initialize_stacks(&ps, values, indices, size);
	sort_push_swap(&ps);
	final_rotate_sort(&ps);
	// ft_printf("Total moves: %d\n", ps.move_count);
	free(values);
	free(sorted_values);
	free(indices);
}

void	parse_single_argument(int *argc, char ***argv)
{
	char	**split_args;
	char	**new_argv;
	int		count;
	int		i;

	if (*argc == 2)
	{
		i = 0;
		count = 0;
		split_args = ft_split((*argv)[1], ' ');
		while (split_args[count] != NULL)
			count++;
		*argc = count + 1;
		new_argv = malloc(sizeof(char *) * (*argc + 1));
		if (!*argv)
			exit(1);
		new_argv[0] = (*argv)[0];
		while (i < *argc)
		{
			new_argv[i + 1] = split_args[i];
			i++;
		}
		new_argv[*argc] = NULL;
		*argv = new_argv;
		free(split_args);
	}
}

int	*parse_and_convert_args(char **argv, int size)
{
	int	*values;
	int	i;

	i = 0;
	values = malloc(sizeof(int) * size);
	if (!values)
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (i < size)
	{
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (values);
}

int	*copy_and_sort_values(int *values, int size)
{
	int	*sorted_values;
	int	i;

	i = 0;
	sorted_values = malloc(sizeof(int) * size);
	if (!sorted_values)
	{
		ft_printf("Error\n");
		free(values);
		exit(1);
	}
	while (i < size)
	{
		sorted_values[i] = values[i];
		i++;
	}
	quick_sort(sorted_values, 0, size - 1);
	return (sorted_values);
}

int	*assign_indices(int *values, int *sorted_values, int size)
{
	int	*indices;
	int	i;
	int	j;

	i = 0;
	j = 0;
	indices = malloc(sizeof(int) * size);
	if (!indices)
	{
		ft_printf("Error\n");
		free(values);
		free(sorted_values);
		exit(1);
	}
	while (i < size)
	{
		while (j < size)
		{
			if (values[i] == sorted_values[j])
			{
				indices[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (indices);
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
	{
		ft_printf("Error\n");
		free(values);
		free(indices);
		exit(1);
	}
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	ps->a = a;
	ps->b = b;
	ps->move_count = 0;
	while (i >= 0)
	{
		node = new_node(values[i], indices[i]);
		push(a, node);
		i--;
	}
	ps->move_count = 0;
}
