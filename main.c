/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:27:46 by joltmann          #+#    #+#             */
/*   Updated: 2024/12/17 22:28:52 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	push_swap_execute(argc, argv);
	return (0);
}
