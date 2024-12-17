/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:40:20 by joltmann          #+#    #+#             */
/*   Updated: 2024/12/17 17:02:32 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*assign_indices(const int *values, int *sorted_values, int count)
{
	int	*indices;
	int	i;
	int	j;

	indices = malloc(sizeof(int) * count);
	if (!indices)
		return (NULL);
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
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
