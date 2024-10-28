/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:06:06 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/28 19:35:32 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_new_argv(char **argv, char **split_args, int count)
{
	char	**new_argv;
	int		i;

	new_argv = malloc(sizeof(char *) * (count + 2));
	if (!new_argv)
		exit(1);
	i = 0;
	new_argv[0] = argv[0];
	while (i < count)
	{
		new_argv[i + 1] = split_args[i];
		i++;
	}
	new_argv[count + 1] = NULL;
	return (new_argv);
}

int	*parse_and_convert_args(char **argv, int size)
{
	int	*values;
	int	i;

	i = 0;
	values = malloc(sizeof(int) * size);
	if (!values)
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (i < size)
	{
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (values);
}

void	parse_single_argument(int *argc, char ***argv)
{
	char	**split_args;
	int		count;

	if (*argc == 2)
	{
		count = 0;
		split_args = ft_split((*argv)[1], ' ');
		while (split_args[count] != NULL)
			count++;
		*argv = create_new_argv(*argv, split_args, count);
		*argc = count + 1;
		free(split_args);
	}
}
