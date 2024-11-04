/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sort_assign_indices.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:27:03 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/31 20:27:10 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*sort_and_assign_indices(int *values, int count)
{
	int	*sorted_values;
	int	*indices;

	sorted_values = copy_and_sort_values(values, count);
	if (!sorted_values)
	{
		free(values);
		ft_printf("Error\n");
		return (NULL);
	}
	indices = assign_indices(values, sorted_values, count);
	free(sorted_values);
	return (indices);
}