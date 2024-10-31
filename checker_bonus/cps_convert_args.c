/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_convert_vald.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:25:49 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/31 20:25:56 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*convert_args_to_values(char **argv, int count)
{
	int	*values;
	int	i;

	i = 0;
	values = malloc(sizeof(int) * count);
	if (!values)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	while (i < count)
	{
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (values);
}
