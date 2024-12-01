/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_and_sort_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:11:15 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/29 18:29:52 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_and_sort_values(int *values, int size)
{
	int	*sorted_values;
	int	i;

	i = 0;
	sorted_values = malloc(sizeof(int) * size);
	if (!sorted_values)
	{
		write(2, "Error\n", 6);
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
