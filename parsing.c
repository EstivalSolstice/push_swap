/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:06:06 by joltmann          #+#    #+#             */
/*   Updated: 2024/12/17 23:47:33 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 1;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

char	**create_new_argv(char **argv, char **split_args, int count)
{
	char	**new_argv;
	int		i;

	new_argv = malloc(sizeof(char *) * (count + 2));
	if (!new_argv)
		exit(1);
	new_argv[0] = argv[0];
	i = 0;
	while (i < count)
	{
		new_argv[i + 1] = ft_strdup(split_args[i]);
		if (!new_argv[i + 1])
		{
			while (i-- > 0)
				free(new_argv[i + 1]);
			free(new_argv);
			exit(1);
		}
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

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	parse_single_argument(int *argc, char ***argv)
{
	char	**split_args;
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
		*argv = create_new_argv(*argv, split_args, count);
		*argc = count + 1;
		free_split(split_args);
		return (1);
	}
	return (0);
}
