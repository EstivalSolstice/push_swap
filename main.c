/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:41:20 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/28 17:27:14 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	push_swap_execute(argc, argv);
	return (0);
}
