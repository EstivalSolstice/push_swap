/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:24:20 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/31 20:24:29 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_and_validate(int *argc, char ***argv)
{
	parse_single_argument(argc, argv);
	if (!validate_args(*argv, *argc - 1))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}