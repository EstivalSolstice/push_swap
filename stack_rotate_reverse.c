/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:53:15 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/30 00:45:22 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push_swap *ps)
{
	reverse_rotate(ps->a);
	if (ps->print_mode)
		ft_printf("rra\n");
	ps->move_count++;
}

void	rrb(t_push_swap *ps)
{
	reverse_rotate(ps->b);
	if (ps->print_mode)
		ft_printf("rrb\n");
	ps->move_count++;
}

void	rrr(t_push_swap *ps)
{
	reverse_rotate(ps->a);
	reverse_rotate(ps->b);
	if (ps->print_mode)
		ft_printf("rrr\n");
	ps->move_count++;
}
