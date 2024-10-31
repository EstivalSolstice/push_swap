/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:20:31 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/31 20:21:23 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	initialize_values(int **values, int **indices, int count)
{
	*values = malloc(sizeof(int) * count);
	*indices = malloc(sizeof(int) * count);
	if (!*values || !*indices)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	initialize_push_swap(t_push_swap *ps, int *values, int *indices, int count)
{
	initialize_stacks(ps, values, indices, count);
	free(values);
	free(indices);
	return (1);
}
