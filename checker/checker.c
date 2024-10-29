/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:10:59 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/29 22:33:20 by joltmann         ###   ########.fr       */
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
	int			*indices;
	int			i;

	parse_single_argument(&argc, &argv);
	i = 0;
	values = malloc(sizeof(int) * (argc - 1));
	indices = malloc(sizeof(int) * (argc - 1));
	// printf("Hallo1\n");
	if (!values || !indices)
		return (ft_printf("Error\n"), 1);
	// printf("Hallo3\n");
	while (i < argc - 1)
	{
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	// printf("Hallo4\n");
	initialize_stacks(&ps, values, indices, argc - 1);
	// printf("Hallo5\n");
	operation = get_next_line(0);
	// printf("Read command: %s\n", operation);
	while (operation != NULL)
	{
		next_operation = ft_strchr(operation, ' ');
		if (next_operation)
			*next_operation = '\0';
		// printf("Hallo6\n");
		if (ft_strncmp(operation, "sa\n", 4) == 0)
			sa(&ps);
		else if (ft_strncmp(operation, "sb\n", 4) == 0)
			sb(&ps);
		else if (ft_strncmp(operation, "ss\n", 4) == 0)
			ss(&ps);
		else if (ft_strncmp(operation, "pa\n", 4) == 0)
			pa(&ps);
		else if (ft_strncmp(operation, "pb\n", 4) == 0)
			pb(&ps);
		else if (ft_strncmp(operation, "ra\n", 4) == 0)
			ra(&ps);
		else if (ft_strncmp(operation, "rb\n", 4) == 0)
			rb(&ps);
		else if (ft_strncmp(operation, "rr\n", 4) == 0)
			rr(&ps);
		else if (ft_strncmp(operation, "rra\n", 5) == 0)
			rra(&ps);
		else if (ft_strncmp(operation, "rrb\n", 5) == 0)
			rrb(&ps);
		else if (ft_strncmp(operation, "rrr\n", 5) == 0)
			rrr(&ps);
		else
		{
			ft_printf("Error\n");
			free(operation);
			free_stack(ps.a);
			free_stack(ps.b);
			free(values);
			free(indices);
			exit(1);
		}
		// printf("Hallo7\n");
		free(operation);
		operation = get_next_line(0);
	}
	if (is_sorted(ps.a) && ps.b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	// printf("Hallo9\n");
	// free_stack(ps.a);
	free_stack(ps.b);
	free(values);
	free(indices);
	// if (ps.a)
	// 	free_stack(ps.a);
	// if (ps.b)
	// 	free_stack(ps.b);
	// if (values)
	// 	free(values);
	// if (indices)
	// 	free(indices);
	return (0);
}
