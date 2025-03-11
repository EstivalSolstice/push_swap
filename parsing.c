/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:06:06 by joltmann          #+#    #+#             */
/*   Updated: 2025/03/03 10:01:04 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_new_argv(char **argv, char **split_args, int count)
{
	char	**new_argv;
	int		i;
	int		allocated;

	new_argv = malloc(sizeof(char *) * (count + 2));
	if (!new_argv)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	new_argv[0] = ft_strdup(argv[0]);
	if (!new_argv[0])
		free_new_argv_on_error(new_argv, 0);
	allocated = 1;
	i = 0;
	while (i < count)
	{
		new_argv[i + 1] = ft_strdup(split_args[i]);
		if (!new_argv[i + 1])
			free_new_argv_on_error(new_argv, allocated);
		allocated++;
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
		write(2, "Error\n", 6);
		exit(1);
	}
	while (i < size)
	{
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (values);
}

int	parse_single_argument(int *argc, char ***argv)
{
	char	**split_args;
	char	**new_argv;
	int		count;

	if (*argc == 2)
	{
		count = 0;
		split_args = ft_split((*argv)[1], ' ');
		if (!split_args)
			return (write(2, "Error\n", 6), 0);
		while (split_args[count] != NULL)
			count++;
		if (!validate_args(split_args, count))
			return (free_split(split_args), 0);
		new_argv = create_new_argv(*argv, split_args, count);
		free_split(split_args);
		*argv = new_argv;
		*argc = count + 1;
		return (1);
	}
	return (0);
}
