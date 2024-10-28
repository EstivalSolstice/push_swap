/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:53:03 by joltmann          #+#    #+#             */
/*   Updated: 2024/10/28 17:31:57 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *ps)
{
	rotate(ps->a);
	ft_printf("ra\n");
	ps->move_count++;
}

void	rb(t_push_swap *ps)
{
	rotate(ps->b);
	ft_printf("rb\n");
	ps->move_count++;
}

void	rr(t_push_swap *ps)
{
	rotate(ps->a);
	rotate(ps->b);
	ft_printf("rr\n");
	ps->move_count++;
}
