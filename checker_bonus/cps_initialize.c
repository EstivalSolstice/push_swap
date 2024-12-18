/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cps_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:20:31 by joltmann          #+#    #+#             */
/*   Updated: 2024/12/18 17:03:02 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	initialize_values(const char **argv, int *values, int *indices, int count)
{
	int	i;

	for (i = 0; i < count - 1; i++)
	{
		values[i] = ft_atoi(argv[i + 1]);
		indices[i] = i;
	}
	return (1);
}

// int	initialize_values(int **values, int **indices, int count)
// {
// 	*values = malloc(sizeof(int) * (count) - 1);
// 	*indices = malloc(sizeof(int) * (count) - 1);
// 	if (!*values || !*indices)
// 	{
// 		if (*values)
// 			free(*values);
// 		if (*indices)
// 			free(*indices);
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	return (1);
// }

// int	initialize_values(int **values, int **indices, int count)
// {
// 	*values = malloc(sizeof(int) * count);
// 	*indices = malloc(sizeof(int) * count);
// 	if (!*values || !*indices)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	return (1);
// }

void	free_values_and_indices(int *values, int *indices)
{
	if (values)
		free(values);
	if (indices)
		free(indices);
}

int	initialize_push_swap(t_push_swap *ps, int *values, int count)
{
	initialize_stacks(ps, values, count);
	// free(values);
	// free(indices);
	return (1);
}
