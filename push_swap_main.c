/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:39:12 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/27 19:39:28 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"


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

	size = argc - 1;
	values = parse_and_convert_args(argv, size);
	sorted_values = copy_and_sort_values(values, size);
	indices = assign_indices(values, sorted_values, size);
	initialize_stacks(&ps, values, indices, size);
	sort_push_swap(&ps);
	final_rotate_sort(&ps);
	ft_printf("Total moves: %d\n", ps.move_count);
	free(values);
	free(sorted_values);
	free(indices);
}

int	*parse_and_convert_args(char **argv, int size)
{
	int	*values;

	values = malloc(sizeof(int) * size);
	if (!values)
	{
		ft_printf("Error\n");
		exit(1);
	}
	for (int i = 0; i < size; i++)
	{
		values[i] = ft_atoi(argv[i + 1]);
	}
	return (values);
}

int	*copy_and_sort_values(int *values, int size)
{
	int	*sorted_values;

	sorted_values = malloc(sizeof(int) * size);
	if (!sorted_values)
	{
		ft_printf("Error\n");
		free(values);
		exit(1);
	}
	for (int i = 0; i < size; i++)
	{
		sorted_values[i] = values[i];
	}
	quick_sort(sorted_values, 0, size - 1);
	return (sorted_values);
}

int	*assign_indices(int *values, int *sorted_values, int size)
{
	int	*indices;

	indices = malloc(sizeof(int) * size);
	if (!indices)
	{
		ft_printf("Error\n");
		free(values);
		free(sorted_values);
		exit(1);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (values[i] == sorted_values[j])
			{
				indices[i] = j;
				break ;
			}
		}
	}
	return (indices);
}

void	initialize_stacks(t_push_swap *ps, int *values, int *indices, int size)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*node;

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
	for (int i = size - 1; i >= 0; i--)
	{
		node = new_node(values[i], indices[i]);
		push(a, node);
	}
}
