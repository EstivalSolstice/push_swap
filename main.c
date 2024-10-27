/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:41:20 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/27 19:39:20 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"


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