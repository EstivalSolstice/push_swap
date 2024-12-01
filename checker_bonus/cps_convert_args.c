/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cps_convert_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:25:49 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/29 18:30:25 by joltmann         ###   ########.fr       */
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
		write(2, "Error\n", 6);
		return (NULL);
	}
	while (i < count)
	{
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (values);
}
