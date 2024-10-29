/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:10:59 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/30 00:48:50 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief Wrapper function for ft_lstclear
 */
void	ft_lstclear_tnode(t_node **node, void (*del)(void *))
{
	ft_lstclear((t_list **)node, del);
}

// int	is_sorted_val(t_stack *stack)
// {
// 	t_node	*current;

// 	if (!stack || !stack->top)
// 		return (1);
// 	current = stack->top;
// 	while (current && current->next)
// 	{
// 		if (current->value > current->next->value)
// 			return (0);
// 		current = current->next;
// 	}
// 	return (1);
// }

void	free_stack(t_stack *stack)
{
	ft_lstclear_tnode(&(stack->top), NULL);
	free(stack);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	char		*operation;
	char		*next_operation;
	int			*values;
	int			*sorted_values;
	int			*indices;
	int			i;

	if (argc < 2)
		return (ft_printf("Error\n"), 0);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (ft_printf("Error\n"), 1);
		i++;
	}
	ps.print_mode = 0;
	parse_single_argument(&argc, &argv);
	if (!validate_args(argv, argc - 1))
		return (ft_printf("Error\n"), 1);
	values = malloc(sizeof(int) * (argc - 1));
	indices = malloc(sizeof(int) * (argc - 1));
	if (!values || !indices)
		return (ft_printf("Error\n"), 1);
	i = 0;
	while (i < argc - 1)
	{
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	sorted_values = copy_and_sort_values(values, argc - 1);
	if (!sorted_values)
		return (free(values), free(indices), ft_printf("Error\n"), 1);
	indices = assign_indices(values, sorted_values, argc - 1);
	free(sorted_values);
	initialize_stacks(&ps, values, indices, argc - 1);
	free(values);
	free(indices);
	operation = get_next_line(0);
	if (operation == NULL)
	{
		if (is_sorted(ps.a) && ps.b->size == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
	{
		while (operation != NULL)
		{
			next_operation = ft_strchr(operation, ' ');
			if (next_operation)
				*next_operation = '\0';
			if (ft_strncmp(operation, "sa\n", 3) == 0)
				sa(&ps);
			else if (ft_strncmp(operation, "sb\n", 3) == 0)
				sb(&ps);
			else if (ft_strncmp(operation, "ss\n", 3) == 0)
				ss(&ps);
			else if (ft_strncmp(operation, "pa\n", 3) == 0)
				pa(&ps);
			else if (ft_strncmp(operation, "pb\n", 3) == 0)
				pb(&ps);
			else if (ft_strncmp(operation, "ra\n", 3) == 0)
				ra(&ps);
			else if (ft_strncmp(operation, "rb\n", 3) == 0)
				rb(&ps);
			else if (ft_strncmp(operation, "rr\n", 3) == 0)
				rr(&ps);
			else if (ft_strncmp(operation, "rra\n", 4) == 0)
				rra(&ps);
			else if (ft_strncmp(operation, "rrb\n", 4) == 0)
				rrb(&ps);
			else if (ft_strncmp(operation, "rrr\n", 4) == 0)
				rrr(&ps);
			else
			{
				ft_printf("Error DEBUG\n");
				free(operation);
				// free_stack(ps.a);
				free_stack(ps.b);
				exit(1);
			}
			free(operation);
			operation = get_next_line(0);
		}
		if (is_sorted(ps.a) && ps.b->size == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stack(ps.b);
		return (0);
	}
}
