/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cps_parse_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:24:20 by joltmann          #+#    #+#             */
/*   Updated: 2024/12/18 16:02:46 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_and_validate(int *argc, char ***argv)
{
	parse_single_argument(argc, argv);
	if (!validate_args(*argv + 1, *argc - 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
