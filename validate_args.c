/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:52:33 by joltmann          #+#    #+#             */
/*   Updated: 2024/12/18 15:38:17 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_integer(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	num = 0;
	sign = 1;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

static int	check_for_duplicates(const int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_args(char **argv, int size)
{
	int		*values;
	int		i;
	long	tmp_value;

	values = malloc(sizeof(int) * size);
	if (!values)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!is_valid_integer(argv[i]))
			return (free(values), 0);
		tmp_value = ft_atoi(argv[i]);
		if (tmp_value < INT_MIN || tmp_value > INT_MAX)
			return (free(values), 0);
		values[i] = (int)tmp_value;
		i++;
	}
	if (check_for_duplicates(values, size))
		return (free(values), 0);
	free(values);
	return (1);
}
