/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:08:26 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/28 20:35:38 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit_indices(int *values, int *sorted_values)
{
	ft_printf("Error\n");
	free(values);
	free(sorted_values);
	exit(1);
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
		error_exit_indices(values, sorted_values);
	while (i < size)
	{
		j = 0;
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
