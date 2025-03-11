/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cps_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:20:31 by joltmann          #+#    #+#             */
/*   Updated: 2025/03/04 07:25:29 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	initialize_values(const char **argv, int *values, int *indices, int count)
{
	int	i;

	i = 0;
	while (i < (count - 1))
	{
		values[i] = ft_atoi(argv[i]);
		indices[i] = i;
		i++;
	}
	return (1);
}

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
	return (1);
}
